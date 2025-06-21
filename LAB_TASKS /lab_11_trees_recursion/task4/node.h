# pragma once 



class Node {


public : 

	Node* left, * right;
	int data;

	Node(int value) { data = value; left = right = nullptr; }
};