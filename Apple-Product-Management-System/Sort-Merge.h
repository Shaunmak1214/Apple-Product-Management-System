#pragma once

/*
  INSERTION SORTING FUNCTION
  - SORT BY PRODUCT NAME
*/

#include<iostream>
#include<iomanip>
#include <mysql.h>
#include <assert.h>
#include "db.h"
#include "product.h"

using namespace std;

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
void Merge(Products* pr, int lpos, int rpos, int rend);
Products* getProductDetails();
void MergeSort(Products* pr, int left, int right);
void PrintProducts(Products* pr);


Products* getProductDetails()
{
	int states;

	Products* pr;
	pr = new (nothrow) Products[totalRows];

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
			cout << "Check p return " << pr << endl;

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
	cout << "Check connection" << endl;

	return 0;
}

void Merge(Products* pr, int lpos, int rpos, int rend)
{
	int lend, numElements, tempPos;

	Products* tempArr;
	tempArr = new (nothrow) Products[totalRows];

	lend = rpos - 1;
	tempPos = lpos;
	numElements = rend - lpos + 1;

	while (lpos <= lend && rpos <= rend)
	{
		double leftPrice = stod(pr[lpos].price);
		double rightPrice = stod(pr[rpos].price);

		if (leftPrice <= rightPrice) {
			tempArr[tempPos++] = pr[lpos++];
		}
		else {
			tempArr[tempPos++] = pr[rpos++];
		}

		while (lpos <= lend)
		{
			tempArr[tempPos++] = pr[lpos++];
		}
		while (rpos <= rend)
		{
			tempArr[tempPos++] = pr[rpos++];
		}
		for (int i = 0; i < numElements; i++)
		{
			pr[rend] = tempArr[rend];
			rend--;
		}
	}

}

void MergeSort(Products* pr, int left, int right)
{
	int mid;

	if (left < right)
	{
		mid = (left + right) / 2;

		// Recursive Function
		MergeSort(pr, left, mid);
		MergeSort(pr, mid + 1, right);
		Merge(pr, left, mid + 1, right); 

	}
}

void PrintProducts(Products* pr)
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
void MergeSorting()
{
	Products* pr;
	pr = new (nothrow) Products[totalRows];
	pr = getProductDetails();

	cout << pr[total].price << endl;
	MergeSort(pr, 0, totalRows - 1);

	PrintProducts(pr);

}
