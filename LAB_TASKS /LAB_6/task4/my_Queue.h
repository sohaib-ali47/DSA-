#pragma once
#include "Queue.h"
#include <iostream>
using namespace std;

template <class T>
class my_Queue : public Abstract_Queue<T> {
private:
    int current_index;
    int front;
    int rear;
    int max_size;
    T* arr;

public:
    my_Queue(int size);
    void enQueue(T value) override;
    T deQueue() override;
    T Front() const override;
    bool isEmpty() const override;
    bool isFull() const override;
    void display() const;  
};

template <class T>
my_Queue<T>::my_Queue(int size) {
    front = 0;
    rear = -1; 
    max_size = size;
    current_index = 0;
    arr = new T[max_size];
}

template <class T>
void my_Queue<T>::enQueue(T value) {
    if (!isFull()) {
        rear = (rear + 1) % max_size;  
        arr[rear] = value;
        current_index++;
    }
    else {
        cerr << "Queue is full! Cannot add ticket ID: " << value << endl;
    }
}

template <class T>
T my_Queue<T>::deQueue() {
    if (!isEmpty()) {
        T ticket = arr[front];
        front = (front + 1) % max_size; 
        current_index--;
        return ticket;
    }
    else {
        cerr << "Queue is empty! No tickets to resolve." << endl;
        return T();  
    }
}

template <class T>
T my_Queue<T>::Front() const {
    if (!isEmpty()) {
        return arr[front];
    }
    else {
        cerr << "Queue is empty! No pending tickets." << endl;
        return T();  
    }
}

template <class T>
bool my_Queue<T>::isEmpty() const {
    return (current_index == 0);
}

template <class T>
bool my_Queue<T>::isFull() const {
    return (current_index == max_size);
}

template <class T>
void my_Queue<T>::display() const {
    if (isEmpty()) {
        cout << "No pending tickets." << endl;
        return;
    }
    cout << "Pending Tickets (Front to Rear):" << endl;
    int count = 0;
    int i = front;
    while (count < current_index) {
        cout << "Ticket ID: " << arr[i] << endl;
        i = (i + 1) % max_size;  
        count++;
    }
}