#pragma once
#include "Customer.h"
#include "Item.h"

class VIPAccount : public Customer
{
private:
	int point = 0;
public:
	VIPAccount();
	VIPAccount(string id, string name, string address, string phone);
	VIPAccount(string id, string name, string address, string phone, int return_count, int point);
	VIPAccount(string id, string name, string address, string phone, int num_borrowed, int return_count, int point, vector<string> borrowed_items);
	~VIPAccount();

	void setPoint(int point);
	int getPoint();
	void redeem();

	bool borrowing(Item* item);
	bool returning(Item* item);

	void writeToFile(string filename);
	void display();

	friend ostream& operator<< (ostream& out, const VIPAccount& csm);
};