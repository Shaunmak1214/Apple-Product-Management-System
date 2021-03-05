#pragma once
/*
  INSERTION SORTING FUNCTION
  - SORT BY PRODUCT NAME
*/

#include<iostream>
#include <mysql.h>
#include <string>
#include "db.h"
#include "Total-Product.h"

using namespace std;

struct Product {
    string id = "";
    string name = "";
    string category = "";
	string price = "";
	string color = "";
};

int total = getTotal();

// list = the amount of total product

Product* getProductData()
{
	int state;

	Product* p;
	p = new (nothrow) Product[total];

	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_ROW columnNameRow = NULL;
	MYSQL_RES* res;
	MYSQL_RES* columnNameRes;
	conn = initConnection();

	if (conn)
	{
		puts("Insertion Successful connection to database !!! ");

		string query = "SELECT * FROM products";
		const char* q = query.c_str();
		state = mysql_query(conn, q);
		if (!state)
		{
			res = mysql_store_result(conn);
			int i = 0;

			while (row = mysql_fetch_row(res))
			{
				p[i].id = row[0];
				p[i].name = row[1];
				p[i].category = row[2];
				p[i].price = row[3];
				p[i].color = row[4];
				 
				cout << "Check while loop" << endl;
				i++;
			}

			mysql_close(conn);
			return p;
			cout << "Check p return " << p << endl;

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

int InsertSort()
{

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

    cout << "Display of Product : " << endl;
    cout << "No\tId\tName\tCategory" << endl;

    for (int i = 0; i < total; i++) 
	{
        cout << i + 1 << "\t" << p[i].id << "\t" << p[i].name << "\t" << p[i].category << endl;
    }

	return 0;
}