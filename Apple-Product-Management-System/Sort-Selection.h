#pragma once
/*
  INSERTION SORTING FUNCTION
  - SORT BY PRODUCT ID
*/

#include<iostream>
#include <mysql.h>
#include <string>
#include "db.h"
#include "product.h"

using namespace std;

// Struct Data Declaration
struct Details {
	string id;
	string code;
	string name;
	string category;
	string price;
	string color;
};

// list = the amount of total product
int Rows = getTotal();

// Function Declaration
int selectMin(Details pd[], int position);
void PrintSelect(Details pd[]);


// Retrieve Data From Struct 
Details* getDetails()
{
	int state;

	Details* pd;
	pd = new (nothrow) Details[Rows];

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
		state = mysql_query(conn, q);

		if (!state)
		{
			res = mysql_store_result(conn);
			int numfields = mysql_num_fields(res);
			int i = 0;

			while (row = mysql_fetch_row(res))
			{
				pd[i].id = row[0];
				pd[i].code = row[1];
				pd[i].name = row[2];
				pd[i].category = row[3];
				pd[i].price = row[4];
				pd[i].color = row[5];

				i++;
			}

			mysql_close(conn);
			return pd;
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

	return 0;
}

// Find the smallest value and return to the main function
int selectMin(Details pd[], int position)
{

	int index = position; // index of the current position
	Details temp;
	temp = pd[position];   // get the value of current position

	for (int i = position + 1; i < Rows; i++)
	{
		if (pd[i].category < temp.category)
		{
			temp = pd[i];  //swap the position 
			index = i;
			//cout << index << endl;
		}
	}

	return index;
}

// Display Sorted Products
void PrintSelect(Details pd[])
{
	cout << endl;
	cout << "\t";
	for (int i = 0; i < 30; i++) { cout << (char)254 << " "; }
	cout << endl;
	cout << "\t" << (char)219 << setw(58) << "                                                         " << (char)219 << endl;
	cout << "\t" << (char)219 << setw(58) << "         PRODUCT SORTED BY CATEGORY			" << (char)219 << endl;
	cout << "\t" << (char)219 << setw(58) << "                                                         " << (char)219 << endl;
	cout << "\t";
	for (int i = 0; i < 30; i++) { cout << (char)254 << " "; }
	cout << endl;

	cout << setw(5) << left << "No" << setw(5) << "Id" << setw(8) << "Code" << setw(30) << "Name" << setw(15) << "Category" << setw(10) << "Price" << setw(25) << "Colors" << endl;

	for (int i = 0; i < Rows; i++)
	{
		cout << setw(5) << i + 1 << setw(5) << pd[i].id << setw(8) << pd[i].code << setw(30) << pd[i].name << setw(15) << pd[i].category << setw(10) << pd[i].price << setw(25) << pd[i].color << endl;
	}
}

void SelectSort()
{
	Details* pd, current;
	pd = new (nothrow) Details[Rows];
	pd = getDetails();


	for (int i = 0; i < Rows - 1; i++)
	{
		//Selection Sort
		int min = selectMin(pd, i);
		//cout << min << endl;

		// Select the minimum element in each loop
		if (pd[min].category < pd[i].category)
		{
			current = pd[min];
			pd[min] = pd[i];      // swap the position
			pd[i] = current;	  // swap the position

		}
	}

	PrintSelect(pd);

}
