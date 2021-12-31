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
	Customer(string id, string name, string address, string phone, string type);

	void setID(string id);
	void setName(string name);
	void setAddress(string address);
	void setPhone(string phone);
	void setType(string type);

	string getID();
	string getName();
	string getAddress();
	string getPhone();
	string getType();
};

