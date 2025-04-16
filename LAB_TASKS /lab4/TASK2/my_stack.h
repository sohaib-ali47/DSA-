#pragma once

#include "abstract_stack.h"
#include <iostream>
#include <stack> // used for minimum tracker
using namespace std;

// this is the actual stack class
template <typename T>
class myStack : public AbstractStack<T> {
private:
    T* arr;
    int maxSize;
    int currentIndex;

    stack<T> minStack; // to keep record of the minimum numbers

public:
    myStack(int size); // constractor
    ~myStack(); // destractor

    void push(T value);
    T pop();
    T top() const;
    bool isEmpty() const;
    bool isFull() const;
    void display() const;
    T getMin() const; // new function to get minimum
};
