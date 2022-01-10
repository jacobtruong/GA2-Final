#include "GuestAccount.h"
#include "Customer.h"

GuestAccount::GuestAccount()
{
	setAll("", "", "", "", "Guest");
	this->setReturnCount(0);
	this->setNumBorrowed(0);
}

GuestAccount::GuestAccount(string id, string name, string address, string phone)
{
	setAll(id, name, address, phone, "Guest");
	this->setReturnCount(0);
	this->setNumBorrowed(0);
}

GuestAccount::GuestAccount(string id, string name, string address, string phone, int return_count) {
	setAll(id, name, address, phone, "Guest");
	setReturnCount(return_count);
	this->setNumBorrowed(0);
}

GuestAccount::GuestAccount(string id, string name, string address, string phone, int num_borrowed, int return_count, vector<Item> borrowed_items) {
	setAll(id, name, address, phone, "Guest");
	setNumBorrowed(num_borrowed);
	setReturnCount(return_count);
	setBorrowedItems(borrowed_items);
}

GuestAccount::~GuestAccount()
{
}

bool GuestAccount::borrowing(Item* item)
{
	// Check if it is 2-day item
	if (item->getLoanType() == 1) {
		cerr << "Guest Member " << this->getName() << " (" << this->getID() << ")" << " cannot borrow item " << item->getTitle() << " (" << item->getID() << ")" << " because it's 2-day item!" << endl;
		return false;
	}

	// Check if the member has already borrowed 2 items
	if (this->getNumBorrowed() >= GUESTMAXRENT) {
		cout << "Borrow failed because Guest Member " << this->getName() << " (" << this->getID() << ")" << " have reached borrow limit (" << GUESTMAXRENT << " items)!" << endl;
		return false;
	}
	
	// Check if item could be borrowed, if so return true
	if (item->getStatus()) {
		if (!(item->borrowing())) {
			cout << "Unexpected error with borrowing process!\n";
			return false;
		}
		cout << "Guest Member " << this->getName() << " (" << this->getID() << ")" << " has successfully borrowed item " << item->getTitle() << " (" << item->getID() << ")" << endl;
		this->getBorrowedItems().push_back(*item);
		setNumBorrowed(getNumBorrowed() + 1);
		return true;
	}
	else { // if status is unavailable, print error and return false
		cout << "Item " << item->getTitle() << " (" << item->getID() << ")" << " is not available!" << endl;
		return false;
	}
}

bool GuestAccount::returning(Item* item)
{
	// Check if the member has borrowed this item, return the item
	for (int i = 0; i < this->getBorrowedItems().size(); i++) {
		if (item->getID() == getBorrowedItems().at(i).getID()) {
			if (!(item->returning())) {
				cout << "Unexpected error with returning process!\n";
				return false;
			}
			getBorrowedItems().erase(getBorrowedItems().begin() + i);
			cout << "Guest Member " << this->getName() << " (" << this->getID() << ")" << " has sucessfully returned item " << item->getTitle() << " (" << item->getID() << ")" << endl;
			setNumBorrowed(getNumBorrowed() - 1);
			return true;
		}
	}
	// If item was not found to have been borrowed, print error and return false
	cout << "Guest Member " << this->getName() << " (" << this->getID() << ")" << " did not borrow item " << item->getTitle() << " (" << item->getID() << ")" << endl;
	return false;
}

ostream& operator<<(ostream& out, const GuestAccount& csm)
{
	// TODO: insert return statement here
	return out;
}
