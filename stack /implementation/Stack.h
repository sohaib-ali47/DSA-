#include <iostream>
#include <string>
using namespace std;

template <class T>
class Stack
{
protected:
	T *arr;
	int maxSize;
	int currentSize;
public:
	virtual void push(T) = 0;
	virtual T pop() = 0;
	virtual bool isFull() = 0;
	virtual bool isEmpty() = 0;
	virtual T top() = 0;
	Stack(int);	//constructor
};

template <class T>
Stack<T>::Stack(int s)
{
	maxSize = s;
	arr = new T [s];
	currentSize = 0;
}