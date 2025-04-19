#pragma once

# include "stack.h"



template <class T>
class myStack : public Stack <T>
{
public : 

	                                               //constructor 
	myStack(int size) : Stack <T>(size) {}

	void push(T);
	bool is_full();
	bool is_empty();
	T pop();
	T top();

	void display();
	//void copy_stack(myStack <int>& obj1, myStack <int>& obj2, );
};

template <class T>
void myStack <T> ::display() {
	int i = this->current_index-1;
	while (i >=0)
	{
		cout << this->stack[i] << endl;

		i--;
	}
}


 
                                          // push function 
template <class T>
void myStack <T> ::push(T value)
{
	if (this->current_index < this->max_size)
	{
		this->stack[this->current_index] = value;
		this->current_index++;
	}
	else
	{
		cerr << "The stack is already full " << endl; 
	}
}
                                          // /is_full function 
template <class T>
bool myStack <T> ::is_full() {


	if (this->current_index == this->max_size)
	{
		return true;
	}
	else
	{
		return false; 
	}

}

                                        // /   is_empty() function 

template <class T>
bool myStack <T> ::is_empty()
{
	if (this->current_index == 0)
	{
		return true;
	}
	else
	{
		return false;

	}
}  


                                           // /   pop  function 


template <class T>
T myStack <T> ::pop()
{
	if (!this->is_empty())
	{
		char temp = top();
		this->current_index--;
		return temp;
		
	}
	else
	{
		cerr << "the stack is empty " << endl; 
		return NULL;
	}
}


                                  // /   is_empty() function 

template <class T>
T myStack <T> ::top()
{

	return this->stack[this->current_index-1];

}