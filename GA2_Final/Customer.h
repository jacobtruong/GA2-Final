#pragma once
#include <iostream>
#include "Item.h"

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
	Item* rental_list[999];

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
	void setAll(string id, string name, string address, string phone, string type);

	string getID();
	string getName();
	string getAddress();
	string getPhone();
	string getType();
	int getReturnCount();

	virtual bool borrowing(Item* item);
	void promotion();
	void add_account();
	void update_account();
	void print_info();
};

