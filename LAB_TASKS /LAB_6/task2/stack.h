#pragma once


# include <iostream>
using namespace std; 



template <class T>
class Stack {


protected: 

	T	* stack;
	int max_size ; 
	int current_index; 

public : 

	Stack(int size);

	virtual void push(T) = 0;
	 virtual T   pop() = 0;
	 virtual T   top() = 0;
	 virtual bool is_full() = 0;
	 virtual bool is_empty() = 0;

	};

template <class T>
 Stack <T> :: Stack (int size )

{

	max_size = size;
	stack = new T [max_size];
	current_index = 0;

}