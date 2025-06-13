#pragma once


# include "node.h"
# include <iostream>
using namespace std;



class tree {

	Node* root; 

public : 

	tree() { root = nullptr;  }
     
	void insert(int value) {
	
		Node* newNode = new Node(value);
		
	
		if (root == nullptr)
		{
			root = newNode;
			return;
		}
		else 
		{   
			Node* temp = root; 

			while (1)
			{
				if (temp->data > value) // move left 
				{
					if (temp->left == nullptr)
					{
						temp->left = newNode;
						return; 
					}
					else
					{
						temp = temp->left; 

					}
				}

				else if (temp->data < value) // move right 
				{

					if (temp->right == nullptr)
					{
						temp->right = newNode;
						return; 
					}
					else
					{
						temp = temp->right; 
					}

				}
			
			}


		}
	}

		
		


	void preorder(Node * root)
	{
   
		if (root == nullptr)
		{
			return;
		}

		cout << root->data << " ";
		preorder(root->left);
		preorder(root->right);


	}

	void pre_trav() {
	
		cout << "preorder ";
		preorder(root);
		cout << endl;
	}

	void in_trav() {

		cout << "inorder travsesal "<< " ";
		inorder(root);
		cout << endl; 
	}
	void post_trav()
	{
	
		cout << "post traversal ";

		post_traversal(root);
		cout << endl; 
	
	}

	void post_traversal(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}

		
	
		post_traversal(root->left);
		post_traversal(root->right);
		cout <<root->data<< " ";
	}


	void inorder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}
	    
		inorder(root->left);
		cout << root->data;
		inorder(root->right);
	}
};