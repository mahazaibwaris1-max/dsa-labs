#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    string text = "";
    stack<string> undoStack;
    stack<string> redoStack;
    int choice;
    char character;

    do
    {
        cout << "\nCurrent Text: " << text;
        cout << "\n\n1. Type a character";
        cout << "\n2. Delete last character";
        cout << "\n3. Undo";
        cout << "\n4. Redo";
        cout << "\n5. Show text";
        cout << "\n0. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter character: ";
            cin >> character;
            undoStack.push(text);
            while (!redoStack.empty())
                redoStack.pop();
            text += character;
            break;

        case 2:
            if (text.empty())
            {
                cout << "There is no text to delete." << endl;
            }
            else
            {
                undoStack.push(text);
                while (!redoStack.empty())
                    redoStack.pop();
                text.erase(text.length() - 1, 1);
            }
            break;

        case 3:
            if (undoStack.empty())
            {
                cout << "Nothing to undo." << endl;
            }
            else
            {
                redoStack.push(text);
                text = undoStack.top();
                undoStack.pop();
            }
            break;

        case 4:
            if (redoStack.empty())
            {
                cout << "Nothing to redo." << endl;
            }
            else
            {
                undoStack.push(text);
                text = redoStack.top();
                redoStack.pop();
            }
            break;

        case 5:
            cout << "Current Text: " << text << endl;
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
