#pragma once
#include <iostream>
#include <string>
using namespace std;

class myCarStack {
private:
    string cars[8]; // only 8 cars can park
    int topIndex;

public:
    myCarStack() {
        topIndex = -1;
    }

    bool isFull() {
        return topIndex == 7;
    }

    bool isEmpty() {
        return topIndex == -1;
    }

    void push(string car) {
        if (!isFull()) {
            topIndex++;
            cars[topIndex] = car;
        }
        else {
            cout << "Parking is full!" << endl;
        }
    }

    string pop() {
        if (!isEmpty()) {
            string car = cars[topIndex];
            topIndex--;
            return car;
        }
        else {
            return "";
        }
    }

    string top() {
        if (!isEmpty()) {
            return cars[topIndex];
        }
        else {
            return "No car";
        }
    }

    int count() {
        return topIndex + 1;
    }

    bool findCar(string carNumber) {
        for (int i = 0; i <= topIndex; i++) {
            if (cars[i] == carNumber) {
                return true;
            }
        }
        return false;
    }

    // for internal use when rearranging stack
    string getCarAt(int i) {
        return cars[i];
    }

    void setCarAt(int i, string car) {
        cars[i] = car;
    }

    int getTopIndex() {
        return topIndex;
    }
};
