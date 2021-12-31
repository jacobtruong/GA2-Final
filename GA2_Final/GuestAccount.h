#pragma once
#include "Customer.h"
#include "Item.h"

#define MAXRENT 2

class GuestAccount : public Customer 
{
private:
	Item* rentalList[MAXRENT];

public:
	GuestAccount();
	GuestAccount(string id, string name, string address, string phone, string type);
};