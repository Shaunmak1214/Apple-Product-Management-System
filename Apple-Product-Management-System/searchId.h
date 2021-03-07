#pragma once
#include "db.h"
#include "list.h"
#include <mysql.h>
#include <iostream>
#include <stdlib.h>  //To use atoi

using namespace std;

void searchId();
void storeIntId(Node* idhead);
void bubbleSort(struct idNode** intidhead);
struct idNode* swap(struct idNode* ptr1, struct idNode* ptr2);
int getCount(idNode* intidhead);
struct idNode* binarySearch(idNode* intidhead, int prodId);
struct idNode* middle(idNode* first, idNode* last);

//New linked list for int data
struct idNode {

	int data;
	idNode* next;

};
//To store a list of int product ID
idNode* intidhead;

class intLinkedList {

public:
	int data;

	//Append product ID into linked list
	void append(idNode** head_ref, int new_data)
	{

		idNode* new_node = new idNode();

		idNode* last = *head_ref;

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

	//Print out the list of product ID
	void printList(idNode* node)
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

//Search product ID (apply bubble sort and binary search)
void searchId()
{
	//Call linked list with object
	linkedList idList;
	linkedList list;

	Node* node;
	int prodId;
	int count;
	int found;

	//Search product menu
	cout << endl;
	cout << "\t";
	for (int i = 0; i < 30; i++) { cout << (char)254 << " "; }
	cout << endl;
	cout << "\t" << (char)219 << setw(58) << "                                                         " << (char)219 << endl;
	cout << "\t" << (char)219 << setw(21) << "                      SEARCH PRODUCT			   " << (char)219 << endl;
	cout << "\t" << (char)219 << setw(58) << "                                                         " << (char)219 << endl;
	cout << "\t";
	for (int i = 0; i < 30; i++) { cout << (char)254 << " "; }
	cout << endl;

	cout << "\t\tEnter the product ID: ";
	cin >> prodId;

	//Call store product ID function for linked list
	storeIntId(idhead);

	//Bubble sort function
	bubbleSort(&intidhead);

	//Get total elements of linked list 
	count = getCount(intidhead);

	//Assign binary search result into linked list head
	idNode* head = binarySearch(intidhead, prodId);
	found = head->data;

	//Display finding result
	if (found == -1)
	{
		cout << endl << "\t\tProduct not found!" << endl;
	}
	else
	{
		cout << endl << "\t\tProduct found!." << endl;
	}

}

//Pass string ID linked list and store into int ID linked list
void storeIntId(Node* idhead)
{
	intLinkedList intIdList;
	int convertedId = 0;
	int listSize = 10;

	while (idhead != NULL)
	{
		//Convert string product ID to int
		convertedId = stoi(idhead->data);
		idhead = idhead->next;
		intIdList.append(&intidhead, convertedId);
	}
}

//Bubble sort to sort product ID
void bubbleSort(struct idNode** intidhead)
{
	struct idNode** h;
	int i, j, swapped;
	int count = 10;

	for (i = 0; i <= count; i++)
	{

		h = intidhead;
		swapped = 0;

		for (j = 0; j < count - i - 1; j++)
		{

			struct idNode* p1 = *h;
			struct idNode* p2 = p1->next;

			if (p1->data > p2->data)
			{

				/* update the link after swapping */
				*h = swap(p1, p2);
				swapped = 1;
			}

			h = &(*h)->next;
		}

		/* break if the loop ended without any swap */
		if (swapped == 0)
			break;
	}
}

//Swap the pointers which get from linked list 
struct idNode* swap(struct idNode* ptr1, struct idNode* ptr2)
{
	struct idNode* temp = ptr2->next;
	ptr2->next = ptr1;
	ptr1->next = temp;
	return ptr2;
}

//Get the total elements of linked list
int getCount(idNode* intidhead)
{
	int count = 0; // Initialize count  
	idNode* current = intidhead; // Initialize current  
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return count;
}

//Binary search to search the product ID in linked list
struct idNode* binarySearch(idNode* intidhead, int prodId)
{
	struct idNode* first = intidhead;
	struct idNode* last = NULL;

	do
	{
		// Find middle 
		idNode* mid = middle(first, last);

		// If middle is empty 
		if (mid == NULL)
			return NULL;

		// If value is present at middle 
		if (mid->data == prodId)
			return mid;

		// If value is more than mid 
		else if (mid->data < prodId)
			first = mid->next;

		// If the value is less than mid. 
		else
			last = mid;

	} while (last == NULL ||
		last != first);

	// value not present 
	return NULL;
}

//A function to find the middle point of linked list
struct idNode* middle(idNode* first, idNode* last)
{
	if (first == NULL)
		return NULL;

	struct idNode* slow = first;
	struct idNode* fast = first->next;
	while (fast != last) 
	{
		fast = fast->next;

		if (fast != last) 
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	return slow;
}