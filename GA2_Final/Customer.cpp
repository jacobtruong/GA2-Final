#include "Customer.h"
#include "Item.h"
// Customer's contructor implementation
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

// Customer's detructor implementation
Customer::~Customer()
{
}

// Customer's set functions
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

// Customer' get functions
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

// Write to file function
void Customer::writeToFile(string filename) {
}

// Display on the console function.
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
		cout << "\t+ " << this->getBorrowedItems().at(i) << endl;
	}

	cout << "\n";
}



