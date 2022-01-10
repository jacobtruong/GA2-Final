#pragma once
#include "Customer.h"
#include "Item.h"

#define MAXRENT 999

class RegularAccount : public Customer
{
private:
	int num_borrowed;
	Item* rental_list[MAXRENT];

public:
	RegularAccount();
	RegularAccount(string id, string name, string address, string phone, string type);
	~RegularAccount();

	bool Borrowing(Item* item);
	bool Returning(Item* item);
};