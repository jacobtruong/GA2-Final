#include "Customer.h"
#include "Item.h"

Customer::Customer()
{
	this->id = "";
	this->name = "";
	this->address = "";
	this->phone = "";
	this->type = "";
}

Customer::Customer(string id, string name, string address, string phone, string type)
{
	this->id = id;
	this->name = name;
	this->address = address;
	this->phone = phone;
	this->type = type;
}

Customer::~Customer()
{
}

void Customer::setID(string id)
{
	this->id = id;
}

void Customer::setName(string name)
{
	this->name = name;
}

void Customer::setAddress(string address)
{
	this->address = address;
}

void Customer::setPhone(string phone)
{
	this->phone = phone;
}

void Customer::setType(string type)
{
	this->type = type;
}

void Customer::setReturnCount(int return_count)
{
	this->return_count = return_count;
}

void Customer::setAll(string id, string name, string address, string phone, string type)
{
	this->id = id;
	this->name = name;
	this->address = address;
	this->phone = phone;
	this->type = type;
}

string Customer::getID()
{
	return this->id;
}

string Customer::getName()
{
	return this->name;
}

string Customer::getAddress()
{
	return this->address;
}

string Customer::getPhone()
{
	return this->phone;
}

string Customer::getType()
{
	return this->type;
}

int Customer::getReturnCount()
{
	return this->return_count;
}

bool Customer::borrowing(Item* item)
{
	// perform the borrowing act using the book object
	if (item->borrowing()) {
		cout << "Member " << this->getID() << " borrowed book item: " << item->getTitle() << endl;
		this->rental_list[num_borrowed++] = item;
		item->setStock(item->getStock() - 1);
		return true;
	}

	// if failed to borrow then the book is not available
	cout << "The item id " << item->getID() << " is not available!" << endl;
	return false;
}


void Customer::promotion() {
	if (this->getType() == "Guest" && this->getReturnCount() == 3) {
		this->setType("Regular");
		cout << "Account " << this->getID() << " " << this->getName() << " is promoted to Regular Account." << endl;
		this->setReturnCount(0);
	}
	else {
		cout << "Account " << this->getID() << " " << this->getName() << " is not able to be promoted to Regular Account." << endl;
	}

	if (this->getType() == "Regular" && this->getReturnCount() == 3) {
		this->setType("VIP");
		cout << "Account " << this->getID() << " " << this->getName() << " is promoted to VIP Account." << endl;
		this->setReturnCount(0);
	}
	else {
		cout << "Account " << this->getID() << " " << this->getName() << " is not able to be promoted to VIP Account." << endl;
	}
}

void Customer::add_account()
{
}

void Customer::update_account()
{
}

void Customer::print_info()
{
}
