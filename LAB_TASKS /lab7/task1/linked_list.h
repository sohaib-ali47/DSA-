#pragma once

# include "Node.h"
using namespace std;
#include <iostream>



class Linked_list  {
private:

	Node* head;


public:

	Linked_list() 
	{
		head = nullptr;
	}

	void push_front(int value)
	{
		cout << "pushing the " << value << "  at start" << endl;
		Node* newNode = new Node(value);
		if (head == NULL)
		{
			head = newNode;
			return;
		}
		else
		{
			newNode->next =head;
			head = newNode;
		}
	}
	void push_back(int value )
	{  
		cout << "pushing the " << value  << "  at the end" << endl;
		Node* newNode = new Node(value);
		if (head == NULL)
		{
			head  = newNode;
			return;
		}
		else
		{
			Node* temp = head; 
			
			while (temp->next  != nullptr)
			{
				temp = temp->next;
			}
			temp->next =newNode; 
		     				
				
			}
		
	}

	void display()
	{
		cout << "displaying the linked_list " << endl;
		Node* temp = head; 
		while (temp != nullptr)
		{
			cout << temp->data << " " << "-";
			temp = temp->next;
		}
		cout <<  "nulllptr" << endl;
	}
};
