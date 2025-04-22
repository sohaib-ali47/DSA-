#pragma once  

#include <iostream>
using namespace std;

template <class T>
class Abstract_Queue {
public:
    virtual void enQueue(T value) = 0;
    virtual T deQueue() = 0;
    virtual T Front() const = 0; 
    virtual bool isEmpty() const = 0; 
    virtual bool isFull() const = 0;  
    virtual ~Abstract_Queue() {}
};
