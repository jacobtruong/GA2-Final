#include "Customer.h"
#include "Item.h"

Customer::Customer()
{
	this->id = "";
	this->name = "";
	this->address = "";
	this->phone = "";
	this->type = "";
	this->return_count = 0;
	this->num_borrowed = 0;
}

Customer::Customer(string id, string name, string address, string phone, string type)
{
	this->id = id;
	this->name = name;
	this->address = address;
	this->phone = phone;
	this->type = type;
	this->return_count = 0;
	this->num_borrowed = 0;
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

void Customer::setBorrowedItems(vector<string>& item)
{
	this->borrowed_items = item;
}

void Customer::setAll(string id, string name, string address, string phone, string type)
{
	this->id = id;
	this->name = name;
	this->address = address;
	this->phone = phone;
	this->type = type;
}

void Customer::setNumBorrowed(int num_borrowed)
{
	this->num_borrowed = num_borrowed;
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

int Customer::getNumBorrowed()
{
	return this->num_borrowed;
}

vector<string>& Customer::getBorrowedItems() {
	return this->borrowed_items;
}

void Customer::writeToFile(string filename) {
}

void Customer::display() {
	cout << "Customer: " << endl;
	cout << "- ID: " << getID() <<
		endl << "- Name: " << getName() <<
		endl << "- Address: " << getAddress() <<
		endl << "- Phone Number: " << getPhone() <<
		endl << "- Account Type: " << getType() <<
		endl << "- Return Count: " << getReturnCount() <<
		endl << "- Number of Items Borrowed: " << getNumBorrowed() <<
		endl << "- Borrowed Items: " << endl;
	for (int i = 0; i < this->getNumBorrowed(); i++) {
		cout << "\t\t" << "+ " << this->getBorrowedItems().at(i) << endl;
	}
	cout << "\n";
}

// I think promote 
//void Customer::promotion() {
//	if (this->getType() == "Guest" && this->getReturnCount() >= 3) {
//		this->setType("Regular");
//		cout << "Account " << this->getID() << " " << this->getName() << " is promoted to Regular Account." << endl;
//		this->setReturnCount(0);
//	}
//	else {
//		cout << "Account " << this->getID() << " " << this->getName() << " is not able to be promoted to Regular Account." << endl;
//	}
//
//	if (this->getType() == "Regular" && this->getReturnCount() >= 3) {
//		this->setType("VIP");
//		cout << "Account " << this->getID() << " " << this->getName() << " is promoted to VIP Account." << endl;
//		this->setReturnCount(0);
//	}
//	else {
//		cout << "Account " << this->getID() << " " << this->getName() << " is not able to be promoted to VIP Account." << endl;
//	}
//}

void Customer::add_account()
{
}

void Customer::update_account()
{
}
