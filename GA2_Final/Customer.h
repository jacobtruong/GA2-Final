#pragma once
#include <iostream>
#include "Item.h"
#include <Vector>

using namespace std;

class Customer
{
private:
	string id; // Note: Has special format
	string name;
	string address;
	string phone;
	string type;
	int return_count;
	int num_borrowed;
	vector<string> borrowed_items;

public:
	Customer();
	Customer(string id, string name, string address, string phone, string type);
	virtual ~Customer();

	void setID(string id);
	void setName(string name);
	void setAddress(string address);
	void setPhone(string phone);
	void setType(string type);
	void setReturnCount(int return_count);
	void setNumBorrowed(int num_borrowed);
	void setBorrowedItems(vector<string>& item);
	void setAll(string id, string name, string address, string phone, string type);

	string getID();
	string getName();
	string getAddress();
	string getPhone();
	string getType();
	int getReturnCount();
	int getNumBorrowed();
	vector<string>& getBorrowedItems();
	virtual bool borrowing(Item * item) = 0;
	virtual bool returning(Item * item) = 0;

	virtual void writeToFile(string filename);
	virtual void display();
};

