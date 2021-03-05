#pragma once
/*
  INSERTION SORTING FUNCTION
  - SORT BY PRODUCT ID
*/

#include<iostream>
#include <mysql.h>
#include <string>
#include "db.h"
#include "Total-Product.h"

using namespace std;

struct Details {
	string id = "";
	string name = "";
	string category = "";
	string price = "";
	string color = "";

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
				pd[i].name = row[1];
				pd[i].category = row[2];
				pd[i].price = row[3];
				pd[i].color = row[4];

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

int selectMin(int position)
{
	Details* pd;
	pd = new (nothrow) Details[Rows];

	int index = position; // index of the current position
	Details temp;
	temp = pd[position];   // get the value of current position

	for (int i = 0; i < Rows; i++) 
	{
		if (pd[i].category < temp.category) 
		{
			temp = pd[i];  //swap the position 
			index = i;
		}
	}

	return index;
}

// function to swap the the position of two elements
void swap(string* a, string* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sortData(Details* pd[])
{
	Details current;

	for (int i = 0; i < total - 1; i++)
	{
		int min = selectMin(i);

		if (pd[min].category < pd[i].category)
		{
			current = pd[min];
			pd[min] = pd[i];      // swap the position
			pd[i] = current;	  // swap the position
		}
	}
}

int SelectSort()
{
	Details* pd, current;
	pd = new (nothrow) Details[Rows];
	pd = getDetails();

	sortData(&pd[]);

	cout << "Display of Product : " << endl;
	cout << "No\tId\tName\tCategory" << endl;

	for (int i = 0; i < Rows; i++) 
	{
		cout << i + 1 << "\t" << pd[i].id << "\t" << pd[i].name << "\t" << pd[i].category << endl;
	}

	return 0;
}