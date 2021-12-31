#include "RegularAccount.h"

RegularAccount::RegularAccount()
{
	setAll("", "", "", "", "Regular");
}

RegularAccount::RegularAccount(string id, string name, string address, string phone, string type)
{
	setAll(id, name, address, phone, "Regular");
}
