#pragma once
#include <iostream>
#include <string>

//setting default namespace to use std
using namespace std;

//node structure for linkedlist
struct Node {

	string data;
	Node* next;

};

//Variable Initializing
Node* head;
Node* idhead;
Node* namehead;
Node* smallnamehead;

//linkedlist class
class linkedList {

public:

	//append new node to linkedlist
	void append(Node** head_ref, string new_data)
	{

		Node* new_node = new Node();

		Node* last = *head_ref;

		new_node->data = new_data;

		new_node->next = NULL;

		if (*head_ref == NULL)
		{
			*head_ref = new_node;
			return;
		}

		while (last->next != NULL)
			last = last->next;

		last->next = new_node;
		return;
	}

	//print all the nodes in linkedlist
	void printList(Node* node)
	{
		int counter = 1;

		cout << endl;
		cout << "==========================" << endl;
		cout << "       Linked List" << endl;
		cout << "==========================" << endl;

		while (node != NULL)
		{
			cout << "Index " << counter << ":" << "  " << node->data << endl;
			node = node->next;

			counter++;
		}
	}
};