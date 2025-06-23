#include "task5_tree.h"

int main() {
    tree t;

    // Sample insertion
    t.insert(50);
    t.insert(30);
    t.insert(70);
    t.insert(20);
    t.insert(40);
    t.insert(60);
    t.insert(80);

    cout << "Original tree: ";
    t.in_trav();

    // Ask user for value to delete
    int val;
    cout << "Enter value to delete: ";
    cin >> val;

    t.remove(val);

    cout << "Updated tree after deletion: ";
    t.in_trav();

    return 0;
}
