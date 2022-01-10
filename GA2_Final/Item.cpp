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
	if (stock > 0) {
		this->status = true;
	}
	else {
		this->status = false;
	}
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

void Item::setStatus(bool status) {
	this->status = status;
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

string Item::getRentalType() {
	return rental_type;
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

bool Item::getStatus()
{
	return this->status;
}

bool Item::borrowing()
{
	// If item is borrowable and stock > 0, decrease stock by 1
	if ((this->status == true) && (this->stock > 0)) {
		this->stock = this->stock - 1;
		// If stock == 0, set status to unavailable
		if (this->stock == 0) {
			this->status = false;
		}
		return true;
	}
	else {
		return false;
	}
}

bool Item::returning()
{
	// If item was previously unavailable and stock == 0, set status to available
	if (status == false && (stock == 0)) {
		status = true;
	}

	// Increase stock by 1
	stock++;

	return true;
}


