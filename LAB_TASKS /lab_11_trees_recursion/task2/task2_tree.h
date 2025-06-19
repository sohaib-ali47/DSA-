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
                // Duplicate value (optional handling)
                delete newNode;
                return;
            }
        }
    }

    void inorder(Node* root) {
        if (root == nullptr) return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void in_trav() {
        cout << "In-order Traversal (Ascending): ";
        inorder(root);
        cout << endl;
    }
};
