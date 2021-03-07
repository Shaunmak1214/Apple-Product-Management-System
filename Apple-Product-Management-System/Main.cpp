#include "db.h"
#include "list.h"
#include "searchName.h"
#include "searchId.h"
#include "Sort-Insertion.h"
#include "Sort-Selection.h"
#include "Sort-Merge.h"
#include <mysql.h>

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

void storeAllList();
void storeIdList();
void storeNameList();
void insert(string name, string category, string price, string colors);
void update(string id, string name, string category, string price, string colors);
int menu();
void display();
void add();
void edit();
void deleteProduct();
void search();
int int_to_str(int a, int b);

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
	int option;
	linkedList list;
	linkedList idList;
	linkedList nameList;
	//intLinkedList intIdList;

	//Used storeAllList();
	//Used //list.printList(head); //Test output

	//Used storeIdList();
	//idList.printList(idhead); //Test output

	storeNameList();
	//nameList.printList(namehead); //Test output

	cout << "+*********************************************************+" << endl;
	cout << "|                                                         |" << endl;
	cout << "|       WELCOME TO APPLE PRODUCT MANAGEMENT SYSTEM!       |" << endl;
	cout << "|                                                         |" << endl;

	do
	{
		option = menu();
	} while (option != 0);




	//Used /*insert("Iphone 11 Pro", "phone", "4500", "black, grey, space gray, midnight green");*/

	//Used /*update("1", "Iphone 11 Pro", "phone", "4500", "black, grey, space gray, midnight green");*/


	//Used //bubbleSort();
	//Used //searchName(); //Done
	//Used //searchId(); //Done

}

int menu()
{
	int action;

	cout << "+=========================================================+" << endl;
	cout << "|                          MENU                           |" << endl;
	cout << "|=========================================================|" << endl;
	cout << "|             Display product              1              |" << endl;
	cout << "|             Search product               2              |" << endl;
	cout << "|             Add product                  3              |" << endl;
	cout << "|             Edit product                 4              |" << endl;
	cout << "|             Delete product               5              |" << endl;
	cout << "|=========================================================|" << endl;
	//cout << "|             BACK                         9              |" << endl; //use on other menu
	cout << "|             EXIT                         0              |" << endl;
	cout << "+.........................................................+" << endl;
	cout << "Please choose an action above: ";
	cin >> action;
	cout << endl;

	while (action != 1 && action != 2 && action != 3 && action != 4 && action != 5 && action != 9 && action != 0)
	{
		cout << "Invalid choice." << endl << endl;
		cout << "Please enter an valid action: ";
		cin >> action;
	}

	switch (action)
	{
	case 1: display(); break;
	case 2: search(); break;
	case 3: add(); break;
	case 4: edit(); break;
	case 5: deleteProduct(); break;
	case 0: exit(0); break;
	default: cout << "Invalid choice." << endl; exit(1); break;
	}

	return action;
}

void display()
{
	int action;
	linkedList list;

	cout << endl;
	cout << "+-------------------------------------------------------+" << endl;
	cout << "|                   DISPLAY PRODUCT                     |" << endl;
	cout << "|-------------------------------------------------------|" << endl;
	cout << "|         Display all product details         1         |" << endl;
	cout << "|         Sort by Name     (Insertion Sort)   2         |" << endl;
	cout << "|         Sort by Category (Selection Sort)   3         |" << endl;
	cout << "|         Sort by Price    (Merge Sort)       4         |" << endl;
	cout << "|-------------------------------------------------------|" << endl;
	cout << "|         BACK                                9         |" << endl;
	cout << "|         EXIT                                0         |" << endl;
	cout << "+.......................................................+" << endl;
	cout << "Please select your choice: ";
	cin >> action;

	while (action != 1 && action != 2 && action != 3 && action != 4 && action != 9 && action != 0)
	{
		cout << "Invalid choice." << endl << endl;
		cout << "Please enter an valid action: ";
		cin >> action;
	}

	switch (action)
	{
	case 1: storeAllList(); list.printList(head); break;
	case 2: InsertSort(); break;
	case 3: SelectSort(); break;
	case 4: MergeSorting(); break;
	case 9: action = menu(); break;
	case 0: exit(0); break;
	default: cout << "Invalid choice." << endl; exit(1); break;
	}
}

void search()
{
	int action;

	cout << endl;
	cout << "+-----------------------------------------------------+" << endl;
	cout << "|                   SEARCH PRODUCT                    |" << endl;
	cout << "|-----------------------------------------------------|" << endl;
	cout << "|           Search by product ID          1           |" << endl;
	cout << "|           Search by product name        2           |" << endl;
	cout << "|-----------------------------------------------------|" << endl;
	cout << "|           BACK                          9           |" << endl;
	cout << "|           EXIT                          0           |" << endl;
	cout << "+.....................................................+" << endl;
	cout << "Please select your choice: ";
	cin >> action;
	cout << endl;

	while (action != 1 && action != 2 && action != 9 && action != 0)
	{
		cout << "Invalid choice." << endl << endl;
		cout << "Please enter an valid action: ";
		cin >> action;
	}

	switch (action)
	{
	case 1: storeIdList(); searchId(); break;
	case 2: searchName(); break;
	case 9: action = menu(); break;
	case 0: exit(0); break;
	default: cout << "Invalid choice." << endl; exit(1); break;
	}
}

void add()
{
	//insert("Iphone 11 Pro", "phone", "4500", "black, grey, space gray, midnight green");
	//insert("10","PH102", "iPhone 12", "iPhone", "3399.00", "Black, White, Red, Green, Blue");
	string name, category, color;
	double price;

	cout << endl;
	cout << "+---------------------------------------------------+" << endl;
	cout << "                     ADD PRODUCT                     " << endl;
	cout << "+---------------------------------------------------+" << endl;
	cout << "Please fill in the product details  below" << endl << endl;
	cout << "Product name     : ";
	getline(cin, name);
	cin.ignore();
	cout << "Product category : ";
	getline(cin, category);
	cin.ignore();
	cout << "Product price    : "; //Infinity loop?
	cin >> price;
	cout << "Product color    : ";
	getline(cin, color);
	cin.ignore();

	cout << name << category << price << color; //Test output

	
	
}

void edit()
{
	//update("1", "Iphone 11 Pro", "phone", "4500", "black, grey, space gray, midnight green");
}

void deleteProduct()
{
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;
	int qState;
	conn = initConnection();

	string prodId;
	cout << "Enter product ID to delete: ";
	cin >> prodId;

	string query = "select * from products where product_id = '" + prodId + "'";
	const char* q = query.c_str();
	qstate = mysql_query(conn, q);
	res = mysql_store_result(conn);
	int count = mysql_num_fields(res);
	if (!qstate)
	{
		string query1 = "delete from products where product_id = '" + prodId + "'";
		const char* q = query1.c_str();
		qstate = mysql_query(conn, q);
		//res = mysql_store_result(conn);
		//int count = mysql_num_fields(res);
		cout << prodId << "Record Found! Deleted";
	}
}

int int_to_str(int a, int b)
{
	// Convert both the integers to string 
	string s1 = to_string(a);
	string s2 = to_string(b);

	// Concatenate both strings 
	string s = s1 + s2;

	// Convert the concatenated string 
	// to integer 
	int combine = stoi(s);

	cout << combine << endl;

	// return the formed integer 
	return combine;
}