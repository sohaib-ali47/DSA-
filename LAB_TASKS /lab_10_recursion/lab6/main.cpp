#include "lab_10_d_lisked.h"

int main() {
    doubly_linked_list<int> list;

    // Insertion tests
    list.insert_at_head(30);
    list.insert_at_head(20);
    cout << "After inserting at head: ";
    list.print_forward();

    list.insert_at_tail(50);
    cout << "After inserting at tail: ";
    list.print_forward();

    list.insert_at_position(3, 25);
    cout << "After inserting 25 at position 3: ";
    list.print_forward();

    // Deletion tests
    list.delete_by_value(25);
    cout << "After deleting value 25: ";
    list.print_forward();

    list.delete_at_position(1);
    cout << "After deleting at position 1: ";
    list.print_forward();

    // Search test
    int pos = list.search(40);
    if (pos != -1)
        cout << "Value 40 found at position: " << pos << endl;
    else
        cout << "Value 40 not found." << endl;

    // Print reverse
    cout << "List in reverse: ";
    list.print_reverse();

    // Palindrome test
    doubly_linked_list<int> palinList;
    palinList.insert_at_tail(1);
    palinList.insert_at_tail(2);
    palinList.insert_at_tail(3);
    palinList.insert_at_tail(2);
    palinList.insert_at_tail(1);
    cout << "Palindrome List: ";
    palinList.print_forward();

    if (palinList.is_palindrome())
        cout << "The list is a palindrome." << endl;
    else
        cout << "The list is not a palindrome." << endl;

    return 0;
}
