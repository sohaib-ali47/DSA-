#include <iostream>
#include "Linked_list.h"
using namespace std;

int main() {
    CircularLinkedList<int> obj1;
    int choice = 0;

    while (choice != 99) {
        cout << "Press 1 to start the game" << endl;
        cout << "Press 99 to exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int start, skip;
            cout << "Enter starting person number: ";
            cin >> start;
            cout << "Enter number of persons to skip: ";
            cin >> skip;

            obj1.clearList();
            obj1.createList();

            int survivor = obj1.solveJosephus(start, skip + 1);
            cout << "The winner  is: " << survivor << endl;
        }
    }

    return 0;
}
