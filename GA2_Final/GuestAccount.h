#pragma once
#include "Customer.h"
#include "Item.h"

#define MAXRENT 2

class GuestAccount
{
private:
	string id; // Note: Has special format
	string name;
	string address;
	string phone;
	int type;
	Item* rentalList[MAXRENT];

public:
	GuestAccount();
	GuestAccount(string id, string name, string address, string phone, int type);

	void setID(string id);
	void setName(string title);
	void setAddress(string address);
	void setPhone(string phone);
	void setType(int type);

	string getID();
	string getName();
	string getAddress();
	string getPhone();
	int getType();
};