#include <iostream>
#include "CustomList.h"
using namespace std;

int main()
{
    int capacity;
    cout << "Enter list capacity: ";
    cin >> capacity;

    if (capacity <= 0)
        capacity = 10;

    CustomList<int> list(capacity);
    int choice;
    int value;
    int index;
    int rotations;

    do
    {
        cout << "\n1. Add at first";
        cout << "\n2. Add at last";
        cout << "\n3. Remove from end";
        cout << "\n4. Remove from start";
        cout << "\n5. Insert at index";
        cout << "\n6. Search";
        cout << "\n7. Display";
        cout << "\n8. Check empty";
        cout << "\n9. Check full";
        cout << "\n10. Show size";
        cout << "\n11. Show last element";
        cout << "\n12. Sum of prime numbers";
        cout << "\n13. Second maximum even";
        cout << "\n14. Second minimum odd";
        cout << "\n15. Print duplicates";
        cout << "\n16. Rotate clockwise";
        cout << "\n17. Rotate anti-clockwise";
        cout << "\n0. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            list.addElementAtFirstIndex(value);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            list.addElementAtLastIndex(value);
            break;

        case 3:
            if (list.empty())
                cout << "List is empty." << endl;
            else
                cout << "Removed: " << list.removeElementFromEnd() << endl;
            break;

        case 4:
            list.removeElementFromStart();
            break;

        case 5:
            cout << "Enter index and value: ";
            cin >> index >> value;
            if (list.insertAt(index, value))
                cout << "Value inserted." << endl;
            else
                cout << "Invalid index or list is full." << endl;
            break;

        case 6:
            cout << "Enter value to search: ";
            cin >> value;
            if (list.search(value))
                cout << "Value found." << endl;
            else
                cout << "Value not found." << endl;
            break;

        case 7:
            list.display();
            break;

        case 8:
            cout << (list.empty() ? "List is empty." : "List is not empty.") << endl;
            break;

        case 9:
            cout << (list.full() ? "List is full." : "List is not full.") << endl;
            break;

        case 10:
            cout << "Current size: " << list.size() << endl;
            break;

        case 11:
            if (list.empty())
                cout << "List is empty." << endl;
            else
                cout << "Last element: " << list.last() << endl;
            break;

        case 12:
            cout << "Sum of prime numbers: " << list.sum_ofPrime() << endl;
            break;

        case 13:
            cout << "Second maximum even number: " << list.secondMaxEven() << endl;
            break;

        case 14:
            cout << "Second minimum odd number: " << list.secondMinOdd() << endl;
            break;

        case 15:
            list.printDuplicates();
            break;

        case 16:
            cout << "Enter number of rotations: ";
            cin >> rotations;
            list.rotateClockwaise(rotations);
            list.display();
            break;

        case 17:
            cout << "Enter number of rotations: ";
            cin >> rotations;
            list.rotateanitclockwaise(rotations);
            list.display();
            break;

        case 0:
            cout << "Program ended." << endl;
            break;

        default:
            cout << "Invalid choice." << endl;
        }

    } while (choice != 0);

    return 0;
}
