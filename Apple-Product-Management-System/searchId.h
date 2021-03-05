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
void printList(struct idNode* intidhead);
int getCount(idNode* intidhead);
struct idNode* binarySearch(idNode* intidhead, int prodId);
struct idNode* middle(idNode* first, idNode* last);

struct idNode {

	int data;
	idNode* next;

};

idNode* intidhead;

class intLinkedList {

public:
	int data;

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

void searchId()
{
	linkedList idList;

	int prodId;
	int count;
	int found;

	cout << endl;
	cout << "+---------------------------------------------------+" << endl;
	cout << "                   SEARCH PRODUCT                    " << endl;
	cout << "+---------------------------------------------------+" << endl;
	cout << "Enter the product ID: ";
	cin >> prodId;

	storeIntId(idhead);
	bubbleSort(&intidhead);
	printList(intidhead); //Test output

	count = getCount(intidhead);
	cout << "Count: " << count;

	idNode* head = binarySearch(intidhead, prodId);
	cout << endl <<  "Data: " << head->data;

	//idList.printList(idhead);
}

void storeIntId(Node* idhead)
{
	intLinkedList intIdList;
	int convertedId = 0;
	int listSize = 10;

	while (idhead != NULL)
	{
		convertedId = stoi(idhead->data);
		idhead = idhead->next;
		intIdList.append(&intidhead, convertedId);
	}
	intIdList.printList(intidhead); //Test output
}

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

struct idNode* swap(struct idNode* ptr1, struct idNode* ptr2)
{
	struct idNode* temp = ptr2->next;
	ptr2->next = ptr1;
	ptr1->next = temp;
	return ptr2;
}

void printList(struct idNode* intidhead) //Test output
{
	while (intidhead != NULL)
	{
		cout << intidhead->data << " -> ";
		intidhead = intidhead->next;
	}
	cout << endl;
}

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

//int binarySearch(idNode* intidhead, int count, int prodId)
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