#pragma once

#include "laB_10_node.h"
#include <iostream>
using namespace std;

template <typename T>
class linked_list {
private:
    Node<T>* head;

public:
    linked_list() { head = nullptr; } // Constructor

    void add_at_tail(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node<T>* temp = head;
            add_at_tail_recurrisive(temp, newNode);
        }
    }

    void add_at_tail_recurrisive(Node<T>* temp, Node<T>* newNode) {
        if (temp->next == nullptr) {
            temp->next = newNode;
            return;
        }

        temp = temp->next;
        add_at_tail_recurrisive(temp, newNode);
    }

    void display() {
        Node<T>* temp = head;
        disply_recursive(temp);
    }

    void disply_recursive(Node<T>* temp) {
        if (temp->next == nullptr) {
            cout << temp->data << " -> nullptr" << endl;
            return;
        }

        cout << temp->data << " -> ";
        temp = temp->next;
        disply_recursive(temp);
    }
};
