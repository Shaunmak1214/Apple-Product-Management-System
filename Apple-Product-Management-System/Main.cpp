#include "db.h"
#include "list.h"
#include <mysql.h>


#include <iostream>
#include <string>

using namespace std;
int qstate;

int main()
{

	head = NULL;
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;
	conn = initConnection();
	linkedList list;

	if (conn) 
	{
		puts("Successful connection to database !!! ");

		string query = "SELECT * FROM host";
		const char* q = query.c_str();
		qstate = mysql_query(conn, q);
		if (!qstate)
		{
			res = mysql_store_result(conn);
			while (row = mysql_fetch_row(res))
			{
				printf("ID: %s, GoogleId: %s, Name: %s\n", row[0], row[1], row[2]);
				string id = row[2];
				list.append(&head, id);
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


	list.printList(head);

}
