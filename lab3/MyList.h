#ifndef MYLIST_H
#define MYLIST_H

#include "List.h"
#include <iostream>
using namespace std;

template <class Type>
class MyList : public List<Type>
{
public:
    MyList(int size = 10) : List<Type>(size) {}

    MyList(const MyList<Type>& other) : List<Type>(other) {}

    void addElementAtFirstIndex(Type value)
    {
        if (this->currentSize == this->maxSize)
            return;

        for (int i = this->currentSize; i > 0; i--)
            this->arr[i] = this->arr[i - 1];

        this->arr[0] = value;
        this->currentSize++;
    }

    void addElementAtLastIndex(Type value)
    {
        if (this->currentSize == this->maxSize)
            return;

        this->arr[this->currentSize] = value;
        this->currentSize++;
    }

    Type removeElementFromEnd()
    {
        if (this->currentSize == 0)
            return Type();

        Type value = this->arr[this->currentSize - 1];
        this->currentSize--;
        return value;
    }

    void removeElementFromStart()
    {
        if (this->currentSize == 0)
            return;

        for (int i = 0; i < this->currentSize - 1; i++)
            this->arr[i] = this->arr[i + 1];

        this->currentSize--;
    }

    bool empty()
    {
        return this->currentSize == 0;
    }

    bool full()
    {
        return this->currentSize == this->maxSize;
    }

    int size()
    {
        return this->currentSize;
    }

    bool insertAt(int index, Type value)
    {
        if (index < 0 || index > this->currentSize || full())
            return false;

        for (int i = this->currentSize; i > index; i--)
            this->arr[i] = this->arr[i - 1];

        this->arr[index] = value;
        this->currentSize++;
        return true;
    }

    Type last()
    {
        if (empty())
            return Type();

        return this->arr[this->currentSize - 1];
    }

    bool search(Type value)
    {
        for (int i = 0; i < this->currentSize; i++)
        {
            if (this->arr[i] == value)
                return true;
        }
        return false;
    }

    void display()
    {
        if (empty())
        {
            cout << "List is empty." << endl;
            return;
        }

        for (int i = 0; i < this->currentSize; i++)
            cout << this->arr[i] << " ";

        cout << endl;
    }
};

#endif
