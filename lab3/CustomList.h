#ifndef CUSTOMLIST_H
#define CUSTOMLIST_H

#include "MyList.h"

template <class Type>
class CustomList : public MyList<Type>
{
private:
    bool isPrime(Type number)
    {
        if (number < 2)
            return false;

        for (int i = 2; i * i <= number; i++)
        {
            if (number % i == 0)
                return false;
        }
        return true;
    }

public:
    CustomList(int size = 10) : MyList<Type>(size) {}

    CustomList(const CustomList<Type>& other) : MyList<Type>(other) {}

    Type sum_ofPrime()
    {
        Type sum = 0;

        for (int i = 0; i < this->currentSize; i++)
        {
            if (isPrime(this->arr[i]))
                sum += this->arr[i];
        }

        return sum;
    }

    Type secondMaxEven()
    {
        Type largest = Type();
        Type second = Type();
        bool foundLargest = false;
        bool foundSecond = false;

        for (int i = 0; i < this->currentSize; i++)
        {
            Type value = this->arr[i];

            if (value % 2 == 0)
            {
                if (!foundLargest || value > largest)
                {
                    if (foundLargest && value != largest)
                    {
                        second = largest;
                        foundSecond = true;
                    }
                    largest = value;
                    foundLargest = true;
                }
                else if (value != largest && (!foundSecond || value > second))
                {
                    second = value;
                    foundSecond = true;
                }
            }
        }

        if (foundSecond)
            return second;

        return Type();
    }

    Type secondMinOdd()
    {
        Type smallest = Type();
        Type second = Type();
        bool foundSmallest = false;
        bool foundSecond = false;

        for (int i = 0; i < this->currentSize; i++)
        {
            Type value = this->arr[i];

            if (value % 2 != 0)
            {
                if (!foundSmallest || value < smallest)
                {
                    if (foundSmallest && value != smallest)
                    {
                        second = smallest;
                        foundSecond = true;
                    }
                    smallest = value;
                    foundSmallest = true;
                }
                else if (value != smallest && (!foundSecond || value < second))
                {
                    second = value;
                    foundSecond = true;
                }
            }
        }

        if (foundSecond)
            return second;

        return Type();
    }

    void printDuplicates()
    {
        bool duplicateFound = false;

        for (int i = 0; i < this->currentSize; i++)
        {
            bool alreadyPrinted = false;

            for (int k = 0; k < i; k++)
            {
                if (this->arr[k] == this->arr[i])
                    alreadyPrinted = true;
            }

            if (!alreadyPrinted)
            {
                int count = 0;
                for (int j = 0; j < this->currentSize; j++)
                {
                    if (this->arr[j] == this->arr[i])
                        count++;
                }

                if (count > 1)
                {
                    cout << this->arr[i] << " ";
                    duplicateFound = true;
                }
            }
        }

        if (!duplicateFound)
            cout << "No duplicates";

        cout << endl;
    }

    void rotateClockwaise(int r)
    {
        int half = this->currentSize / 2;
        if (half == 0)
            return;

        r = r % half;

        for (int part = 0; part < 2; part++)
        {
            int start = (part == 0) ? 0 : half;
            int end = (part == 0) ? half - 1 : this->currentSize - 1;
            int length = end - start + 1;
            int times = r % length;

            for (int t = 0; t < times; t++)
            {
                Type lastValue = this->arr[end];
                for (int i = end; i > start; i--)
                    this->arr[i] = this->arr[i - 1];
                this->arr[start] = lastValue;
            }
        }
    }

    void rotateanitclockwaise(int rt)
    {
        int half = this->currentSize / 2;
        if (half == 0)
            return;

        for (int part = 0; part < 2; part++)
        {
            int start = (part == 0) ? 0 : half;
            int end = (part == 0) ? half - 1 : this->currentSize - 1;
            int length = end - start + 1;
            int times = rt % length;

            for (int t = 0; t < times; t++)
            {
                Type firstValue = this->arr[start];
                for (int i = start; i < end; i++)
                    this->arr[i] = this->arr[i + 1];
                this->arr[end] = firstValue;
            }
        }
    }
};

#endif
