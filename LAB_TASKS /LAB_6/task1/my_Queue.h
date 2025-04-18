# include "Queue.h"
# include <iostream>
using namespace std; 

template <class T>
class my_Queue : public Abstract_Queue <T> {

private: 
	int current_index ; 
	int front;
	int rear; 
	int max_size; 
	T* arr; 

public : 

	my_Queue   (int size) ;
	 void enQueue(T value )override;
	 T deQueue()override;
	 T Front()const override;
	 bool isEmpty()const override;
	 bool isFull()const override;
	
	 void display(); 
};


 template <class T >
 void my_Queue <T>::display()
 {
	 for (int i = 0; i < current_index; i++)
	 {
		 cout << arr[front] << endl ;
	 }
	 cout << "All the elements present in the queue has been displayed " << endl; 
 }




template <class T >
my_Queue<T> :: my_Queue(int  size) 
{
	front = 0; 
	rear = 0; 
	max_size = size; 
	current_index = 0;

	arr = new T[max_size];
}




template <class T >
void my_Queue<T> ::enQueue(T value) {

	if (!isFull())
	{
		arr[rear % max_size] = value; 
		current_index ++; 

	}
	else
	{
		cerr << "the satck is full cant add an element" << endl;;	}

}



template <class T >
T my_Queue<T> ::deQueue() {


	if (!isEmpty())
	{
		current_index--; 

		return arr[front++ % max_size];
	}
	else
	{
		cerr << "the satck is empty" << endl;;
		return T(); 
	}


}


template <class T >
T my_Queue<T> ::Front() const  {

	if (!isEmpty())
	{
		return arr[front];
	}
	else
	{
		cout << "the queue is empty " << endl; 
	}

	return 0;
}



template <class T >
bool my_Queue<T> ::isEmpty() const  {


	if (current_index == 0)
	{
		return true ;
	}
	else
	{
		return false ; 
	}
}



template <class T >
bool my_Queue<T> ::isFull() const {

	if (current_index == max_size)
	{
		return true;
	}
	else
	{
		return false;
	}
}
	