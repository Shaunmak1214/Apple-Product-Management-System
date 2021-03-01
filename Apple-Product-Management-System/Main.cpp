#include "db.h"
#include "list.h"
#include <mysql.h>
#include "Sort-Insertion.h"
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

void printList();
void insert(string name, string category, string price, string colors);
void update(string id, string name, string category, string price, string colors);

using namespace std;
int qstate;
int columnQState;

void printList() {

	linkedList list;
	head = NULL;
	string datas;

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
		qstate = mysql_query(conn, q);
		if (!qstate)
		{
			res = mysql_store_result(conn);
			int numfields = mysql_num_fields(res);
			int i = 0;
			while (row = mysql_fetch_row(res))
			{
				datas = "";
				//for (int i = 0; i < numfields; i++) {

				//	datas += columnNameRow[i];
				//	datas += row[i];

				//}
				datas += "Product_Id: ";
				datas += row[0];
				datas += ", ";
				datas += "Product_Name: ";
				datas += row[1];
				datas += ", ";
				datas += "Product_Category: ";
				datas += row[2];
				datas += ", ";
				datas += "Product_Price: ";
				datas += row[3];
				datas += ", ";
				datas += "Product_Colors: ";
				datas += row[4];
				list.append(&head, datas);
				//columnNameRow++;
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

}

void insert(string name, string category, string price, string colors) {

	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;
	int qState;
	conn = initConnection();

	if (conn) {

		string insertQ = "INSERT INTO products (`product_name`, `product_category`, `product_price`, `product_colors`) VALUES ( ' ";
		insertQ += name;
		insertQ += "', '";
		insertQ += category;
		insertQ += "', '";
		insertQ += price;
		insertQ += "', '";
		insertQ += colors;
		insertQ += "' );";
		cout << insertQ << endl;

		const char* q = insertQ.c_str();
		qState = mysql_query(conn, q);

		if (!qState) {

			cout << "Insert Successfully" << endl;

		}
		else {

			cout << "Insert Failed" << endl;

		}

	}

}

void update(string id, string name, string category, string price, string colors) {

	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;
	int qState;
	conn = initConnection();

	if (conn) {

		string updateQ = "UPDATE products SET `product_name` = ";
		updateQ += "'" + name + "' ";
		updateQ += ",";
		updateQ += " `product_category` = ";
		updateQ += "'" + category + "' ";
		updateQ += ",";
		updateQ += " `product_price` = ";
		updateQ += "'" + price + "' ";
		updateQ += ",";
		updateQ += " `product_colors` = ";
		updateQ += "'" + colors + "' ";
		updateQ += "WHERE `product_id` = '" + id;
		updateQ += "';";

		cout << updateQ << endl;

		const char* q = updateQ.c_str();
		qState = mysql_query(conn, q);

		if (!qState) {

			cout << "Update Successfully" << endl;

		}
		else {

			cout << "Update Failed" << endl;

		}

	}

}

int main()
{

	linkedList list;

	printList();
	list.printList(head);

	/*insert("Iphone 11 Pro", "phone", "4500", "black, grey, space gray, midnight green");*/

	/*update("1", "Iphone 11 Pro", "phone", "4500", "black, grey, space gray, midnight green");*/

	InsertSort();

}