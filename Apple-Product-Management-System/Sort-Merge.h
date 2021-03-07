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
		puts("Insertion Successful connection to database (Merge) !!! ");

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


void Merge(Products* pr, int low, int mid, int high)
{
	cout << "Hello Inside Merge " << endl;
	//
	//Products* TempArr;
	//TempArr = new (nothrow) Products[totalRows];
	//int i;
	//int leftEnd = mid - 1;
	//int tempPos = left;
	//int numElements = right - left + 1;

	//while (left <= leftEnd && mid <= right)
	//{
	//	cout << "while (left <= leftEnd && mid <= right) " << endl;

	//	if (pr[left].price <= pr[mid].price){
	//		TempArr[tempPos++] = pr[left++];
	//	cout << "if (pr[left].price <= pr[mid].price) " << endl;
	//}
	//	else {
	//		TempArr[tempPos++] = pr[mid++];

	//	}
	//}

	//while (left <= mid)
	//{
	//	cout << "while (left <= mid)" << endl;

	//	TempArr[tempPos++]  = pr[left++] ;
	//}
	//while (mid <= right)
	//{
	//	cout << "while (mid <= right)" << endl;

	//	TempArr[tempPos++]  = pr[mid++] ;
	//}
	//for (i = 0; i < totalRows; i++, right++)
	//{
	//	pr[right]  = TempArr[right] ;
	//}

	//cout << "End Merge" << endl;


	//free(TempArr);
	//

	int size = high - low + 1;
	Products* tempArr = new (nothrow) Products[totalRows];
	int mergepos = 0;
	int leftpos = low;
	int rightpos = mid + 1;

	while (leftpos <= mid && rightpos <= high)
	{
		if (pr[leftpos].price < pr[rightpos].price)
			tempArr[mergepos++] = pr[leftpos++];
		else
			tempArr[mergepos++] = pr[rightpos++];
	}
	while (leftpos <= mid)
	{
		tempArr[mergepos++] = pr[leftpos++];
	}
	while (rightpos <= high)
	{
		tempArr[mergepos++] = pr[rightpos++];
	}
	//for (int i = 0; i < totalRows; i++, high--)
	//{
	//	pr[high] = tempArr[high];
	//}
	assert(mergepos == size);

	for (mergepos = 0; mergepos < size; ++mergepos)
	{
		pr[low + mergepos] = tempArr[mergepos];
	}
	free(tempArr);
}

void MergeSort(Products* pr, int low, int high)
{
	cout << "Hello Inside Merge Sort" << endl;

	//int mid;

	//if (left < right)
	//{
	//	mid = (left + right) / 2;

	//	// Recursive Function
	//	MergeSort(pr, left, mid);
	//	MergeSort(pr, mid + 1, right);
	//	cout << "Hello Going to Merge" << endl;
	//	Merge(pr, left, mid + 1, right); 

	//}
	if (low < high)
	{
		int mid = (low + high) / 2;
		cout << pr;
		MergeSort(pr, low, mid);
		MergeSort(pr, mid + 1, high);
		Merge(pr, low, mid, high);
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
