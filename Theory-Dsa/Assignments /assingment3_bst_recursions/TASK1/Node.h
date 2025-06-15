#pragma once


class Node {

public :

	Node* left;
	Node* right;
	int data; 

	Node(int data);
};
Node::  Node(int data ) {

	this->data = data; 
	left = right = nullptr;


}