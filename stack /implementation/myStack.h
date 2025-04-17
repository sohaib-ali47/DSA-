#include "Stack.h"

template <class T>
class myStack :public Stack<T>
{
public:
	void push(T);	//push
	T pop();	//pop
	T top();
	myStack(int size);
	void display();
	bool isFull();
	bool isEmpty();
};

template <class T>
bool myStack<T>::isEmpty()
{
	if (currentSize == 0)
		return true;
	else
		return false;
}

template <class T>
bool myStack<T>::isFull()
{
	if (currentSize == maxSize)
		return true;

	else
		return false;
}

template <class T>
void myStack<T>::display()
{
	cout << "Max Size: " << maxSize << endl;
	cout << "Current Size: " << currentSize << endl;

	for (int i = 0; i < currentSize; i++)
	{
		cout << i << ". " << arr[i] << endl;
	}
}

template <class T>
myStack<T>::myStack(int size) :Stack<T>(size)
{

}

template <class T>
void myStack<T>::push(T value)
{
	if (!isFull())
	{
		arr[currentSize] = value;
		currentSize++;
	}

	else
		cout << "The array is FULL" << endl;
}

template <class T>
T myStack<T>::pop()
{
	if (!isEmpty())
	{
		currentSize--;
		return arr[currentSize];
	}

	else
	{
		cout << "Stack is Empty" << endl;
		return NULL;
	}
		
}

template <class T>
T myStack<T>::top()
{
	if (!isEmpty())
	{
		return arr[currentSize-1];
	}

	else
	{
		cout << "Stack is Empty" << endl;
		return NULL;
	}

}