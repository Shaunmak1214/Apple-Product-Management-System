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


// list = the amount of total product

Product* getProductData()
{
	int state;

	Product* p;
	p = new (nothrow) Product[getTotal()];

	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_ROW columnNameRow = NULL;
	MYSQL_RES* res;
	MYSQL_RES* columnNameRes;
	conn = initConnection();

	if (conn)
	{
		puts("Successful connection to database !!! ");
		//string columnNameSql = "SELECT COLUMN_NAME FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = N'products'";
		//const char* columnQ = columnNameSql.c_str();
		//columnQState = mysql_query(conn, columnQ);
		//if (columnQState) {

		//	columnNameRes = mysql_store_result(conn);
		//	columnNameRow = mysql_fetch_row(columnNameRes);

		//}
		string query = "SELECT * FROM products";
		const char* q = query.c_str();
		state = mysql_query(conn, q);
		if (!state)
		{
			res = mysql_store_result(conn);
			int numRows = 0;
			numRows = mysql_num_rows(res);
			int i = 0;

			while (row = mysql_fetch_row(res))
			{
				p[i].id = row[0];
				p[i].name = row[1];
				p[i].category = row[2];
				p[i].price = row[3];
				p[i].color = row[4];

				i++;
			}

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

	return p;
}


int InsertSort()
{
	Product* pd, temp;
	pd = new (nothrow) Product[getTotal()];
	pd = getProductData();

	int total = getTotal();

    for (int i = 0; i < total; i++) {

        //Insertion Sort
        temp = pd[i];  // copy database into temp
        int j = i;    // assign current index to j

        while (j > 0 && temp.name < pd[j - 1].name) { //if 

            pd[j] = pd[j - 1];  //swap the value
            j--;
            pd[j] = temp;    // reset the temp value
        }
    }

    cout << "Display of Product : " << endl;
    cout << "No\tId\tName\tCategory" << endl;

    for (int i = 0; i < total; i++) {

        cout << i + 1 << "\t" << pd[i].id << "\t" << pd[i].name << "\t" << pd[i].category << endl;

    }

	return 0;
}