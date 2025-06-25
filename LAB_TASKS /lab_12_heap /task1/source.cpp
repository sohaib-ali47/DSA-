#include <iostream>
using namespace std;

class MinHeap {
private:
    int heap[100]; // Fixed-size array (you can increase size)
    int size;

    // Heapify-up function to maintain min-heap property
    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] < heap[parent]) {
                swap(heap[index], heap[parent]);
                index = parent;
            }
            else {
                break;
            }
        }
    }

public:
    MinHeap() {
        size = 0;
    }

    // Insert an element and call heapify-up
    void insert(int value) {
        if (size >= 100) {
            cout << "Heap is full!\n";
            return;
        }
        heap[size] = value;
        heapifyUp(size);
        size++;
    }

    // Display heap as array
    void display() {
        cout << "Min-Heap as array: ";
        for (int i = 0; i < size; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MinHeap h;
    int n, val;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        h.insert(val);
    }

    h.display();

    return 0;
}
