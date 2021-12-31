#pragma once
#include "Customer.h"
#include "Item.h"

#define MAXRENT 999
class VIPAccount : public Customer
{
private:
	int point;
	Item* rentalList[MAXRENT];
public:
	VIPAccount();
	VIPAccount(string id, string name, string address, string phone, string type);

	void setPoint(int point);

	int getPoint();
};