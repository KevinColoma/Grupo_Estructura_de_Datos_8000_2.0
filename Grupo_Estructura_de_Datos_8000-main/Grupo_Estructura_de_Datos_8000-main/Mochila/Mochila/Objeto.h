#pragma once
#include <iostream>
#include <cstring>

using namespace std;


class Object
{
public:
    int weight;
    int value;
    Object* next;
};

class Backpack
{
private:
    Object* head;
    int f[1005];
    int n, m;

public:
    Backpack()
    {
        head = NULL;
        memset(f, 0, sizeof f);
    }

    void addObject(int weight, int value)
    {
        Object* temp = new Object();
        temp->weight = weight;
        temp->value = value;
        temp->next = head;
        head = temp;
        n++;
    }

    void solve()
    {
        Object* current = head;
        for (int i = 1; i <= n; i++)
        {
            for (int j = m; j >= current->weight; j--)
                f[j] = max(f[j], f[j - current->weight] + current->value);
            current = current->next;
        }
    }

    int getResult()
    {
        return f[m];
    }

    void setCapacity(int capacity)
    {
        m = capacity;
    }

    void clear()
    {
        Object* current = head;
        while (head != NULL)
        {
            current = head;
            head = head->next;
            delete current;
        }
        n = 0;
        memset(f, 0, sizeof f);
    }
};