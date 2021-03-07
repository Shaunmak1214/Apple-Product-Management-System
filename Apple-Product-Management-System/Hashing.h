#pragma once

#include"db.h"
#include<iostream>
#include<string>

using namespace std;

int hashing(int code);

void searchCode()
{
	int hashedCode;
	int productCode;
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;
	int qstate1;

	cout << endl;
	cout << "+---------------------------------------------------+" << endl;
	cout << "                SEARCH BY PRODUCT CODE               " << endl;
	cout << "+---------------------------------------------------+" << endl;
	cout << "	Product Category		Code	  "					<< endl;
	cout << "\t 1. Accessories		-------------------  101	  " << endl;
	cout << "\t 2. Laptop		-------------------  202	  "		<< endl;
	cout << "\t 3. Accessories		-------------------  303	  " << endl;
	cout << "\t 4. Accessories		-------------------  404	  " << endl;
	cout << "\t 5. Accessories		-------------------  505	  " << endl;
	cout << "\t 6. Others		-------------------  909	  "		<< endl;
	cout << "+---------------------------------------------------+" << endl << endl;
	cout << "Enter the product code: ";
	cin >> hashedCode;

	conn = initConnection();

	if (conn)
	{
		string query = "SELECT * FROM products";
		const char* q = query.c_str();
		qstate1 = mysql_query(conn, q);
		if (!qstate1)
		{
			res = mysql_store_result(conn);
			int numfields = mysql_num_fields(res);
			int i = 0;

			//cout << row[2] << endl;
			cout << "Product Hashed by Key Entered : " << endl;
			cout << setw(4) << left << "No" << setw(15) << "Id" << setw(30) << "Name" << setw(15) << "Category" << setw(10) << "Price" << setw(25) << "Colors" << endl;

			while (row = mysql_fetch_row(res))
			{
				int comparedHash = hashing(stoi(row[1]));
				if (comparedHash == hashedCode) {

					cout << setw(4) << (i+1) << setw(15) << row[1] << setw(30) << row[2] << setw(15) << row[3] << setw(10) << row[4] << setw(25) << row[5] << endl;

				}
				i++;
			}
			
			cout << endl;

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

}

int hashing(int code)
{
	int hashCode;
	hashCode = code / 100000;

	return hashCode;
}