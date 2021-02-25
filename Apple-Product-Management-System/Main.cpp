#include "db.h"
#include <mysql.h>
#include <iostream>
#include <string>

using namespace std;
int qstate;

struct Node {

	string data;
	Node* next;

};

Node* head;

class linkedList {

	public:
		int data;

	void append(Node** head_ref, string new_data)
	{
		/* 1. allocate node */
		Node* new_node = new Node();

		Node* last = *head_ref; /* used in step 5*/

		/* 2. put in the data */
		new_node->data = new_data;

		/* 3. This new node is going to be
		the last node, so make next of
		it as NULL*/
		new_node->next = NULL;

		/* 4. If the Linked List is empty,
		then make the new node as head */
		if (*head_ref == NULL)
		{
			*head_ref = new_node;
			return;
		}

		/* 5. Else traverse till the last node */
		while (last->next != NULL)
			last = last->next;

		/* 6. Change the next of last node */
		last->next = new_node;
		return;
	}

	void printList(Node* node)
	{
		int counter = 1;

		cout << endl;
		cout << "=============" << endl;
		cout << " Linked List" << endl;
		cout << "=============" << endl;

		while (node != NULL)
		{
			cout << "Index " << counter << ":" << "  " << node->data << endl;
			node = node->next;

			counter++;
		}
	}

};

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
                //list.push(stoi(row[0]));
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
