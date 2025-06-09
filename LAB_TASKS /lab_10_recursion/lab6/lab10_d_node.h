#pragma once

#include <iostream>
using namespace std;

template <typename T>
class DNode {
public:
    T data;
    DNode<T>* prev;
    DNode<T>* next;

    DNode(T val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};