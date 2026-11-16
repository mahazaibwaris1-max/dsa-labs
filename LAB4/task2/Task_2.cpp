#include <iostream>
#include "myStack.h"
using namespace std;

int main()
{
    int size;
    cout << "Enter stack size: ";
    cin >> size;

    if (size <= 0)
        size = 10;

    myStack<int> s(size);
    int choice;
    int value;

    do
    {
        cout << "\n1. Push element";
        cout << "\n2. Pop element";
        cout << "\n3. Show top element";
        cout << "\n4. Check if stack is empty";
        cout << "\n5. Check if stack is full";
        cout << "\n6. Display stack";
        cout << "\n7. Show minimum element";
        cout << "\n8. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            s.push(value);
            break;

        case 2:
            if (!s.isEmpty())
                cout << "Removed: " << s.pop() << endl;
            else
                cout << "Stack is empty." << endl;
            break;

        case 3:
            if (!s.isEmpty())
                cout << "Top element: " << s.top() << endl;
            else
                cout << "Stack is empty." << endl;
            break;

        case 4:
            cout << (s.isEmpty() ? "Stack is empty." : "Stack is not empty.") << endl;
            break;

        case 5:
            cout << (s.isFull() ? "Stack is full." : "Stack is not full.") << endl;
            break;

        case 6:
            s.display();
            break;

        case 7:
            if (!s.isEmpty())
                cout << "Minimum element: " << s.getMin() << endl;
            else
                cout << "Stack is empty." << endl;
            break;

        case 8:
            cout << "Program ended." << endl;
            break;

        default:
            cout << "Invalid choice." << endl;
        }
    } while (choice != 8);

    return 0;
}
