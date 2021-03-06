#include "GuestAccount.h"
#include "Customer.h"

// Guest Account's Contructor Implementation
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

GuestAccount::GuestAccount(string id, string name, string address, string phone, int num_borrowed, int return_count, vector<string> borrowed_items) {
	setAll(id, name, address, phone, "Guest");
	setNumBorrowed(num_borrowed);
	setReturnCount(return_count);
	setBorrowedItems(borrowed_items);
}

// Guest Account's Detructor Implementation
GuestAccount::~GuestAccount()
{
}

// Borrowing Function for Guest Account
bool GuestAccount::borrowing(Item* item)
{
	// Check if it is 2-day item
	if (item->getLoanType() == 1) {
		cerr << "Guest Customer " << this->getName() << " (" << this->getID() << ")" << " cannot borrow item " << item->getTitle() << " (" << item->getID() << ")" << " because it's 2-day item!" << endl;
		return false;
	}

	// Check if the Customer has already borrowed 2 items
	if (this->getNumBorrowed() >= GUESTMAXRENT) {
		cout << "Borrow failed because Guest Customer " << this->getName() << " (" << this->getID() << ")" << " have reached borrow limit (" << GUESTMAXRENT << " items)!" << endl;
		return false;
	}
	
	// Check if item could be borrowed, if so return true
	if (item->getStatus()) {
		if (!(item->borrowing())) {
			cout << "Unexpected error with borrowing process!\n";
			return false;
		}
		cout << "Guest Customer " << this->getName() << " (" << this->getID() << ")" << " has successfully borrowed item " << item->getTitle() << " (" << item->getID() << ")" << endl;
		this->getBorrowedItems().push_back(item->getID());
		setNumBorrowed(getNumBorrowed() + 1);
		return true;
	}
	else { // if status is unavailable, print error and return false
		cout << "Item " << item->getTitle() << " (" << item->getID() << ")" << " is not available!" << endl;
		return false;
	}
}

// Returning Fucntion for Guest Account
bool GuestAccount::returning(Item* item)
{
	// Check if the Customer has borrowed this item, return the item
	for (int i = 0; i < this->getBorrowedItems().size(); i++) {
		if (item->getID() == this->getBorrowedItems().at(i)) {
			if (!(item->returning())) {
				cout << "Unexpected error with returning process!\n";
				return false;
			}
			getBorrowedItems().erase(getBorrowedItems().begin() + i);
			cout << "Guest Customer " << this->getName() << " (" << this->getID() << ")" << " has sucessfully returned item " << item->getTitle() << " (" << item->getID() << ")" << endl;
			setNumBorrowed(getNumBorrowed() - 1);
			setReturnCount(getReturnCount() + 1);
			return true;
		}
	}
	// If item was not found to have been borrowed, print error and return false
	cout << "Guest Customer " << this->getName() << " (" << this->getID() << ")" << " did not borrow item " << item->getTitle() << " (" << item->getID() << ")" << endl;
	return false;
}

// Write to File functions
void GuestAccount::writeToFile(string filename) {
	ofstream file;
	file.open(filename, ios::app);
	file << *this;
	file.close();
}

// Operator Declaration 
ostream& operator<<(ostream& out, const GuestAccount& csm)
{
	GuestAccount a = csm;
	out << a.getID() << "," << a.getName() << "," << a.getAddress() << "," << a.getPhone() << "," << a.getType() << "," << a.getReturnCount() << "," << a.getNumBorrowed() << ",";
	
	for (int i = 0; i < a.getBorrowedItems().size(); i++) {
		out << a.getBorrowedItems().at(i);
		if (i == a.getBorrowedItems().size() - 1) {
			continue;
		}
		else {
			out << ",";
		}
	}

	out << endl;
	return out;
}
