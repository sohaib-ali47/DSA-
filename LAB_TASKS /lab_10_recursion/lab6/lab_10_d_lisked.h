#pragma once

# include "lab10_d_node.h"

template <typename T>
class doubly_linked_list {
private:
    DNode<T>* head;

public:
    doubly_linked_list() {
        head = nullptr;
    }

    void insert_at_head(T data) {
        DNode<T>* newNode = new DNode<T>(data);
        if (head != nullptr) {
            head->prev = newNode;
            newNode->next = head;
        }
        head = newNode;
    }

    void insert_at_tail(T data) {
        DNode<T>* newNode = new DNode<T>(data);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            insert_tail_recursive(head, newNode);
        }
    }

    void insert_tail_recursive(DNode<T>* current, DNode<T>* newNode) {
        if (current->next == nullptr) {
            current->next = newNode;
            newNode->prev = current;
            return;
        }
        insert_tail_recursive(current->next, newNode);
    }

    void insert_at_position(int pos, T data) {
        DNode<T>* newNode = new DNode<T>(data);
        if (pos == 1) {
            insert_at_head(data);
        }
        else {
            insert_at_pos_recursive(head, newNode, pos - 1);
        }
    }

    void insert_at_pos_recursive(DNode<T>* current, DNode<T>* newNode, int pos) {
        if (pos == 1 && current != nullptr) {
            newNode->next = current->next;
            newNode->prev = current;
            if (current->next != nullptr)
                current->next->prev = newNode;
            current->next = newNode;
            return;
        }
        insert_at_pos_recursive(current->next, newNode, pos - 1);
    }

    void delete_by_value(T value) {
        delete_by_value_recursive(head, value);
    }

    void delete_by_value_recursive(DNode<T>* current, T value) {
        if (current == nullptr) return;
        if (current->data == value) {
            if (current->prev) current->prev->next = current->next;
            if (current->next) current->next->prev = current->prev;
            if (current == head) head = current->next;
            delete current;
            return;
        }
        delete_by_value_recursive(current->next, value);
    }

    void delete_at_position(int pos) {
        delete_at_pos_recursive(head, pos);
    }

    void delete_at_pos_recursive(DNode<T>* current, int pos) {
        if (current == nullptr) return;
        if (pos == 1) {
            if (current->prev) current->prev->next = current->next;
            if (current->next) current->next->prev = current->prev;
            if (current == head) head = current->next;
            delete current;
            return;
        }
        delete_at_pos_recursive(current->next, pos - 1);
    }

    int search(T value) {
        return search_recursive(head, value, 1);
    }

    int search_recursive(DNode<T>* current, T value, int pos) {
        if (current == nullptr) return -1;
        if (current->data == value) return pos;
        return search_recursive(current->next, value, pos + 1);
    }

    void print_forward() {
        print_forward_recursive(head);
        cout << "nullptr" << endl;
    }

    void print_forward_recursive(DNode<T>* current) {
        if (current == nullptr) return;
        cout << current->data << " <-> ";
        print_forward_recursive(current->next);
    }

    void print_reverse() {
        DNode<T>* tail = head;
        if (tail == nullptr) return;
        while (tail->next != nullptr)
            tail = tail->next;
        print_reverse_recursive(tail);
        cout << "nullptr" << endl;
    }

    void print_reverse_recursive(DNode<T>* current) {
        if (current == nullptr) return;
        cout << current->data << " <-> ";
        print_reverse_recursive(current->prev);
    }

    bool is_palindrome() {
        DNode<T>* tail = head;
        while (tail && tail->next)
            tail = tail->next;
        return check_palindrome_recursive(head, tail);
    }

    bool check_palindrome_recursive(DNode<T>* left, DNode<T>* right) {
        if (!left || !right) return true;
        if (left == right || left->next == right) {
            return left->data == right->data;
        }
        if (left->data != right->data) return false;
        return check_palindrome_recursive(left->next, right->prev);
    }
};