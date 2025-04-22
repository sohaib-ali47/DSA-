#include <iostream>
#include "my_Queue.h"
#include "myStack.h"
using namespace std;

void reverseFirstK(my_Queue<int>& q, int k) {
    if (k <= 1 || k > q.size()) {
        return;  // No reversal needed
    }

    myStack<int> stack(k);  
    
     for (int i = 0; i < k; i++) {
        stack.push(q.deQueue());
    }

    
    while (!stack.is_empty()) {
        q.enQueue(stack.pop());
    }

    
    for (int i = 0; i < q.size() - k; i++) {
        q.enQueue(q.deQueue());
    }
}

int main() {
    int n, k;
    cout << "Enter the number of elements in the queue: ";
    cin >> n;

    my_Queue<int> q(n);

    cout << "Enter " << n << " elements for the queue:\n";
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        q.enQueue(num);
    }

    cout << "Original Queue: ";
    q.display();

    cout << "Enter K (number of elements to reverse): ";
    cin >> k;

    reverseFirstK(q, k);

    cout << "Queue after reversing first " << k << " elements: ";
    q.display();

    return 0;
}
