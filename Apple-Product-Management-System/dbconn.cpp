#include <mysql.h>
#include <iostream>

MYSQL* initConnection() {

	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, "remotemysql.com", "VMuaSaEWtB", "b33DlmSP1D", "VMuaSaEWtB", 3306, NULL, 0);

	return conn; 

}