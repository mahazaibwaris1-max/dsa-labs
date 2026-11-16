#ifndef MYCARSTACK_H
#define MYCARSTACK_H

#include <iostream>
#include <string>
using namespace std;

class myCarStack
{
private:
    string cars[8];
    int currentSize;

public:
    myCarStack()
    {
        currentSize = 0;
    }

    bool isEmpty() const
    {
        return currentSize == 0;
    }

    bool isFull() const
    {
        return currentSize == 8;
    }

    int size() const
    {
        return currentSize;
    }

    bool push(string carNumber)
    {
        if (isFull())
            return false;

        cars[currentSize] = carNumber;
        currentSize++;
        return true;
    }

    string pop()
    {
        if (isEmpty())
            return "";

        currentSize--;
        return cars[currentSize];
    }

    string top() const
    {
        if (isEmpty())
            return "";

        return cars[currentSize - 1];
    }

    bool search(string carNumber) const
    {
        for (int i = 0; i < currentSize; i++)
        {
            if (cars[i] == carNumber)
                return true;
        }
        return false;
    }

    bool removeCar(string carNumber)
    {
        if (!search(carNumber))
            return false;

        myCarStack temp;

        while (!isEmpty() && top() != carNumber)
            temp.push(pop());

        if (!isEmpty())
            pop();

        while (!temp.isEmpty())
            push(temp.pop());

        return true;
    }

    void display() const
    {
        if (isEmpty())
        {
            cout << "No cars are parked." << endl;
            return;
        }

        cout << "Cars from top to bottom:" << endl;
        for (int i = currentSize - 1; i >= 0; i--)
            cout << cars[i] << endl;
    }
};

#endif
