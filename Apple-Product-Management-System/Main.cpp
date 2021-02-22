#include "db.h"
#include <mysql.h>
#include <iostream>
#include <string>

using namespace std;
int qstate;

struct node {

	int data;
	node* next;

};

class ADTstack {

private:
    node* top;

public:
    ADTstack() : top(NULL) {}

    int empty() {

        if (top == NULL) {
            return 1;
        }
        else {
            return 0;
        }

    }

    void push(int num) {

        node* temp;
        temp = new node;
        temp->data = num;
        if (!empty()) {
            temp->next = top;
            top = temp;
        }
        else {
            top = temp;
            top->next = NULL;
        }

    }

    int pop() {

        int num;
        node* temp;

        if (!empty()) {
            temp = top;
            num = top->data;
            top = top->next;
            delete temp;
            return num;
        }

    }

    void display() {

        node* temp;
        temp = top;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

    }
};


int main()
{

    ADTstack list;

	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;
	conn = initConnection();

	if (conn) 
	{
		puts("Successful connection to database!");

		string query = "SELECT * FROM host";
		const char* q = query.c_str();
		qstate = mysql_query(conn, q);
		if (!qstate)
		{
			res = mysql_store_result(conn);
			while (row = mysql_fetch_row(res))
			{
				printf("ID: %s, GoogleId: %s, Name: %s\n", row[0], row[1], row[2]);
                list.push(stoi(row[0]));
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

    list.display();

}
