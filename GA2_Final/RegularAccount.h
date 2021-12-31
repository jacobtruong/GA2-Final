#pragma once
#include "Customer.h"
#include "Item.h"

#define MAXRENT 999

class RegularAccount : public Customer
{
private:
	Item* rental_list[MAXRENT];

public:
	RegularAccount();
	RegularAccount(string id, string name, string address, string phone, string type);
};