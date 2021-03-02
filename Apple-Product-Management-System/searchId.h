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

//int binarySearch(int[], int, int);

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

	cout << "SEARCH PRODUCT" << endl;
	cout << "Enter the ID of product: ";
	cin >> prodId;


	storeIntId(idhead);
	bubbleSort(&intidhead);
	printList(intidhead);
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

void printList(struct idNode* intidhead)
{
	while (intidhead != NULL)
	{
		cout << intidhead->data << " -> ";
		intidhead = intidhead->next;
	}
	cout << endl;
}

/*void searchId()
{
	intLinkedList idList;
	int prodId;
	//
	int listSize = 10;

	cout << "SEARCH PRODUCT" << endl;
	cout << "Enter the ID of product: ";
	cin >> prodId;


	bubbleSort(id);
	//idList.printList(idhead);
}

void bubbleSort(struct Node* id)
{
	int swapped;
	struct Node* ptr1;
	struct Node* lptr = NULL;

	/* Checking for empty list */
	/*if (id == NULL)
		return;

	do
	{
		swapped = 0;
		ptr1 = id;

		while (ptr1->next != lptr)
		{
			if (ptr1->data > ptr1->next->data)
			{
				swap(ptr1, ptr1->next);
				swapped = 1;
			}
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
	} while (swapped);
}

void printList(struct Node* start)
{
	struct Node* temp = start;
	printf("\n");
	while (temp != NULL)
	{
		printf("%p ", temp->data);
		temp = temp->next;
	}
}

void swap(struct Node* a, struct Node* b)
{
	int temp = a->data;
	a->data = b->data;
	b->data = temp;
}*/