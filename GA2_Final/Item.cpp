#include "Item.h"

Item::Item()
{
}

Item::Item(string id, string title, int loan_type, int stock, float rental_fee, bool status)
{
}

void Item::setID(string id)
{
	this->id = id;
}

void Item::setTitle(string title)
{
	this->title = title;
}

void Item::setLoanType(int loan_type)
{
	this->loan_type = loan_type;
}

void Item::setStock(int stock)
{
	this->stock = stock;
}

void Item::setRentalFee(float rental_fee)
{
	this->rental_fee = rental_fee;
}

void Item::setStatus(bool status)
{
	this->status = status;
}

string Item::getID()
{
	return this->id;
}

string Item::getTitle()
{
	return this->title;
}

int Item::getLoanType()
{
	return this->loan_type;
}

int Item::getStock()
{
	return this->stock;
}

float Item::getRentalFee()
{
	return this->rental_fee;
}

bool Item::getStatus()
{
	return this->status;
}
