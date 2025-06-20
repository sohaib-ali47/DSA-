#include "task3_tree.h"

int main() {
    tree t;

    t.insert(50);
    t.insert(30);
    t.insert(70);
    t.insert(20);
    t.insert(40);
    t.insert(60);
    t.insert(80);

    t.in_trav();

    int val;
    cout << "Enter value to search: ";
    cin >> val;

    if (t.search(val)) {
        cout << "Value " << val << " found in the BST." << endl;
    }
    else {
        cout << "Value " << val << " not found in the BST." << endl;
    }

    return 0;
}
