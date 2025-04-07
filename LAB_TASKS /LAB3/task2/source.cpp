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








                                                                                                                                                                            .

header file1 >>   (  abstractclass.h  )    :

                                                                                                                                                               

#pragma once
#include <iostream>
using namespace std;

template <typename T>
class List {
protected:
    T* arr;
    int currentindex;
    int maxsize;

public:
    // Constructor with default arguments
    List(int max = 10, int current = 0) : maxsize(max), currentindex(current) {
        arr = new T[maxsize];
    }

    // Destructor
    virtual ~List() {
        delete[] arr;
    }

    // Pure virtual functions (must be implemented by derived classes)
    virtual void addElementAtFirstIndex(T value) = 0;
    virtual void addElementAtLastIndex(T value) = 0;
    virtual T removeElementFromEnd() = 0;
    virtual void removeElementFromStart() = 0;
    virtual void display() = 0;
};


