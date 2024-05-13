#include <iostream>
#include <string>
#include <cstdlib>
#include "data.h"

using namespace std;

int intValidation(string prompt);

int main() {
    LinkedList list;
    int choice, position, data;

    do {
        cout << "\nLIST OPERATIONS:\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert at position\n";
        cout << "4. Remove at position\n";
        cout << "5. Search\n";
        cout << "6. Display list\n";
        cout << "7. Get size\n";
        cout << "8. Check if list is empty\n";
        cout << "9. Check if list is full\n";
        cout << "0. Exit\n";

        string prompt = "Enter your choice: ";
        choice = intValidation(prompt);

        switch (choice) {
        case 1:
            {
            prompt = "Enter data to be inserted at beginning: ";
            data = intValidation(prompt);
            list.insertAtBeginning(data);
            cout << "\x1b[32m \nData input succesful! \x1b[0m" << endl;
            system("PAUSE");
            system("CLS");
            break;
            }

        case 2:
            {
            prompt = "Enter data to be inserted at end: ";
            data = intValidation(prompt);
            list.insert(data);
            cout << "\x1b[32m \nData input succesful! \x1b[0m" << endl;
            system("PAUSE");
            system("CLS");
            break;
            }

        case 3:
            {
            prompt = "Enter data to be inserted: ";
            data = intValidation(prompt);
            prompt = "Enter position to insert data: ";
            position = intValidation(prompt);
            list.insertAfter(data, position);
            cout << "\x1b[32m \nData input succesful at position" << "position!\x1b[0m" << endl;
            system("PAUSE");
            system("CLS");
            break;
            }

        case 4:
            {
            prompt = "Enter position of data to be removed: ";
            position = intValidation(prompt);
            list.removeAt(position);
            cout << "\x1b[32m \nData Removed!\x1b[0m" << endl;
            system("PAUSE");
            system("CLS");
            break;
            }

        case 5:
            {
            prompt = "Enter data to search: ";
            data = intValidation(prompt);
            if (list.search(data))
                cout << "Element found in the list\n";
            else
                cout << "Element not found in the list\n";
            system("PAUSE");
            system("CLS");
            break;
            }

        case 6:
            {
            cout << "Elements in the list are: ";
            list.printList();
            system("PAUSE");
            system("CLS");
            break;
            }

        case 7:
            {
            cout << "Size of the list is: " << list.getSize() << endl;
            system("PAUSE");
            system("CLS");
            break;
            }

        case 8:
            {
            if (list.isEmpty())
                cout << "List is empty\n";
            else
                cout << "List is not empty\n";
            system("PAUSE");
            system("CLS");
            break;
            }

        case 9:
            {
            if (!list.isFull())
                cout << "List is full\n";
            else
                cout << "List is not full\n";
            system("PAUSE");
            system("CLS");
            break;
            }

        case 0:
            {
            cout << "Exiting...\n";
            break;
            }
        default:
            {
            cout << "Invalid choice, please try again\n";
            break;
            }
        }

    } while (choice != 0);

    return 0;
}

int intValidation(string prompt) {
    int choice;
    string s_choice;

    do {
        cout << prompt;
        getline(cin, s_choice);

        if (!isdigit(s_choice[0])) {
            cout << "\x1b[31m\nInvalid input! Please enter a single digit.\x1b[0m\n";
            cin.clear();
        }
        else {
            choice = stoi(s_choice);  // Convert char to int
        }
    } while (!isdigit(s_choice[0]));

    return choice;
}
