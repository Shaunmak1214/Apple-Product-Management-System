#pragma once

#include <mysql.h>
#include <string>
#include "db.h"

#include <iostream>
#include <string>

using namespace std;

int getTotal();

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
		pstate = mysql_query(conn, q);
		if (!pstate)
		{
			res = mysql_store_result(conn);
			numRows = mysql_num_rows(res);
			cout << "Total NumRows = " << numRows << endl;
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

	return numRows;
}
