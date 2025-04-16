#include "my_stack.h"

// constructor to create array with size
template <typename T>
myStack<T>::myStack(int size) {
    maxSize = size;
    arr = new T[maxSize];
    currentIndex = 0;
}

// delete array when done
template <typename T>
myStack<T>::~myStack() {
    delete[] arr;
}

// push value in stack
template <typename T>
void myStack<T>::push(T value) {
    if (!isFull()) {
        arr[currentIndex] = value;
        currentIndex++;

        if (minStack.empty() || value <= minStack.top()) {
            minStack.push(value); // update min tracker also
        }
    }
    else {
        cout << "Stack is full!" << endl;
    }
}

// pop value from stack
template <typename T>
T myStack<T>::pop() {
    if (!isEmpty()) {
        currentIndex--;
        T poppedValue = arr[currentIndex];

        if (poppedValue == minStack.top()) {
            minStack.pop(); // also remove from min tracker
        }

        return poppedValue;
    }
    else {
        cout << "Stack is empty!" << endl;
        return T(); // return 0 or default
    }
}

// see top value of stack
template <typename T>
T myStack<T>::top() const {
    if (!isEmpty()) {
        return arr[currentIndex - 1];
    }
    else {
        cout << "Stack is empty!" << endl;
        return T();
    }
}

// check if stack is empty
template <typename T>
bool myStack<T>::isEmpty() const {
    return currentIndex == 0;
}

// check if stack is full
template <typename T>
bool myStack<T>::isFull() const {
    return currentIndex == maxSize;
}

// show all stack values
template <typename T>
void myStack<T>::display() const {
    if (isEmpty()) {
        cout << "Stack is empty!" << endl;
    }
    else {
        cout << "Stack from top to bottom: ";
        for (int i = currentIndex - 1; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

// get the minimum value
template <typename T>
T myStack<T>::getMin() const {
    if (!minStack.empty()) {
        return minStack.top();
    }
    else {
        cout << "Stack is empty! No min value." << endl;
        return T();
    }
}

// template instanciation
template class myStack<int>;
