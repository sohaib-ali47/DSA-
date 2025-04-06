#pragma once

using namespace std;
#include <iostream>

template <typename type>
class List {
protected:
    type* arr;
    int currentindex;
    int maxsize;

public:
    // parameterized constructor 
    List(int max, int current) : maxsize(max), currentindex(current) {
        arr = new type[maxsize];
    }

    virtual ~List() {
        delete[] arr; // Clean up memory
    }

    virtual void addElementAtFirstIndex(type value) = 0;

    virtual void addElementAtLastIndex(type value) = 0;
    // Should add the element at the last position of the List

    virtual type removeElementFromEnd() = 0;
    // Should remove the element from the last position of the List

    virtual void removeElementFromStart() = 0;
    // Should remove the element from the first position of the List

    virtual void display() = 0;
};
