#pragma once
#pragma once

template <class Tkey, class TValue>
class HashElement
{
public:
    HashElement() = default;
    HashElement(Tkey key, TValue value);

    ~HashElement();
    void set_key(Tkey key);
    void set_value(TValue value);
    TValue get_value() const;
    Tkey get_key() const;
    HashElement<Tkey, TValue>* get_next() const;
    void set_next(HashElement<Tkey, TValue>* next);
    bool operator==(HashElement<Tkey, TValue>& other) const;


private:
    Tkey key;
    TValue value;
    HashElement* next{ nullptr };
};

template <class Tkey, class TValue>
HashElement<Tkey, TValue>::HashElement(Tkey key, TValue value)
    : key(key), value(value)
{
}

template <class Tkey, class TValue>
HashElement<Tkey, TValue>::~HashElement()
{

    // destructor
}

template <class Tkey, class TValue>
void HashElement<Tkey, TValue>::set_key(Tkey key)
{
    this->key = key;
}

template <class Tkey, class TValue>
void HashElement<Tkey, TValue>::set_value(TValue value)
{
    this->value = value;
}

template <class Tkey, class TValue>
TValue HashElement<Tkey, TValue>::get_value() const
{
    return this->value;
}
template <class Tkey, class TValue>
Tkey HashElement<Tkey, TValue>::get_key() const
{
    return this->key;
}

template <class Tkey, class TValue>
HashElement<Tkey, TValue>* HashElement<Tkey, TValue>::get_next() const
{
    return this->next;
}

template <class Tkey, class TValue>
void HashElement<Tkey, TValue>::set_next(HashElement<Tkey, TValue>* next)
{
    this->next = next;
}

template <class Tkey, class TValue>
bool HashElement<Tkey, TValue>::operator==(HashElement<Tkey, TValue>& other) const
{
    return this->key == other.key;
}