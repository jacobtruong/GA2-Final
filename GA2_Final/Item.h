#pragma once
#include <iostream>
#include <string>

using namespace std;

class Item {
private:
	string id; // Note: Has special format
	string title;
	string rental_type;
	int loan_type; // 1 means 2-day, 2 means 1-week
	int stock;
	float rental_fee;
	bool status;

public:
	Item();
	Item(string id, string title, int loan_type, int stock, float rental_fee);
	virtual ~Item();

	void setID(string id);
	void setTitle(string title);
	void setLoanType(int loan_type);
	void setStock(int stock);
	void setRentalFee(float rental_fee);
	//void setRentalType(string rental_type);
	void setAll(string id, string title, string rental_type, int loan_type, int stock, float rental_fee);

	string getID();
	string getTitle();
	int getLoanType();
	int getStock();
	float getRentalFee();
	string getRentalType();
	bool borrowing();
	bool returning();
};

