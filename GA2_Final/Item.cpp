#include "Item.h"

Item::Item() {
	//id = "";
	//title = "";
	//rental_type = "";
	//loan_type = 0;
	//stock = 0;
	//rental_fee = 0;
	//status = "";
}

Item::Item(string id, string title, int loan_type, int stock, float rental_fee, string status) {
	//this->id = id;
	//this->title = title;
	//this->loan_type = loan_type;
	//this->stock = stock;
	//this->rental_fee = rental_fee;
	//this->status = status;
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

void Item::setStatus(string status) {
	this->status = status;
}

//void Item::setRentalType(string rental_type) {
//	this->rental_type = rental_type;
//}

void Item::setAll(string id, string title, string rental_type, int loan_type, int stock, float rental_fee, string status) {
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

string Item::getStatus() {
	return this->status;
}

string Item::getRentalType() {
	return rental_type;
}