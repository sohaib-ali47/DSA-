#include <iostream>
#include "my_stack.h"
using namespace std;

int main() {
    int size;
    cout << "Enter the size of the stack: ";
    cin >> size;

    myStack<int> stack(size);

    int choice;
    int value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Top\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            stack.push(value);
            break;

        case 2:
            cout << "Popped value: " << stack.pop() << endl;
            break;

        case 3:
            cout << "Top of stack: " << stack.top() << endl;
            break;

        case 4:
            stack.display();
            break;

        case 5:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
