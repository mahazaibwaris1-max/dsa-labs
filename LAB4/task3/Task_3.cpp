#include <iostream>
#include <string>
#include "myCarStack.h"
using namespace std;

int main()
{
    myCarStack parking;
    int choice;
    string carNumber;

    do
    {
        cout << "\n1. Park a car";
        cout << "\n2. Remove a car";
        cout << "\n3. View parked cars";
        cout << "\n4. Total cars parked";
        cout << "\n5. Search for a car";
        cout << "\n0. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter car number: ";
            cin >> carNumber;
            if (parking.push(carNumber))
                cout << "Car parked successfully." << endl;
            else
                cout << "Parking lot is full." << endl;
            break;

        case 2:
            cout << "Enter car number to remove: ";
            cin >> carNumber;
            if (parking.removeCar(carNumber))
                cout << "Car removed successfully." << endl;
            else
                cout << "Car not found." << endl;
            break;

        case 3:
            parking.display();
            break;

        case 4:
            cout << "Total cars parked: " << parking.size() << endl;
            break;

        case 5:
            cout << "Enter car number to search: ";
            cin >> carNumber;
            if (parking.search(carNumber))
                cout << "Car is present in parking lot." << endl;
            else
                cout << "Car is not present." << endl;
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
