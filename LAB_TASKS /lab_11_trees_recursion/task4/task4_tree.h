
#pragma once

#include "node.h"
#include <iostream>
using namespace std;

class tree {
    Node* root;

public:
    tree() { root = nullptr; }

    void insert(int value) {
        Node* newNode = new Node(value);
        if (root == nullptr) {
            root = newNode;
            return;
        }

        Node* temp = root;
        while (true) {
            if (value < temp->data) {
                if (temp->left == nullptr) {
                    temp->left = newNode;
                    return;
                }
                temp = temp->left;
            }
            else if (value > temp->data) {
                if (temp->right == nullptr) {
                    temp->right = newNode;
                    return;
                }
                temp = temp->right;
            }
            else {
                delete newNode;
                return;
            }
        }
    }

    // function to find the  minimum
    int findMin() {
        if (root == nullptr) {
            cout << "Tree is empty!" << endl;
            return -1;
        }
        return findMinHelper(root);
    }

    //minimum Recursive maximum
    int findMax() {
        if (root == nullptr) {
            cout << "Tree is empty!" << endl;
            return -1;
        }
        return findMaxHelper(root);
    }

private:
    int findMinHelper(Node* current) {
        if (current->left == nullptr)
            return current->data;
        return findMinHelper(current->left);
    }

    int findMaxHelper(Node* current) {
        if (current->right == nullptr)
            return current->data;
        return findMaxHelper(current->right);
    }
};
#pragma once
