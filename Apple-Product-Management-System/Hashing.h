#pragma once

#include<iostream>
#include<string>
using namespace std;

int hashing(int code);

void searchCode()
{
	int hashedCode;
	int productCode;

	cout << endl;
	cout << "+---------------------------------------------------+" << endl;
	cout << "                SEARCH BY PRODUCT CODE               " << endl;
	cout << "+---------------------------------------------------+" << endl;
	cout << "	Product Category						Code	  " << endl;
	cout << "\t 1. Accessories		-------------------  101	  " << endl;
	cout << "\t 2. Laptop			-------------------  202	  " << endl;
	cout << "\t 3. Accessories		-------------------  303	  " << endl;
	cout << "\t 4. Accessories		-------------------  404	  " << endl;
	cout << "\t 5. Accessories		-------------------  505	  " << endl;
	cout << "\t 6. Others			-------------------  909	  " << endl;
	cout << "+---------------------------------------------------+" << endl << endl;
	cout << "Enter the product code: ";
	cin >> productCode;

	// User hashedCode
	hashedCode = hashing(productCode);

	// search from database
	// if hashed == hashedCode
	// display by linked list

}

int hashing(int code)
{
	int hashCode;
	hashCode = code / 100000;

	return hashCode;
}