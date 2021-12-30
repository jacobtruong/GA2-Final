#pragma once
#include <iostream>

using namespace std;

class Item {
private:
	string id; // Note: Has special format
	string title;
	string rental_type;
	int loan_type;
	int stock;
	float rental_fee;
	bool status;
public:
	Item();
	Item(string id, string title, int loan_type, int stock, float rental_fee, bool status);
	virtual ~Item() = 0;

	void setID(string id);
	void setTitle(string title);
	void setLoanType(int loan_type);
	void setStock(int stock);
	void setRentalFee(float rental_fee);
	void setStatus(bool status);
	void setRentalType(string rental_type);

	string getID();
	string getTitle();
	int getLoanType();
	int getStock();
	float getRentalFee();
	bool getStatus();
	string getRentalType();
};

