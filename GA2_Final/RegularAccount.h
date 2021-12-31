#pragma once
#include "Customer.h"
#include "Item.h"

#define MAXRENT 999

class RegularAccount : public Customer
{
private:
	Item* rentalList[MAXRENT];

public:
	RegularAccount();
	RegularAccount(string id, string name, string address, string phone, int type);

};