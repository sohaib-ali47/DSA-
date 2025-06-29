# pragma once 
#include <iostream>
using namespace std;

struct Node {
    int key;
    int value;
    Node* next;

    Node(int k, int v) {
        key = k;
        value = v;
        next = NULL;
    }
};

class UnorderedMap {
private:
    static const int SIZE = 10;
    Node* buckets[SIZE];

    int getHash(int key) {
        return key % SIZE;
    }

public:
    UnorderedMap() {
        for (int i = 0; i < SIZE; i++)
            buckets[i] = NULL;
    }

    void insert(int key, int value) {
        int index = getHash(key);
        Node* temp = buckets[index];

        while (temp != NULL) {
            if (temp->key == key) {
                temp->value = value;
                return;
            }
            temp = temp->next;
        }

        Node* newNode = new Node(key, value);
        newNode->next = buckets[index];
        buckets[index] = newNode;
    }

    int get(int key) {
        int index = getHash(key);
        Node* temp = buckets[index];

        while (temp != NULL) {
            if (temp->key == key)
                return temp->value;
            temp = temp->next;
        }
        return -1;
    }

    void remove(int key) {
        int index = getHash(key);
        Node* temp = buckets[index];
        Node* prev = NULL;

        while (temp != NULL) {
            if (temp->key == key) {
                if (prev == NULL)
                    buckets[index] = temp->next;
                else
                    prev->next = temp->next;
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
    }

    void show() {
        cout << "    --- Hash Table Buckets ---" << endl;
        for (int i = 0; i < SIZE; i++) {
            cout << "    [" << i << "]: ";
            Node* temp = buckets[i];
            while (temp != NULL) {
                cout << "(" << temp->key << " => " << temp->value << ") -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
    }
};


