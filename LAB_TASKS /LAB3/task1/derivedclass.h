
#pragma once
#include "abstractclass.h"

template<typename type>
class Work : public List<type> {
public:
    // constructor
    Work(int max, int current) : List<type>(max, current) {}

    void addElementAtFirstIndex(type value) override {
        if (this->currentindex < this->maxsize) {
            for (int i = this->currentindex; i >= 0; i--) {
                this->arr[i + 1] = this->arr[i]; // moving the elements to the free index to make some space for the incoming element 
            }
            this->arr[0] = value;
            this->currentindex++;
        }
        else {
            cerr << "The array is already full. Can't add a new element." << endl;
        }
    }

    void addElementAtLastIndex(type value) override {
        if (this->currentindex < this->maxsize) {
            this->arr[this->currentindex] = value;
            this->currentindex++;
        }
        else {
            cerr << "The array is already full. Can't add a new element." << endl;
        }
    }

    type removeElementFromEnd() override {
        if (this->currentindex > 0) {
            this->currentindex--;
            return this->arr[this->currentindex];
        }
        cerr << "The array is empty. No element to remove." << endl;
        return type();  // Return default-constructed value     }

    void removeElementFromStart() override {
        if (this->currentindex > 0) {
            for (int i = 0; i < this->currentindex - 1; i++) {
                this->arr[i] = this->arr[i + 1];
            }
            this->currentindex--;
        }
        else {
            cerr << "The array is empty. No element to remove." << endl;
        }
    }

    void display() override {
        for (int i = 0; i < this->currentindex; i++) {
            cout << this->arr[i] << " ";
        }
        cout << endl << "All elements are displayed." << endl;
    }
};
