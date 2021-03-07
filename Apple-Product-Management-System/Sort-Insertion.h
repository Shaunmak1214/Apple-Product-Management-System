#pragma once
/*
  INSERTION SORTING FUNCTION
  - SORT BY PRODUCT NAME
*/

#include<iostream>
#include<iomanip>
#include <mysql.h>
#include <string>
#include "db.h"
#include "product.h"

using namespace std;

// Struct Data Declaration
struct Product {
	string id;
	string code;
	string name;
	string category;
	string price;
	string color;
};

// list = the amount of total product
int total = getTotal();

// Function Declaration
void PrintInsert(Product* p);
Product* getProductData();


// Retrieve Data From Struct 
Product* getProductData()
{
	int state;

	Product* p;
	p = new (nothrow) Product[total];

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
		state = mysql_query(conn, q);
		if (!state)
		{
			res = mysql_store_result(conn);
			int i = 0;

			// store data from database in struct variable
			while (row = mysql_fetch_row(res))
			{
				p[i].id = row[0];
				p[i].code = row[1];
				p[i].name = row[2];
				p[i].category = row[3];
				p[i].price = row[4];
				p[i].color = row[5];

				i++;
			}

			mysql_close(conn);
			return p;
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

// Display Sorted Products
void PrintInsert(Product* p)
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

	cout << setw(5) << left << "No" << setw(5) << "Id" << setw(8) << "Code" << setw(30) << "Name" << setw(15) << "Category" << setw(10) << "Price" << setw(25) << "Colors" << endl;

	for (int i = 0; i < total; i++)
	{
		cout << setw(5) << i + 1 << setw(5) << p[i].id << setw(8) << p[i].code << setw(30) << p[i].name << setw(15) << p[i].category << setw(10) << p[i].price << setw(25) << p[i].color << endl;
	}

}

// Insertion Sorting Function
void InsertSort()
{
	// create objects for Product
	Product* p, temp;
	p = new (nothrow) Product[total];
	p = getProductData();

	for (int i = 0; i < total; i++)
	{
		//Insertion Sort
		temp = p[i];  // copy database into temp
		int j = i;    // assign current index to jCounting 

		while (j > 0 && temp.name < p[j - 1].name)
		{
			p[j] = p[j - 1];  //swap the value
			j--;
			p[j] = temp;    // reset the temp value
		}
	}

	PrintInsert(p);
}