#pragma once
#include "Customer.h"
#include "Item.h"

class RegularAccount : public Customer
{
private:

public:
	RegularAccount();
	RegularAccount(string id, string name, string address, string phone);
	RegularAccount(string id, string name, string address, string phone, int return_count);
	RegularAccount(string id, string name, string address, string phone, int num_borrowed, int return_count, vector<string> borrowed_items);
	~RegularAccount();

	bool borrowing(Item* item);
	bool returning(Item* item);

	void writeToFile(string filename);

	friend ostream& operator<< (ostream& out, const RegularAccount& csm);
};