#include "db.h"
#include "list.h"
#include "searchName.h"
#include "searchId.h"
#include "Sort-Insertion.h"
#include "Sort-Selection.h"
#include "Sort-Merge.h"
#include "Hashing.h "
#include <mysql.h>
#include <iostream>
#include <iomanip>
#include <string>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

// Function Declaration
void storeAllList();
void storeIdList();
void storeNameList();
void insert();
void update();
int  menu();
void display();
//void add();
void deleteProduct();
void search();
int int_to_str(int a, int b);
void InsertSort();
void SelectSort();
void MergeSort();

// Global Variables
int qstate;
int columnQState;


/***************************************************/
/*					MAIN FUNCTION				  */	
/*************************************************/
int main()
{
	int option;
	linkedList list;
	linkedList idList;
	linkedList nameList;

	storeNameList();

	cout << "\t";
	for (int i = 0; i < 60; i++) { cout << (char)219; }
	cout << endl;
	cout << "\t" << (char)219 << setw(58) << "                                                         " << (char)219 << endl;
	cout << "\t" << (char)219 << setw(58) << "       WELCOME TO APPLE PRODUCT MANAGEMENT SYSTEM!       " << (char)219 << endl;
	cout << "\t" << (char)219 << setw(58) << "                                                         " << (char)219 << endl;
	cout << "\t";
	for (int i = 0; i < 60; i++) { cout << (char)219; }
	cout << endl;

	do
	{
		option = menu();
	} while (option != 0);

}

/***************************************************/
/*						 MENU					  */
/*************************************************/
int menu()
{
	int action;

	cout << endl;
	cout << "\t";
	for (int i = 0; i < 60; i++) { cout << (char)219; }
	cout << endl;
	cout << "\t" << (char)219 << setw(58) << "                                                         " << (char)219 << endl;
	cout << "\t" << (char)219 << setw(58) << "                          MENU                           " << (char)219 << endl;
	cout << "\t" << (char)219 << setw(58) << "                                                         " << (char)219 << endl;
	cout << "\t";
	for (int i = 0; i < 60; i++) { cout << (char)219; }
	cout << endl;
	cout << "\t" << (char)219 << setw(58) << "                                                         " << (char)219 << endl;
	cout << "\t" << (char)219 << setw(58) << "             Display product              1              " << (char)219 << endl;
	cout << "\t" << (char)219 << setw(58) << "             Search product               2              " << (char)219 << endl;
	cout << "\t" << (char)219 << setw(58) << "             Add product                  3              " << (char)219 << endl;
	cout << "\t" << (char)219 << setw(58) << "             Edit product                 4              " << (char)219 << endl;
	cout << "\t" << (char)219 << setw(58) << "             Delete product               5              " << (char)219 << endl;
	cout << "\t" << (char)219 << setw(58) << "                                                         " << (char)219 << endl;
	cout << "\t";
	for (int i = 0; i < 60; i++) { cout << (char)223; }
	cout << endl;
	cout << "\t" << (char)219 << setw(58) << "             EXIT                         0              " << (char)219 << endl;
	cout << "\t";
	for (int i = 0; i < 30; i++) { cout << (char)254 << " "; }
	cout << endl;

	// Prompt the user enter input
	cout << "\t\tPlease choose an action above: ";
	cin >> action;
	cout << endl;

	// check the user input (avoid invalid input)
	while (action != 1 && action != 2 && action != 3 && action != 4 && action != 5 && action != 9 && action != 0)
	{
		cout << "\t\tInvalid choice." << endl << endl;
		cout << "\t\tPlease enter an valid action: ";
		cin >> action;
	}

	switch (action)
	{
	case 1: display(); break;
	case 2: search(); break;
	case 3: insert(); break;
	case 4: update(); break;
	case 5: deleteProduct(); break;
	case 0: exit(0); break;
	default: cout << "\t\tInvalid choice." << endl; exit(1); break;
	}

	return action;
}


/***************************************************/
/*						DISPLAY					  */
/*************************************************/
void display()
{
	int action;
	linkedList list;

	cout << "\t";
	for (int i = 0; i < 60; i++) { cout << (char)219; }
	cout << endl;
	cout << "\t" << (char)219 << setw(58) << "                                                         " << (char)219 << endl;
	cout << "\t" << (char)219 << setw(29) << "      	    	      DISPLAY PRODUCT	                   " << (char)219 << endl;
	cout << "\t" << (char)219 << setw(58) << "                                                    " << (char)219 << endl;
	cout << "\t";
	for (int i = 0; i < 60; i++) { cout << (char)219; }
	cout << endl;
	cout << "\t" << (char)219 << setw(58) << "                                                        " << (char)219 << endl;
	cout << "\t" << (char)219 << setw(58) << "          Display all product details         1         " << (char)219 << endl;
	cout << "\t" << (char)219 << setw(58) << "          Sort by Name     (Insertion Sort)   2         " << (char)219 << endl;
	cout << "\t" << (char)219 << setw(58) << "          Sort by Category (Selection Sort)   3         " << (char)219 << endl;
	cout << "\t" << (char)219 << setw(58) << "          Sort by Price    (Merge Sort)       4         " << (char)219 << endl;
	cout << "\t" << (char)219 << setw(58) << "" << (char)219 << endl;
	cout << "\t";
	for (int i = 0; i < 60; i++) { cout << (char)223; }
	cout << endl;
	cout << "\t" << (char)219 << setw(58) << "          BACK                                9         " << (char)219 << endl;

	cout << "\t" << (char)219 << setw(58) << "          EXIT                                0         " << (char)219 << endl;
	cout << "\t";
	for (int i = 0; i < 30; i++) { cout << (char)254 << " "; }
	cout << endl;

	cout << "\t\tPlease select your choice: ";
	cin >> action;

	while (action != 1 && action != 2 && action != 3 && action != 4 && action != 9 && action != 0)
	{
		cout << "\t\tInvalid choice." << endl << endl;
		cout << "\t\tPlease enter an valid action: ";
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
	default: cout << "\t\tInvalid choice." << endl; exit(1); break;
	}
}

/***************************************************/
/*						SEARCH					  */
/*************************************************/
void search()
{
	int action;

	cout << "\t";
	for (int i = 0; i < 60; i++) { cout << (char)219; }
	cout << endl;
	cout << "\t" << (char)219 << setw(20) << "                      SEARCH PRODUCT                      " << (char)219 << endl;
	cout << "\t";
	for (int i = 0; i < 60; i++) { cout << (char)219; }
	cout << endl;
	cout << "\t" << (char)219 << setw(58) << "                                                         " << (char)219 << endl;
	cout << "\t" << (char)219 << setw(58) << "             Search by Product ID          1              " << (char)219 << endl;
	cout << "\t" << (char)219 << setw(58) << "             Search by Product Name        2              " << (char)219 << endl;
	cout << "\t" << (char)219 << setw(58) << "             Search by Product Code        3              " << (char)219 << endl;
	cout << "\t" << (char)219 << setw(58) << "             Edit product                  4              " << (char)219 << endl;
	cout << "\t" << (char)219 << setw(58) << "             Delete product                5              " << (char)219 << endl;
	cout << "\t" << (char)219 << setw(58) << "                                                         " << (char)219 << endl;
	cout << "\t";
	for (int i = 0; i < 60; i++) { cout << (char)223; }
	cout << endl;
	cout << "\t" << (char)219 << setw(58) << "             BACK                          9              " << (char)219 << endl;
	cout << "\t" << (char)219 << setw(58) << "             EXIT                          0              " << (char)219 << endl;
	cout << "\t";
	for (int i = 0; i < 30; i++) { cout << (char)254 << " "; }
	cout << endl;

	// Prompt the user enter input
	cout << "\t\tPlease select your choice: ";
	cin >> action;
	cout << endl;

	// check the user input (avoid invalid input)
	while (action != 1 && action != 2 && action != 3 && action != 9 && action != 0)
	{
		cout << "\t\tInvalid choice." << endl << endl;
		cout << "\t\tPlease enter an valid action: ";
		cin >> action;
	}

	switch (action)
	{
	case 1: storeIdList(); searchId(); break;
	case 2: searchName(); break;
	case 3: searchCode(); break;
	case 9: action = menu(); break;
	case 0: exit(0); break;
	default: cout << "\t\tInvalid choice." << endl; exit(1); break;
	}
}


/***************************************************/
/*						 ADD					  */
/*************************************************/


void insert()
{
	string name, category, colors, price;
	int code, preID, id;

	cout << "\t";
	for (int i = 0; i < 60; i++) { cout << (char)219; }
	cout << endl;
	cout << "\t" << (char)219 << setw(58) << "                                                         " << (char)219 << endl;
	cout << "\t" << (char)219 << setw(28) << "                       ADD PRODUCT			   " << (char)219 << endl;
	cout << "\t" << (char)219 << setw(58) << "                                                         " << (char)219 << endl;
	cout << "\t";
	for (int i = 0; i < 60; i++) { cout << (char)219; }
	cout << endl;

	// Prompt user to enter product details
	cout << "\t\tPlease fill in the product details  below" << endl << endl;
	cout << "\t\tProduct name     : ";
	cin.ignore();
	getline(cin, name);
	cout << "\t\tProduct category : ";
	getline(cin, category);
	cout << "\t\tProduct Price : ";
	getline(cin, price);
	cout << "\t\tProduct color    : ";
	getline(cin, colors);


	// create unique ID
	srand(time(NULL));		

	// Set unique code for each category
	if (category == "Accessories") {
		code = 101;
		preID = (rand() % 50000) + 1;	// randomizer generator
		id = int_to_str(code, preID);	// convert id to string

	}
	else if (category == "Laptop") {
		code = 202;
		preID = (rand() % 50000) + 1;
		id = int_to_str(code, preID);
	}
	else if (category == "Phone") {
		code = 303;
		preID = (rand() % 50000) + 1;
		id = int_to_str(code, preID);
	}
	else if (category == "Watch") {
		code = 404;
		preID = (rand() % 50000) + 1;
		id = int_to_str(code, preID);
	}
	else if (category == "Tablet") {
		code = 505;
		preID = (rand() % 50000) + 1;
		id = int_to_str(code, preID);
	}
	else {
		code = 909;
		preID = (rand() % 50000) + 1;
		id = int_to_str(code, preID);
	}

	// Convert id back to string
	string strid = to_string(id);

	// Connect to database
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;
	int qState;
	conn = initConnection();

	if (conn) {
		// Insert Product details into tables
		string insertQ = "INSERT INTO products (`id`, `product_name`, `product_category`, `product_price`, `product_colors`) VALUES ( '" + strid + "', '" + name + "', '" + category + "', '" + price + "', '" + colors + "');";

		cout << insertQ << endl;

		const char* q = insertQ.c_str();
		qState = mysql_query(conn, q);

		if (!qState) {

			cout << "\t\tInsert Successfully" << endl;

		}
		else {

			cout << "\t\tInsert Failed" << endl;

		}

	}
}

// Convert Integer to String and concatenate
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

/***************************************************/
/*						 UPDATE					  */
/*************************************************/

void update()
// Convert Integer to String and concatenate
{
	string id, name, category, color, price;

	cout << "\t";
	for (int i = 0; i < 60; i++) { cout << (char)219; }
	cout << endl;
	cout << "\t" << (char)219 << setw(58) << "                                                         " << (char)219 << endl;
	cout << "\t" << (char)219 << setw(58) << "                   EDIT PRODUCT				" << (char)219 << endl;
	cout << "\t" << (char)219 << setw(58) << "                                                         " << (char)219 << endl;
	cout << "\t";
	for (int i = 0; i < 60; i++) { cout << (char)219; }
	cout << endl;

	cout << "\t\tPlease fill in the product details  below" << endl << endl;

	cin.ignore();
	cout << "\t\tProduct id     : ";
	getline(cin, id);
	cout << "\t\tProduct name     : ";
	getline(cin, name);
	cout << "\t\tProduct category : ";
	getline(cin, category);
	cout << "\t\tProduct Price : ";
	getline(cin, price);
	cout << "\t\tProduct color    : ";
	getline(cin, color);

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
		updateQ += "'" + color + "' ";
		updateQ += "WHERE `id` = '" + id;
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


/***************************************************/
/*					  DELETE					  */
/*************************************************/
//Delete product based on product ID
void deleteProduct()
{
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;
	int qState;
	conn = initConnection();

	cout << endl;
	cout << "\t";
	for (int i = 0; i < 60; i++) { cout << (char)219; }
	cout << endl;
	cout << "\t" << (char)219 << setw(58) << "                                                         " << (char)219 << endl;
	cout << "\t" << (char)219 << setw(20) << "                     DELETE PRODUCT			   " << (char)219 << endl;
	cout << "\t" << (char)219 << setw(58) << "                                                         " << (char)219 << endl;
	cout << "\t";
	for (int i = 0; i < 60; i++) { cout << (char)219; }
	cout << endl;

	string prodId;
	cout << "\t\tEnter product ID to delete: ";
	cin >> prodId;

	//Find the value based on the product ID 
	string query = "select * from products where product_id = '" + prodId + "'";
	const char* q = query.c_str();
	qstate = mysql_query(conn, q);
	res = mysql_store_result(conn);
	int count = mysql_num_fields(res);
	if (!qstate)
	{
		//Delete product query, delete the selected row
		string query1 = "delete from products where product_id = '" + prodId + "'";
		const char* q = query1.c_str();
		qstate = mysql_query(conn, q);
		cout << prodId << "\t\tRecord Found! Deleted";
	}
}

// Store Data into Linked List
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
			}

		}
		else
		{
			cout << "\t\tQuery failed: " << mysql_error(conn) << endl;
		}
	}
	else
	{
		puts("\t\tConnection to database has failed!");
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
			cout << "\t\tQuery failed: " << mysql_error(conn) << endl;
		}
	}
	else
	{
		puts("\t\tConnection to database has failed!");
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
				name += row[2];
				nameList.append(&namehead, name);
			}
		}
		else
		{
			cout << "\t\tQuery failed: " << mysql_error(conn) << endl;
		}
	}
	else
	{
		puts("\t\tConnection to database has failed!");
	}
}
