#include <iostream>
#include "derivedclass.h"
using namespace std;

int main() {
    // Creating an object of MyList class with integer type
    MyList<int> list(5, 0);

    // Add some elements to the list
    list.addElementAtFirstIndex(10);
    list.addElementAtLastIndex(20);
    list.addElementAtFirstIndex(5);

    // Display the elements
    cout << "Elements in the list: ";
    list.display();

    // Remove an element from the start
    list.removeElementFromStart();

    // Display after removal
    cout << "After removing an element from the start: ";
    list.display();

    // Remove an element from the end
    list.removeElementFromEnd();

    // Display after removal
    cout << "After removing an element from the end: ";
    list.display();

    return 0;
}






