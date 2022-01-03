#include "VIPAccount.h"

VIPAccount::VIPAccount()
{
	setAll("", "", "", "", "VIP");
}

VIPAccount::VIPAccount(string id, string name, string address, string phone, string type)
{
	setAll(id, name, address, phone, "VIP");
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
