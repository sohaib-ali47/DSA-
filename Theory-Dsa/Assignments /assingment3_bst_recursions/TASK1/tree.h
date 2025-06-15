#pragma once

#include "Node.h"
#include <iostream>
using namespace std;

class BST {
public:
    Node* root;

    BST() {
        root = nullptr;
    }

    ~BST() {
        delete_recursion(root);
    }

    void delete_recursion(Node* node) {
        if (node == nullptr) return;
        delete_recursion(node->left);
        delete_recursion(node->right);
        delete node;
    }

    void insert(int value) {
        Node* new_node = new Node(value);
        if (root == nullptr) {
            root = new_node;
            return;
        }

        Node* temp = root;
        while (true) {
            if (value < temp->data) {
                if (temp->left == nullptr) {
                    temp->left = new_node;
                    return;
                }
                temp = temp->left;
            }
            else {
                if (temp->right == nullptr) {
                    temp->right = new_node;
                    return;
                }
                temp = temp->right;
            }
        }
    }

    // (a) Check if valid BST
    bool is_valid_bst() {
        return is_valid_bst_recursion(root, nullptr, nullptr);
    }

    bool is_valid_bst_recursion(Node* node, Node* min_node, Node* max_node) {
        if (node == nullptr) return true;

        if (min_node && node->data <= min_node->data) return false;
        if (max_node && node->data >= max_node->data) return false;

        return is_valid_bst_recursion(node->left, min_node, node) &&
            is_valid_bst_recursion(node->right, node, max_node);
    }

    // (b) Convert BST to sorted array
    void convert_to_sorted_array() {
        int array[100]; // fixed size
        int index = 0;
        fill_array_inorder_recursion(root, array, index);

        cout << "Sorted Array: ";
        for (int i = 0; i < index; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    void fill_array_inorder_recursion(Node* node, int array[], int& index) {
        if (node == nullptr) return;

        fill_array_inorder_recursion(node->left, array, index);
        array[index++] = node->data;
        fill_array_inorder_recursion(node->right, array, index);
    }

    // (c) Distance between two nodes
    int find_distance_between_nodes(int value1, int value2) {
        Node* lowest_common_ancestor = find_lca_recursion(root, value1, value2);
        int distance1 = find_node_distance_recursion(lowest_common_ancestor, value1);
        int distance2 = find_node_distance_recursion(lowest_common_ancestor, value2);
        return distance1 + distance2;
    }

    Node* find_lca_recursion(Node* node, int value1, int value2) {
        if (node == nullptr) return nullptr;

        if (value1 < node->data && value2 < node->data) {
            return find_lca_recursion(node->left, value1, value2);
        }
        else if (value1 > node->data && value2 > node->data) {
            return find_lca_recursion(node->right, value1, value2);
        }
        else {
            return node;
        }
    }

    int find_node_distance_recursion(Node* node, int value) {
        if (node->data == value) return 0;
        else if (value < node->data) return 1 + find_node_distance_recursion(node->left, value);
        else return 1 + find_node_distance_recursion(node->right, value);
    }

    // (d) Check if tree is balanced
    bool is_tree_balanced() {
        return check_balance_recursion(root) != -1;
    }

    int check_balance_recursion(Node* node) {
        if (node == nullptr) return 0;

        int left_height = check_balance_recursion(node->left);
        if (left_height == -1) return -1;

        int right_height = check_balance_recursion(node->right);
        if (right_height == -1) return -1;

        int difference = left_height - right_height;
        if (difference < -1 || difference > 1) return -1;

        return 1 + max(left_height, right_height);
    }
};
