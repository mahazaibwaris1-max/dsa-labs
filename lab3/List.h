#ifndef LIST_H
#define LIST_H

template <class Type>
class List
{
protected:
    Type* arr;
    int maxSize;
    int currentSize;

public:
    List(int size = 10)
    {
        maxSize = size;
        currentSize = 0;
        arr = new Type[maxSize];
    }

    List(const List<Type>& other)
    {
        maxSize = other.maxSize;
        currentSize = other.currentSize;
        arr = new Type[maxSize];

        for (int i = 0; i < currentSize; i++)
            arr[i] = other.arr[i];
    }

    virtual void addElementAtFirstIndex(Type value) = 0;
    virtual void addElementAtLastIndex(Type value) = 0;
    virtual Type removeElementFromEnd() = 0;
    virtual void removeElementFromStart() = 0;

    virtual ~List()
    {
        delete[] arr;
    }
};

#endif
