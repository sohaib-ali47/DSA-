#include "task4_tree.h"

int main() {
    tree t;

    t.insert(40);
    t.insert(20);
    t.insert(60);
    t.insert(10);
    t.insert(30);
    t.insert(50);
    t.insert(70);

   

    cout << "Minimum value in BST: " << t.findMin() << endl;
    cout << "Maximum value in BST: " << t.findMax() << endl;

    return 0;
}
