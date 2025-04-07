#include <iostream>
#include "derivedclass.h"
using namespace std;

int main() {
    CustomList<int> list(10, 0);

    list.addElementAtFirstIndex(2);
    list.addElementAtLastIndex(7);
    list.addElementAtLastIndex(12);
    list.addElementAtLastIndex(4);
    list.addElementAtLastIndex(15);
    list.addElementAtLastIndex(7);
    list.addElementAtLastIndex(10);
    list.addElementAtLastIndex(3);
    list.addElementAtLastIndex(18);

    // Display the list
    cout << "List: ";
    list.display();

    // Sum of prime numbers
    cout << "Sum of primes: " << list.sum_ofPrime() << endl;

    // Second maximum even number
    cout << "Second max even number: " << list.secondMaxEven() << endl;

    // Second minimum odd number
    cout << "Second min odd number: " << list.secondMinOdd() << endl;

    // Print duplicates
    cout << "Duplicates: " << endl;
    list.printDuplicates();

    // Rotate clockwise
    list.rotateClockwise(3);
    cout << "List after rotating clockwise 3 times: ";
    list.display();

    // Rotate anti-clockwise
    list.rotateAntiClockwise(3);
    cout << "List after rotating anti-clockwise 3 times: ";
    list.display();

    return 0;
}





