#ifndef MYSTACK_H
#define MYSTACK_H

#include "AbstractStack.h"
#include <iostream>
using namespace std;

template <class T>
class myStack : public AbstractStack<T>
{
private:
    T* arr;
    int maxSize;
    int currentSize;

public:
    myStack(int size = 10)
    {
        maxSize = size;
        currentSize = 0;
        arr = new T[maxSize];
    }

    myStack(const myStack<T>& other)
    {
        maxSize = other.maxSize;
        currentSize = other.currentSize;
        arr = new T[maxSize];

        for (int i = 0; i < currentSize; i++)
            arr[i] = other.arr[i];
    }

    void push(T value)
    {
        if (isFull())
        {
            cout << "Stack is full." << endl;
            return;
        }

        arr[currentSize] = value;
        currentSize++;
    }

    T pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty." << endl;
            return T();
        }

        currentSize--;
        return arr[currentSize];
    }

    T top() const
    {
        if (isEmpty())
            return T();

        return arr[currentSize - 1];
    }

    bool isEmpty() const
    {
        return currentSize == 0;
    }

    bool isFull() const
    {
        return currentSize == maxSize;
    }

    void display() const
    {
        if (isEmpty())
        {
            cout << "Stack is empty." << endl;
            return;
        }

        for (int i = currentSize - 1; i >= 0; i--)
            cout << arr[i] << endl;
    }

    ~myStack()
    {
        delete[] arr;
    }
};

#endif
