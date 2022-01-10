#include "RegularAccount.h"
#include "Item.h"

RegularAccount::RegularAccount()
{
	setAll("", "", "", "", "Regular");
	this->setReturnCount(0);
	this->setNumBorrowed(0);
}

RegularAccount::RegularAccount(string id, string name, string address, string phone)
{
	setAll(id, name, address, phone, "Regular");
	this->setReturnCount(0);
	this->setNumBorrowed(0);
}

RegularAccount::RegularAccount(string id, string name, string address, string phone, int return_count) {
	setAll(id, name, address, phone, "Regular");
	setReturnCount(return_count);
	this->setNumBorrowed(0);
}

RegularAccount::RegularAccount(string id, string name, string address, string phone, int num_borrowed, int return_count, vector<Item> borrowed_items) {
	setAll(id, name, address, phone, "Regular");
	setNumBorrowed(num_borrowed);
	setReturnCount(return_count);
	setBorrowedItems(borrowed_items);
}

RegularAccount::~RegularAccount()
{
}

bool RegularAccount::borrowing(Item* item)
{
	// Check if item could be borrowed, if so return true
	if (item->getStatus()) {
		if (!(item->borrowing())) {
			cout << "Unexpected error with borrowing process!\n";
			return false;
		}
		cout << "Regular Member " << this->getName() << " (" << this->getID() << ")" << " has successfully borrowed item " << item->getTitle() << " (" << item->getID() << ")" << endl;
		this->getBorrowedItems().push_back(*item);
		setNumBorrowed(getNumBorrowed() + 1);
		return true;
	}
	else { // if status is unavailable, print error and return false
		cout << "Item " << item->getTitle() << " (" << item->getID() << ")" << " is not available!" << endl;
		return false;
	}
}

bool RegularAccount::returning(Item* item)
{
	// Check if the member has borrowed this item, return the item
	for (int i = 0; i < this->getBorrowedItems().size(); i++) {
		if (item->getID() == getBorrowedItems().at(i).getID()) {
			if (!(item->returning())) {
				cout << "Unexpected error with returning process!\n";
				return false;
			}
			getBorrowedItems().erase(getBorrowedItems().begin() + i);
			cout << "Regular Member " << this->getName() << " (" << this->getID() << ")" << " has sucessfully returned item " << item->getTitle() << " (" << item->getID() << ")" << endl;
			setNumBorrowed(getNumBorrowed() - 1);
			return true;
		}
	}
	// If item was not found to have been borrowed, print error and return false
	cout << "Regular Member " << this->getName() << " (" << this->getID() << ")" << " did not borrow item " << item->getTitle() << " (" << item->getID() << ")" << endl;
	return false;
}

ostream& operator<<(ostream& out, const RegularAccount& csm)
{
	// TODO: insert return statement here
	return out;
}
