#pragma once
#include "db.h"
#include "list.h"
#include <mysql.h>
#include <iostream>

using namespace std;

void searchId();
void bubbleSort(struct Node* head);
void printList(struct Node* n);
void swap(struct Node* a, struct Node* b);
//int binarySearch(int[], int, int);

struct Node {

	int data;
	Node* next;

};

Node* id;

void searchId()
{
	linkedList idList;
	int prodId;
	//
	int listSize = 10;

	cout << "SEARCH PRODUCT" << endl;
	cout << "Enter the ID of product: ";
	cin >> prodId;


	bubbleSort(idhead);
	//idList.printList(idhead);
}

void bubbleSort(struct Node* id)
{
	int swapped;
	struct Node* ptr1;
	struct Node* lptr = NULL;

	/* Checking for empty list */
	if (id == NULL)
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

/*void printList(struct Node* start)
{
	struct Node* temp = start;
	printf("\n");
	while (temp != NULL)
	{
		printf("%p ", temp->data);
		temp = temp->next;
	}
}*/

void swap(struct Node* a, struct Node* b)
{
	int temp = a->data;
	a->data = b->data;
	b->data = temp;
}