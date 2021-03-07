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

struct Details {
	string id;
	string code;
	string name;
	string category;
	string price;
	string color;
};

int Rows = getTotal();
// list = the amount of total product


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
		puts("Selection Successful connection to database !!! ");

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
			cout << index << endl;
		}
	}

	return index;
}

int SelectSort()
{
	Details* pd, current;
	pd = new (nothrow) Details[Rows];
	pd = getDetails();

	//sortData(&pd[]);

	for (int i = 0; i < Rows - 1; i++)
	{
		int min = selectMin(pd, i);
		//cout << min << endl;

		if (pd[min].category < pd[i].category)
		{
			current = pd[min];
			pd[min] = pd[i];      // swap the position
			pd[i] = current;	  // swap the position

		}
	}

	cout << "Product Sorted By Category : " << endl;
	cout << endl;
	cout << "=======================================================================================================================" << endl;
	cout << setw(5) << left << "No" << setw(6) << "Id" << setw(11) << "Code" << setw(30) << "Name" << setw(15) << "Category" << setw(10) << "Price" << setw(25) << "Colors" << endl;
	cout << "=======================================================================================================================" << endl;

	for (int i = 0; i < Rows; i++)
	{
		cout << setw(5) << i + 1 << setw(6) << pd[i].id << setw(11) << pd[i].code << setw(30) << pd[i].name << setw(15) << pd[i].category << setw(10) << pd[i].price << setw(25) << pd[i].color << endl;
	}

	return 0;
}
