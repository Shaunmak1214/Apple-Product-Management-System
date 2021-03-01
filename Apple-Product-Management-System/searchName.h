#pragma once
#include "db.h"
#include "list.h"
#include <mysql.h>
#include <iostream>
#include <string> 
#include <cstdlib> 
#include <ctype.h>

using namespace std;

//const int SIZE = 10;
//int qstate;

void searchName();
int converSearchName(string, Node** name, Node** smallname);
string convertToLower(string name);
int linearSearch(string, Node* head);

void searchName()
{
	int found;
	string prodName;
	linkedList nameList;
	linkedList smallNameList;

	cout << "SEARCH PRODUCT" << endl;
	cout << "Enter the name of product: ";
	getline(cin, prodName);
	//cin.ignore();


	found = converSearchName(prodName, &namehead, &smallnamehead);
	cout << "Found: " << found;
}

int converSearchName(string prodName, Node** name, Node** smallname)
{
	linkedList smallNameList;
	string productName = convertToLower(prodName);
	Node* head = *name;
	Node* node = new Node();
	int found;

	while (head != NULL)
	{
		node->data = convertToLower(head->data);
		head = head->next;
		smallNameList.append(&smallnamehead, node->data);
	}
	cout << productName;
	smallNameList.printList(smallnamehead);

	found = linearSearch(productName, smallnamehead);

	return found;
}

string convertToLower(string str)
{
	for (int i = 0;i < str.length();i++)
	{
		//If the character is not a space
		if (str[i] != ' ')
		{
			//Reset the value of the array position to the new lower case letter
				str[i] = tolower(str[i]);
		}
	}
	return str;
}

int linearSearch(string productName, Node* head)
{
	int found = 1;
	while (head != NULL)
	{
		if (head->data == productName)
		{
			return found;
		}
		found++;
		head = head->next;
	}
	return -1;
}
