#include "my_stack.h"


template <typename T>
myStack<T>::myStack(int size) {
    maxSize = size;
    arr = new T[maxSize];
    currentIndex = 0;
}

template <typename T>
myStack<T>::~myStack() {
    delete[] arr;
}


template <typename T>
void myStack<T>::push(T value) {
    if (!isFull()) {
        arr[currentIndex] = value;
        currentIndex++;
    }
    else {
        cout << "Stack is full!" << endl;
    }
}


template <typename T>
T myStack<T>::pop() {
    if (!isEmpty()) {
        currentIndex--;
        return arr[currentIndex];
    }
    else {
        cout << "Stack is empty!" << endl;
        return T(); 
    }
}


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


template <typename T>
bool myStack<T>::isEmpty() const {
    return currentIndex == 0;
}


template <typename T>
bool myStack<T>::isFull() const {
    return currentIndex == maxSize;
}


template <typename T>
void myStack<T>::display() const {
    if (isEmpty()) {
        cout << "Stack is empty!" << endl;
    }
    else {
        cout << "Stack elements (top to bottom): ";
        for (int i = currentIndex - 1; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}
template class myStack<int>;
