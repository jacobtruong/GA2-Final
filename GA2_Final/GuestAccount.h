#pragma once
#include "Customer.h"
#include "Item.h"

#define GUESTMAXRENT 2

class GuestAccount : public Customer
{
private:

public:
	GuestAccount();
	GuestAccount(string id, string name, string address, string phone);
	GuestAccount(string id, string name, string address, string phone, int return_count);
	GuestAccount(string id, string name, string address, string phone, int num_borrowed, int return_count, vector<string> borrowed_items);
	~GuestAccount();

	bool borrowing(Item* item);
	bool returning(Item* item);

	void writeToFile(string filename);

	friend ostream& operator<< (ostream& out, const GuestAccount& csm);
};