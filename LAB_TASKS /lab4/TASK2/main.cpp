#include <iostream>
#include "my_stack.h"
using namespace std;

int main() {
    int size;
    cout << "Enter size of the stack: ";
    cin >> size;

    myStack<int> stack(size);

    int choice;
    int value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Push element\n";
        cout << "2. Pop element\n";
        cout << "3. Show top element\n";
        cout << "4. Check if stack is empty\n";
        cout << "5. Check if stack is full\n";
        cout << "6. Display stack elements\n";
        cout << "7. Show minimum element\n";
        cout << "8. Exit\n";
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
            cout << (stack.isEmpty() ? "Stack is empty" : "Stack is not empty") << endl;
            break;
        case 5:
            cout << (stack.isFull() ? "Stack is full" : "Stack is not full") << endl;
            break;
        case 6:
            stack.display();
            break;
        case 7:
            cout << "Minimum value in stack: " << stack.getMin() << endl;
            break;
        case 8:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Wrong choice bro, try again!" << endl;
        }

    } while (choice != 8);

    return 0;
}
