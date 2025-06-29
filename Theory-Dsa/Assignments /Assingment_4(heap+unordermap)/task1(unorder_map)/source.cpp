#include "Unordered_map.h"

int main() {
    UnorderedMap map;
    int choice, key, value;
    bool running = true;

    cout << endl;
    cout << "    ********** MENU **********" << endl;
    cout << "    1. Insert a Key-Value Pair" << endl;
    cout << "    2. Retrieve Value by Key" << endl;
    cout << "    3. Remove a Key" << endl;
    cout << "    4. Show All Stored Pairs" << endl;
    cout << "    5. Exit Program" << endl;

    while (running) {
        cout << endl << "    Your choice (1-5): ";
        cin >> choice;
        cout << endl;

        if (choice == 1) {
            cout << "    Enter key: ";
            cin >> key;
            cout << "    Enter value: ";
            cin >> value;
            map.insert(key, value);
            cout << "    Pair inserted or updated." << endl;
        }
        else if (choice == 2) {
            cout << "    Enter key to look up: ";
            cin >> key;
            value = map.get(key);
            if (value == -1)
                cout << "    Key not found." << endl;
            else
                cout << "    Value = " << value << endl;
        }
        else if (choice == 3) {
            cout << "    Enter key to remove: ";
            cin >> key;
            map.remove(key);
            cout << "    If it existed, it has been removed." << endl;
        }
        else if (choice == 4) {
            map.show();
        }
        else if (choice == 5) {
            cout << "    Exiting program. Thank you." << endl;
            running = false;
        }
        else {
            cout << "    Invalid choice. Please enter a number from 1 to 5." << endl;
        }
    }

    return 0;
}
