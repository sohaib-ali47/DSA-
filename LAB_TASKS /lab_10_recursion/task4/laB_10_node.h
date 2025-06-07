# pragma once 
# include <iostream>
using namespace std; 

template <typename T>

class Node
{
public:

	Node <T>* next;
	T data;

	Node(T data)
	{
		this->data = data;
		next = nullptr;
	}

};