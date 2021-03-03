#include "db.h"
#include "list.h"
#include "searchName.h"
#include "searchId.h"
#include "Sort-Insertion.h"
#include <mysql.h>
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

void storeAllList();
void storeIdList();
void storeNameList();
void insert(string name, string category, string price, string colors);
void update(string id, string name, string category, string price, string colors);
void menu();

using namespace std;
int qstate;
int columnQState;

void storeAllList() {

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

//Store product ID into linked list
void storeIdList()
{
	linkedList idList;
	idhead = NULL;
	string id;
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
		qstate = mysql_query(conn, q);
		if (!qstate)
		{
			res = mysql_store_result(conn);
			int numfields = mysql_num_fields(res);
			int i = 0;

			while (row = mysql_fetch_row(res))
			{
				id = "";
				id += row[0];
				idList.append(&idhead, id);
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

//Store product name into linked list
void storeNameList()
{
	linkedList nameList;
	namehead = NULL;
	string name;
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
		qstate = mysql_query(conn, q);
		if (!qstate)
		{
			res = mysql_store_result(conn);
			int numfields = mysql_num_fields(res);
			int i = 0;

			while (row = mysql_fetch_row(res))
			{
				name = "";
				name += row[1];
				nameList.append(&namehead, name);
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
	linkedList idList;
	linkedList nameList;
	//intLinkedList intIdList;

	//Used storeAllList();
	//Used //list.printList(head); //Test output
	storeIdList();
	//idList.printList(idhead); //Test output
	storeNameList();
	//nameList.printList(namehead); //Test output

	cout << "+*********************************************************+" << endl;
	cout << "|                                                         |" << endl;
	cout << "|       WELCOME TO APPLE PRODUCT MANAGEMENT SYSTEM!       |" << endl;
	cout << "|                                                         |" << endl;

	menu();


	

	//Used /*insert("Iphone 11 Pro", "phone", "4500", "black, grey, space gray, midnight green");*/

	//Used /*update("1", "Iphone 11 Pro", "phone", "4500", "black, grey, space gray, midnight green");*/

	//InsertSort();
	//bubbleSort();

	//searchName(); //Done
	searchId();

}

void menu()
{
	int action;
	linkedList list;

	cout << "|=========================================================|" << endl;
	cout << "|                          MENU                           |" << endl;
	cout << "|=========================================================|" << endl;
	cout << "|             Display all products         1              |" << endl;
	cout << "|             Add product                  2              |" << endl;
	cout << "|             Edit product                 3              |" << endl;
	cout << "|             Delete product               4              |" << endl;
	cout << "|             Search product               5              |" << endl;
	cout << "|=========================================================|" << endl;
	//cout << "|             BACK                         9              |" << endl; //use on other menu
	cout << "|             EXIT                         0              |" << endl;
	cout << "+.........................................................+" << endl;
	cout << "Please choose an action above: ";
	cin >> action;

	while (action != 1 && action != 2 && action != 3 && action != 4 && action != 5 && action != 9 && action != 0)
	{
		cout << "Invalid choice." << endl << endl;
		cout << "Please enter an valid action: ";
		cin >> action;
	}

	switch (action)
	{
		case 1: storeAllList(); list.printList(head); break;
		case 2: insert("Iphone 11 Pro", "phone", "4500", "black, grey, space gray, midnight green"); break;
		case 3: update("1", "Iphone 11 Pro", "phone", "4500", "black, grey, space gray, midnight green"); break;
		case 4: break;
		case 5: break;
		case 0: break;
		default: cout << "Invalid choice." << endl; break;
	}
}