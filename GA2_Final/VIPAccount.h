#pragma once
#include "Customer.h"
#include "Item.h"

#define MAXRENT 999

class VIPAccount : public Customer
{
private:
	int point;
	Item* rental_list[MAXRENT];
public:
	VIPAccount();
	VIPAccount(string id, string name, string address, string phone, string type);
	~VIPAccount();

	void setPoint(int point);

	int getPoint();
};