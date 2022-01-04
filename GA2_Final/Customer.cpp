#include "Customer.h"

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

void Customer::promotion() {

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
