#pragma once
#include "Customer.h"
#include "Item.h"

#define MAXRENTFORGUEST 2

class GuestAccount : public Customer 
{
private:
	int num_borrowed;
	Item* rental_list[MAXRENTFORGUEST];

public:
	GuestAccount();
	GuestAccount(string id, string name, string address, string phone, string type);
	~GuestAccount();

	bool Borrowing(Item* item);
	bool Returning(Item* item);
};