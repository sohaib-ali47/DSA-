// memory blocks of same data type
// contiguous memory location
// static and dynamic
// homogenoeus data structures
// dimensions

#include <iostream>
#include "myStack.h"
using namespace std;

int main()
{
	myStack<int> obj(5);

	obj.push(-3);
	obj.push(15);
	obj.push(99);
	obj.push(888);
	obj.push(-33);
	cout << "Top = " << obj.top() << endl;
	obj.display();

	cout << endl << endl << endl;

	myStack<char> obj2(100);
	obj2.push('A');
	obj2.push(48);
	obj2.display();

	myStack<string> obj3(15);
	obj3.push("daniyal");
	obj3.display();
	return 0;
}



