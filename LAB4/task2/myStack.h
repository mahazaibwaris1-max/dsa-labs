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
    T* minArr;
    int maxSize;
    int currentSize;
    int minSize;

public:
    myStack(int size = 10)
    {
        maxSize = size;
        currentSize = 0;
        minSize = 0;
        arr = new T[maxSize];
        minArr = new T[maxSize];
    }

    myStack(const myStack<T>& other)
    {
        maxSize = other.maxSize;
        currentSize = other.currentSize;
        minSize = other.minSize;
        arr = new T[maxSize];
        minArr = new T[maxSize];

        for (int i = 0; i < currentSize; i++)
            arr[i] = other.arr[i];

        for (int i = 0; i < minSize; i++)
            minArr[i] = other.minArr[i];
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

        if (minSize == 0 || value <= minArr[minSize - 1])
        {
            minArr[minSize] = value;
            minSize++;
        }
    }

    T pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty." << endl;
            return T();
        }

        T value = arr[currentSize - 1];
        currentSize--;

        if (minSize > 0 && value == minArr[minSize - 1])
            minSize--;

        return value;
    }

    T top() const
    {
        if (isEmpty())
            return T();

        return arr[currentSize - 1];
    }

    T getMin() const
    {
        if (isEmpty())
            return T();

        return minArr[minSize - 1];
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
        delete[] minArr;
    }
};

#endif
