#pragma once
#include "db.h"
#include "list.h"
#include <mysql.h>
#include <iostream>
#include <string> 
#include <cstdlib> 
#include <ctype.h>
#include <iomanip>

//set the default namespace to std
using namespace std;

//const int SIZE = 10;
//int qstate;

//function prototype
void searchName();
int converSearchName(string, Node** name, Node** smallname);
string convertToLower(string name);
int linearSearch(string, Node* head);

//function to search product name
void searchName()
{
	int found;
	string prodName;
	linkedList nameList;
	linkedList smallNameList;

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
	
	cout << "\t\tEnter the name of product: ";
	cin.ignore();
	getline(cin, prodName);

	found = converSearchName(prodName, &namehead, &smallnamehead);

	if (found == -1)
	{
		cout << endl << "\t\tProduct not found!" << endl;
	}
	else
	{
		cout << endl << "\t\tProduct found! Product ID is " << found << "." << endl;
	}
}

//appending to linkedlist
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
	//cout << productName; //Test converted product name output
	//smallNameList.printList(smallnamehead); //Test the name that convert to small cases

	found = linearSearch(productName, smallnamehead);

	return found;
}

//converting string to all lovercase
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

// linear search function to search product name


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
