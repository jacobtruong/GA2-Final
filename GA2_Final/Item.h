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
	string status;

public:
	Item();
	Item(string id, string title, int loan_type, int stock, float rental_fee, string status);
	virtual ~Item() = 0;

	void setID(string id);
	void setTitle(string title);
	void setLoanType(int loan_type);
	void setStock(int stock);
	void setRentalFee(float rental_fee);
	void setStatus(string status);
	//void setRentalType(string rental_type);
	void setAll(string id, string title, string rental_type, int loan_type, int stock, float rental_fee, string status);

	string getID();
	string getTitle();
	int getLoanType();
	int getStock();
	float getRentalFee();
	string getStatus();
	string getRentalType();
};

