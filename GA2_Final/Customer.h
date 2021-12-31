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
	Item* rentalList[999];

public:
	Customer();
	Customer(string id, string name, string address, string phone, int type);

	void setID(string id);
	void setName(string title);
	void setAddress(string address);
	void setPhone(string phone);
	void setType(int type);

	string getID();
	string getName();
	string getAddress();
	string getPhone();
	string getType();
};

