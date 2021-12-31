#pragma once
#include "Customer.h"
#include "Item.h"

#define MAXRENT 999

class RegularAccount
{
private:
	string id; // Note: Has special format
	string name;
	string address;
	string phone;
	Item* rentalList[MAXRENT];

public:
	RegularAccount();
	RegularAccount(string id, string name, string address, string phone, int type);

	void setID(string id);
	void setName(string title);
	void setAddress(string address);
	void setPhone(string phone);

	string getID();
	string getName();
	string getAddress();
	string getPhone();
	
};