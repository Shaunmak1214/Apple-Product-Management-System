#include <mysql.h>
#include <iostream>

MYSQL* initConnection() {

	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, "remotemysql.com", "mMIOP5Me5n", "0aEgsAQYEI", "mMIOP5Me5n", 3306, NULL, 0);

	return conn; 

}