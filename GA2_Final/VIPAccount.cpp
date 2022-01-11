#include "VIPAccount.h"

VIPAccount::VIPAccount()
{
	setAll("", "", "", "", "VIP");
	this->setReturnCount(0);
	this->setNumBorrowed(0);
	this->point = 0;
}

VIPAccount::VIPAccount(string id, string name, string address, string phone)
{
	setAll(id, name, address, phone, "VIP");
	this->setReturnCount(0);
	this->setNumBorrowed(0);
	this->point = 0;
}

VIPAccount::VIPAccount(string id, string name, string address, string phone, int return_count, int point) {
	setAll(id, name, address, phone, "VIP");
	setReturnCount(return_count);
	this->setNumBorrowed(0);
	this->point = point;
}

VIPAccount::VIPAccount(string id, string name, string address, string phone, int num_borrowed, int return_count, int point, vector<string> borrowed_items) {
	setAll(id, name, address, phone, "VIP");
	setNumBorrowed(num_borrowed);
	setReturnCount(return_count);
	setBorrowedItems(borrowed_items);
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

void VIPAccount::redeem()
{
}

bool VIPAccount::borrowing(Item* item)
{
	// Check if item could be borrowed, if so return true
	if (item->getStatus()) {
		if (!(item->borrowing())) {
			cout << "Unexpected error with borrowing process!\n";
			return false;
		}
		cout << "VIP Member " << this->getName() << " (" << this->getID() << ")" << " has successfully borrowed item " << item->getTitle() << " (" << item->getID() << ")" << endl;
		this->getBorrowedItems().push_back(item->getID());
		setNumBorrowed(getNumBorrowed() + 1);
		return true;
	}
	else { // if status is unavailable, print error and return false
		cout << "Item " << item->getTitle() << " (" << item->getID() << ")" << " is not available!" << endl;
		return false;
	}
}

bool VIPAccount::returning(Item* item)
{
	// Check if the member has borrowed this item, return the item
	for (int i = 0; i < this->getBorrowedItems().size(); i++) {
		if (item->getID() == this->getBorrowedItems().at(i)) {
			if (!(item->returning())) {
				cout << "Unexpected error with returning process!\n";
				return false;
			}
			getBorrowedItems().erase(getBorrowedItems().begin() + i);
			cout << "VIP Member " << this->getName() << " (" << this->getID() << ")" << " has sucessfully returned item " << item->getTitle() << " (" << item->getID() << ")" << endl;
			setNumBorrowed(getNumBorrowed() - 1);

			// Add rewards point
			this->point += 10;
			return true;
		}
	}
	// If item was not found to have been borrowed, print error and return false
	cout << "Regular Member " << this->getName() << " (" << this->getID() << ")" << " did not borrow item " << item->getTitle() << " (" << item->getID() << ")" << endl;
	return false;
}

void VIPAccount::writeToFile(string filename) {
	ofstream file;
	file.open(filename, ios::app);
	file << *this;
	file.close();
}

void VIPAccount::display() {
	cout << "Customer: " << endl;
	cout << "- ID: " << getID() <<
		endl << "- Name: " << getName() <<
		endl << "- Address: " << getAddress() <<
		endl << "- Phone Number: " << getPhone() <<
		endl << "- Account Type: " << getType() <<
		endl << "- Return Count: " << getReturnCount() <<
		endl << "- Number of Items Borrowed: " << getNumBorrowed() <<
		endl << "- Reward Point: " << this->getPoint() << 
		endl << "- Borrowed Items: " << endl;
		for (int i = 0; i < this->getNumBorrowed(); i++) {
			cout << this->getBorrowedItems().at(i) << endl;
		}
}

ostream& operator<<(ostream& out, const VIPAccount& csm)
{
	VIPAccount a = csm;
	out << a.getID() << "," << a.getName() << "," << a.getAddress() << "," << a.getPhone() << "," << a.getType() << "," << a.getReturnCount() << "," << a.getNumBorrowed() << "," << a.getPoint() << ",";

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
