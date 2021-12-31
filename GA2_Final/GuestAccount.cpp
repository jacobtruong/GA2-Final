#include "GuestAccount.h"

GuestAccount::GuestAccount()
{
	setAll("", "", "", "", "Guest");
}

GuestAccount::GuestAccount(string id, string name, string address, string phone, string type)
{
	setAll(id, name, address, phone, "Guest");
}
