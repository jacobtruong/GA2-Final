#include "RegularAccount.h"
#include "Item.h"

RegularAccount::RegularAccount()
{
	setAll("", "", "", "", "Regular");
	this->num_borrowed = 0;
	for (int i = 0; i < MAXRENT; i++) {
		this->rental_list[i] = NULL;
	}
}

RegularAccount::RegularAccount(string id, string name, string address, string phone, string type)
{
	setAll(id, name, address, phone, "Regular");
	this->num_borrowed = 0;
	for (int i = 0; i < MAXRENT; i++) {
		this->rental_list[i] = NULL;
	}
}

RegularAccount::~RegularAccount()
{
}

bool RegularAccount::Borrowing(Item* item)
{
	// perform the borrowing act using the book object
	if (item->borrowing()) {
		cout << "Member " << this->getID() << " borrowed item: " << item->getTitle() << endl;
		this->rental_list[num_borrowed++] = item;
		item->setStock(item->getStock() - 1);
		return true;
	}
	// if failed to borrow then the book is not available
	cout << "The item id " << item->getID() << " is not available!" << endl;
	return false;
}

bool RegularAccount::Returning(Item* item)
{
	bool found = false;
	// check if the customer really borrow this book
	for (int i = 0; i < MAXRENT; i++) {
		// if an item exists in this borrowList
		if (this->rental_list[i] != NULL) {
			// check that item has the same id with the returning book item
			if (item->getID().compare(this->rental_list[i]->getID()) == 0) {
				found = true;
				break;
			}
		}
	}

	// no book item in the list match the book item, then failed to return the book
	if (!found) {
		cout << "Member " << this->getID() << " does not borrow item: " << item->getTitle() << endl;
		return false;
	}

	// returning function
	if (item->returning()) {
		cout << "Member " << this->getID() << " returned item: " << item->getTitle() << endl;
		this->rental_list[num_borrowed--] = NULL;
		setReturnCount(this->getReturnCount() + 1);
		return true;
	}
	cout << "The item id " << item->getID() << " is available so returning failed!" << endl;
	return false;
}
