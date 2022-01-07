#include "Item.h"

Item::Item() {
	this->id = "";
	this->title = "";
	this->loan_type = 1;
	this->stock = 0;
	this->rental_fee = rental_fee;
	this->status = false;
}

Item::Item(string id, string title, int loan_type, int stock, float rental_fee) {
	this->id = id;
	this->title = title;
	this->loan_type = loan_type;
	this->stock = stock;
	this->rental_fee = rental_fee;
	this->status = false;
}

Item::~Item() {

}

void Item::setID(string id) {
	this->id = id;
}

void Item::setTitle(string title) {
	this->title = title;
}

void Item::setLoanType(int loan_type) {
	this->loan_type = loan_type;
}

void Item::setStock(int stock) {
	this->stock = stock;
}

void Item::setRentalFee(float rental_fee) {
	this->rental_fee = rental_fee;
}


//void Item::setRentalType(string rental_type) {
//	this->rental_type = rental_type;
//}

void Item::setAll(string id, string title, string rental_type, int loan_type, int stock, float rental_fee) {
	this->id = id;
	this->title = title;
	this->loan_type = loan_type;
	this->stock = stock;
	this->rental_fee = rental_fee;
	this->status = status;
	this->rental_type = rental_type;
}

string Item::getID() {
	return this->id;
}

string Item::getTitle() {
	return this->title;
}

int Item::getLoanType() {
	return this->loan_type;
}

int Item::getStock() {
	return this->stock;
}

float Item::getRentalFee() {
	return this->rental_fee;
}

string Item::getRentalType() {
	return rental_type;
}

bool Item::borrowing()
{
	if ((!this->status) && (getStock() != 0)) {
		this->status = true;
	}
	return this->status;
}

bool Item::returning()
{
	if (this->status)	this->status = false;
	return !this->status;
}


