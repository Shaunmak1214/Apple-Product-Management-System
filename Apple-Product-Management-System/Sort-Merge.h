#pragma once

/*
  MERGE SORTING FUNCTION
  - SORT BY PRODUCT PRICE
*/

#include<iostream>
#include<iomanip>
#include <mysql.h>
#include <assert.h>
#include "db.h"
#include "product.h"

using namespace std;

// Struct Data Declaration
struct Products {
	string id;
	string code;
	string name;
	string category;
	string price;
	string color;
};

// num of total Products
int totalRows = getTotal();

// Function Declaration
void Merge(Products* pr, int lpos, int rpos, int rend);
Products* getProductDetails();
void MergeSort(Products* pr, int left, int right);
void PrintProducts(Products* pr);


// Retrieve Data From Struct 
Products* getProductDetails()
{
	int states;

	Products* pr;
	pr = new (nothrow) Products[totalRows];

	// Connect to database (phpMyAdmin)
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_ROW columnNameRow = NULL;
	MYSQL_RES* res;
	MYSQL_RES* columnNameRes;
	conn = initConnection();

	if (conn)
	{
		string query = "SELECT * FROM products";
		const char* q = query.c_str();
		states = mysql_query(conn, q);
		if (!states)
		{
			res = mysql_store_result(conn);
			int i = 0;

			// store data from database in struct variable
			while (row = mysql_fetch_row(res))
			{
				pr[i].id = row[0];
				pr[i].code = row[1];
				pr[i].name = row[2];
				pr[i].category = row[3];
				pr[i].price = row[4];
				pr[i].color = row[5];

				i++;
			}

			mysql_close(conn);
			return pr;

		}
		// Error Handlings
		else
		{	
			cout << "Query failed: " << mysql_error(conn) << endl;
		}
	}
	else
	{
		puts("Connection to database has failed!");	
	}
	cout << "Check connection" << endl;		

	return 0;
}

<<<<<<< Updated upstream
// Merge Function
=======
>>>>>>> Stashed changes
void Merge(Products pr[], int lpos, int rpos, int rend)
{
	int lend, numElements, tempPos;

<<<<<<< Updated upstream
	/* create temp array */
	Products* tempArr = new (nothrow) Products[totalRows];
=======
	Products* tempArr = new (nothrow) Products[totalRows];
	//tempArr = new (nothrow) Products[totalRows];
>>>>>>> Stashed changes

	lend = rpos - 1;
	tempPos = lpos;
	numElements = rend - lpos + 1;

	while (lpos <= lend && rpos <= rend)
	{
		int leftPrice = stoi(pr[lpos].price);
		int rightPrice = stoi(pr[rpos].price);
	
		if (leftPrice > rightPrice) {
<<<<<<< Updated upstream
=======
		//if (pr[lpos].price < pr[rpos].price) {
>>>>>>> Stashed changes
			tempArr[tempPos++] = pr[lpos++];
		}
		else {
			tempArr[tempPos++] = pr[rpos++];
		}

		/* Copy the remaining elements of first half, if there are any */
		while (lpos <= lend)
		{
			tempArr[tempPos++] = pr[lpos++];
		}

		/* Copy the remaining elements of second half, if there are any */
		while (rpos <= rend)
		{
			tempArr[tempPos++] = pr[rpos++];
		}
<<<<<<< Updated upstream

		/* Copy the temp array to original array */
=======
>>>>>>> Stashed changes
		for (int i = 0; i < numElements; i++, rend--)
		{
			pr[rend] = tempArr[rend];
		}
<<<<<<< Updated upstream

=======
		for (int i = 0; i < numElements; i++)
		{
			cout << pr[i].price << " ";
		}
		cout << endl;
>>>>>>> Stashed changes
	}

}

<<<<<<< Updated upstream
// Merge Sort Function
// `left` is for left index and `right` is right index of the
// sub-array of pr to be sorted 
=======
>>>>>>> Stashed changes
void MergeSort(Products pr[], int left, int right)
{
	int mid;

	if (left < right)
	{
		mid = (left + right) / 2;

		// Recursive Function
		MergeSort(pr, left, mid);			// recurcive mergesort first and second halves
		MergeSort(pr, mid + 1, right);
		Merge(pr, left, mid + 1, right);	//merge

	}
}

<<<<<<< Updated upstream
// Display Sorted Products
=======
>>>>>>> Stashed changes
void PrintProducts(Products pr[])
{
	cout << endl;
	cout << "\t";
	for (int i = 0; i < 30; i++) { cout << (char)254 << " "; }
	cout << endl;
	cout << "\t" << (char)219 << setw(58) << "                                                         " << (char)219 << endl;
	cout << "\t" << (char)219 << setw(58) << "         PRODUCT SORTED BY NAME		" << (char)219 << endl;
	cout << "\t" << (char)219 << setw(58) << "                                                         " << (char)219 << endl;
	cout << "\t";
	for (int i = 0; i < 30; i++) { cout << (char)254 << " "; }
	cout << endl;

	cout << setw(5) << left << "no" << setw(5) << "id" << setw(8) << "code" << setw(30) << "name" << setw(15) << "category" << setw(10) << "price" << setw(25) << "colors" << endl;

	for (int i = 0; i < totalRows; i++)
	{
		cout << setw(5) << i + 1 << setw(5) << pr[i].id << setw(8) << pr[i].code << setw(30) << pr[i].name << setw(15) << pr[i].category << setw(10) << pr[i].price << setw(25) << pr[i].color << endl;
	}
}

// Merge Sorting Function
void MergeSorting()
{
	Products* pr;
	pr = new (nothrow) Products[totalRows];
	pr = getProductDetails();

	MergeSort(pr, 0, totalRows - 1);	// mergesort(arr,left,right) called

	PrintProducts(pr);

}
