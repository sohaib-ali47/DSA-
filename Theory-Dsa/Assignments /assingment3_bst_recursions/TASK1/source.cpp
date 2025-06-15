#include "tree.h"

int main() {
    BST tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);

    //  Check if tree is a valid BST
    cout << "Is valid BST: ";
    if (tree.is_valid_bst()) cout << "Yes"<<endl;
    else cout << "No" << endl;

    //  Convert to sorted array
    tree.convert_to_sorted_array();

    // (c) Find distance between nodes
    int distance = tree.find_distance_between_nodes(3, 7);
    cout << "Distance between 3 and 7: " << distance << endl;

    //  Check if balanced
    cout << "Is tree balanced: ";
    if (tree.is_tree_balanced()) cout << "Yes" << endl;
    else cout << "No"<<endl;

    return 0;
}
