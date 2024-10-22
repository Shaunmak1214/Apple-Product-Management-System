#pragma once

#include <mysql.h>
#include <string>
#include "db.h"

#include <iostream>
#include <string>

using namespace std;

// get the total row from the database
int getTotal() {

	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_ROW columnNameRow = NULL;
	MYSQL_RES* res;
	MYSQL_RES* columnNameRes;
	conn = initConnection();

	int pstate;
	int numRows = 0;

	if (conn)
	{

		string query = "SELECT * FROM products";
		const char* q = query.c_str();
		pstate = mysql_query(conn, q);
		if (!pstate)
		{
			res = mysql_store_result(conn);
			numRows = mysql_num_rows(res);

			return numRows;		// return total rows

			mysql_close(conn);
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
	return 0;
}
