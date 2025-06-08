# pragma once 

# include "laB_10_node.h"
# include <iostream>
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
        display();
    }

    void add_at_tail_recurrisive(Node<T>* temp, Node<T>* newNode) {
        if (temp->next == nullptr) {
            temp->next = newNode;
            return;
        }
        temp = temp->next;
        add_at_tail_recurrisive(temp, newNode);
    }

    void add_at_head(T data) {
        Node<T>* newNode = new Node<T>(data);
        Node<T>* temp = head;
        head = newNode;
        head->next = temp;
        display();
    }

    void display() {
        Node<T>* temp = head;
        disply_recursive(temp);
    }

    void disply_recursive(Node<T>* temp) {
        if (temp == nullptr) {
            cout << "nullptr" << endl;
            return;
        }
        cout << temp->data << " -> ";
        disply_recursive(temp->next);
    }

    // Insert at a specific position (1-based index)
    void add_at_position(T data, int pos) {
        add_at_pos_recursive(head, data, pos);
        display();
    }

    void add_at_pos_recursive(Node<T>*& temp, T data, int pos) {
        if (pos <= 0) return;

        if (pos == 1) {
            Node<T>* newNode = new Node<T>(data);
            newNode->next = temp;
            temp = newNode;
            return;
        }
        add_at_pos_recursive(temp->next, data, pos - 1);
    }

    // Delete by value
    void delete_by_value(T val) {
        delete_by_value_recursive(head, val);
        display();
    }

    void delete_by_value_recursive(Node<T>*& temp, T val) {
        if (temp == nullptr) return;

        if (temp->data == val) {
            Node<T>* toDelete = temp;
            temp = temp->next;
            delete toDelete;
            return;
        }
        delete_by_value_recursive(temp->next, val);
    }

    // Delete at position (1-based)
    void delete_at_position(int pos) {
        delete_at_pos_recursive(head, pos);
        display();
    }

    void delete_at_pos_recursive(Node<T>*& temp, int pos) {
        if (temp == nullptr || pos <= 0) return;

        if (pos == 1) {
            Node<T>* toDelete = temp;
            temp = temp->next;
            delete toDelete;
            return;
        }
        delete_at_pos_recursive(temp->next, pos - 1);
    }

    // Search and return 1-based position
    int search(T val) {
        return search_recursive(head, val, 1);
    }

    int search_recursive(Node<T>* temp, T val, int pos) {
        if (temp == nullptr) return -1;
        if (temp->data == val) return pos;
        return search_recursive(temp->next, val, pos + 1);
    }
};
