#include "VIPAccount.h"

VIPAccount::VIPAccount()
{
	setAll("", "", "", "", "VIP");
	this->point = 0;
}


VIPAccount::VIPAccount(string id, string name, string address, string phone, string type, int point)
{
	setAll(id, name, address, phone, "VIP");
	this->point = point; 
}

VIPAccount::~VIPAccount()
{
}

void VIPAccount::setPoint(int point)
{
	this->point = point;
}

int VIPAccount::getPoint()
{
	return this->point;
}

void VIPAccount::VIP_award()
{
}
