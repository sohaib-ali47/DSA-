#pragma once
#include <iostream>
using namespace std;

const int MaxTasks = 100;

// struct for task
struct Task {
    int arrivalTime;
    int taskID;
};


class MinHeap {
private:
    Task heap[MaxTasks];
    int size;

    // swap two tasks
    void swap(Task& a, Task& b) {
        Task temp = a;
        a = b;
        b = temp;
    }

    // fix after insert
    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (compare(heap[index], heap[parent])) {
                swap(heap[index], heap[parent]);
                index = parent;
            }
            else {
                break;
            }
        }
    }

    // fix after remove
    void heapifyDown(int index) {
        while (index * 2 + 1 < size) {
            int left = index * 2 + 1;
            int right = index * 2 + 2;
            int smallest = index;

            if (left < size && compare(heap[left], heap[smallest]))
                smallest = left;
            if (right < size && compare(heap[right], heap[smallest]))
                smallest = right;

            if (smallest != index) {
                swap(heap[index], heap[smallest]);
                index = smallest;
            }
            else {
                break;
            }
        }
    }

    // cheak which task is small
    bool compare(Task a, Task b) {
        if (a.arrivalTime == b.arrivalTime)
            return a.taskID < b.taskID;
        return a.arrivalTime < b.arrivalTime;
    }

public:
    MinHeap() {
        size = 0;
    }

    // add task in heap
    void insert(Task t) {
        if (size < MaxTasks) {
            heap[size] = t;
            heapifyUp(size);
            size++;
        }
    }

    // get task which come first
    Task extractMin() {
        Task minTask = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);
        return minTask;
    }

    // check if heap empty
    bool isEmpty() {
        return size == 0;
    }

    // this will print task id
    void executeTask(int taskID) {
        cout << "Executing task " << taskID << "..." << endl;
    }

    // this is for planning and running tasks
    void scheduleTasks(const int* arrivalTimes, int totalTasks) {
        for (int i = 0; i < totalTasks; i++) {
            Task t;
            t.arrivalTime = arrivalTimes[i];
            t.taskID = i + 1;
            insert(t);
        }

        // now run all task
        while (!isEmpty()) {
            Task next = extractMin();
            executeTask(next.taskID);
        }
    }
};
