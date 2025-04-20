#include "TextEditor.h"
#include <iostream>
#include <string>  // <-- this fixes the getline issue
using namespace std;

int main() {
    TextEditor editor;
    int choice;
    string input;

    while (true) {
        editor.showText();
        cout << "1. Type text\n";
        cout << "2. Delete last character\n";
        cout << "3. Undo\n";
        cout << "4. Redo\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter text to add: ";
            cin.ignore();
            getline(cin, input);
            editor.typeText(input);
        }
        else if (choice == 2) {
            editor.deleteChar();
        }
        else if (choice == 3) {
            editor.undo();
        }
        else if (choice == 4) {
            editor.redo();
        }
        else if (choice == 5) {
            break;
        }
        else {
            cout << "Invalid choice." << endl;
        }
    }

    return 0;
}
