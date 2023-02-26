#pragma once
#include <string>
#include <cstdlib>
#include <iomanip>
#include <regex>
#include "hash_element.hpp"
#include <functional>

template <typename Tkey, typename TValue>
class HashElement;

template <typename Tkey, typename TValue>
class HashTable
{
public:
    HashTable(unsigned int size = 5018);
    void insert(Tkey key, TValue value);
    TValue find(Tkey key);
    void erase(Tkey key);
    void clear();
    inline bool has(Tkey key);
    int size() { return _size; };
    /////////////////////////////////////////////
    unsigned int hash(std::string key);
    unsigned int hash(unsigned int key);
    unsigned string_to_int(Tkey key);
    bool collision(Tkey key);
    void for_each(std::function<void(Tkey, TValue)> callback);
    bool is_empty();
    int prime_number(int size);

private:
    unsigned int _size{ 0 };
    HashElement<Tkey, TValue>** _table{ nullptr };
};

template <typename Tkey, typename TValue>
HashTable<Tkey, TValue>::HashTable(unsigned int size)
    : _size(prime_number(size))
{
    _table = new HashElement<Tkey, TValue> *[_size];
    for (unsigned int i = 0; i < _size; ++i)
    {
        *(_table + i) = nullptr;
    }
}

template <typename Tkey, typename TValue>
void HashTable<Tkey, TValue>::insert(Tkey key, TValue value)
{
    unsigned int index = hash(key);

    HashElement<Tkey, TValue>* p = *(_table + index);
    while ((p != nullptr) && p->get_key() == key)
    {
        index = hash(index + 1);
        p = *(_table + index);
    }
    HashElement<Tkey, TValue>* new_element = new HashElement<Tkey, TValue>(key, value);

    if (p == nullptr)
    {
        *(_table + index) = new_element;
    }
    else
    {
        new_element->set_next(p);
        *(_table + index) = new_element;
    }
}

template <typename Tkey, typename TValue>
TValue HashTable<Tkey, TValue>::find(Tkey key)
{
    unsigned int index = hash(key);
    HashElement<Tkey, TValue>* p = *(_table + index);
    return p->get_value();
}

template <typename Tkey, typename TValue>
void HashTable<Tkey, TValue>::erase(Tkey key)
{
    unsigned int index = hash(key);
    HashElement<Tkey, TValue>* p = *(_table + index);
    while ((p != nullptr) && p->get_key() == index)
    {
        if (p->get_key() == index)
        {
            HashElement<Tkey, TValue>* q = p;
            p = p->get_next();
            delete q;
            *(_table + index) = p;
        }
    }
}

template <typename Tkey, typename TValue>
void HashTable<Tkey, TValue>::clear()
{
    for (size_t i = 0; i < _size; ++i)
    {
        HashElement<Tkey, TValue>* p = *(_table + i);
        while (p != nullptr)
        {
            HashElement<Tkey, TValue>* q = p;
            p = p->get_next();
            delete q;
        }
    }
    for (size_t i = 0; i < _size; ++i)
    {
        *(_table + i) = nullptr;
    }
}

template <typename Tkey, typename TValue>
inline bool HashTable<Tkey, TValue>::has(Tkey key)
{
    bool is_found = false;
    for_each([&](Tkey k, TValue v)
        {
            if (k == key)
            {
                is_found = true;
                return false;
            }
    return true;
        });
    return is_found;
}

/****************FUNCIONES HASH*****************/
//////////////////////////////////////////////////////////////////////
template <typename Tkey, typename TValue>
unsigned int HashTable<Tkey, TValue>::hash(std::string key)
{

    //hash function generic for strings
    std::string str = key;
    std::string::iterator it = str.begin();
    std::string::iterator it_end = str.end();
    unsigned int hash = 0;
    for (; it != it_end; ++it)
    {
        hash += *it;
    }
    return hash % _size;
}

template <typename Tkey, typename TValue>
unsigned int HashTable<Tkey, TValue>::hash(unsigned int key)
{
    //hash function generic for ints
    return key % _size;
}

template <typename Tkey, typename TValue>
unsigned int HashTable<Tkey, TValue>::string_to_int(Tkey key)
{
    int num = 0;
    for (size_t i = 0; i < key.size(); ++i)
    {
        num *= 27 + static_cast<int>(key[i]);
    }
    if (num < 0)
    {
        num = -num;
    }
    return num;
}

template <typename Tkey, typename TValue>
bool HashTable<Tkey, TValue>::collision(Tkey _key)
{
    //return true if there is a collision
    bool collision = false;
    for_each([&](Tkey key, TValue value)
        {
            if (key == _key)
            {
                collision = true;
            }
        });
    return collision;
}

template <typename Tkey, typename TValue>
void HashTable<Tkey, TValue>::for_each(std::function<void(Tkey, TValue)> callback)
{
    if (is_empty())
    {
        return;
    }

    for (size_t i = 0; i < _size; ++i)
    {
        HashElement<Tkey, TValue>* p = *(_table + i);
        while (p != nullptr)
        {
            callback(p->get_key(), p->get_value());
            p = p->get_next();
        }
    }
}

template <typename Tkey, typename TValue>
bool HashTable<Tkey, TValue>::is_empty()
{
    for (size_t i = 0; i < _size; ++i)
    {
        if (*(_table + i) != nullptr)
        {
            return false;
        }
    }
    return true;
}

template <typename Tkey, typename TValue>
int HashTable<Tkey, TValue>::prime_number(int size)
{
    //check prime number for size
    int count = 0;
    for (int i = 2; i <= (size / 2); ++i)
    {
        if (size % i == 0)
        {
            count++;
            break;
        }
    }
    if (count == 0)
    {
        return size;
    }
    else
    {
        return prime_number(size + 1);
    }
}