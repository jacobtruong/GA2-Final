#pragma once
#include "Customer.h"
#include "Item.h"

#define MAXRENT 999
class VIPAccount
{
private:
	string id; // Note: Has special format
	string name;
	string address;
	string phone;
	int point;
	Item* rentalList[MAXRENT];

public:
	VIPAccount();
	VIPAccount(string id, string name, string address, string phone, int type);

	void setID(string id);
	void setName(string title);
	void setAddress(string address);
	void setPhone(string phone);
	void setPoint(int point);

	string getID();
	string getName();
	string getAddress();
	string getPhone();
	int getPoint();
};