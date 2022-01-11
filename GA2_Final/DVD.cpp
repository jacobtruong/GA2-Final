#include "DVD.h"

// DVD's Contructor implementation
DVD::DVD() {
	setAll("", "", "DVD", 0, 0, 0);
}

DVD::DVD(string id, string title, string genre, int loan_type, int stock, float rental_fee) {
	setAll(id, title, "DVD", loan_type, stock, rental_fee);
	this->genre = genre;
	if (stock > 0) {
		this->setStatus(true);
	}
	else {
		this->setStatus(false);
	}
}

// DVD's Detructor implementation 
DVD::~DVD() {
}

// set function
void DVD::setGenre(string genre) {
	this->genre = genre;
}

// get function
string DVD::getGenre() {
	return genre;
}

// write to file function
void DVD::writeToFile(string filename) {
	ofstream file;
	file.open(filename, ios::app);
	file << *this;
	file.close();
}

// Display DVD item on the console
void DVD::display() {
	cout << "Item: " << endl;
	cout << "- ID: " << getID() <<
		endl << "- Type: " << getTitle() <<
		endl << "- Loan Type: ";
	if (getLoanType() == 1) {
		cout << "2-day" << endl;
	}
	else {
		cout << "1-week" << endl;
	}
		cout << "- Genre: " << this->getGenre() <<
		endl << "- Stock: " << getStock() <<
		endl << "- Rental Fee: " << getRentalFee() << " USD" <<
		endl << "- Status: ";
	if (getStatus()) {
		cout << "True" << endl;
	}
	else {
		cout << "False" << endl;
	}
	cout << "\n";
}

string DVD::toStr()
{
	stringstream ss;
	ss << this->getID() << "," << this->getTitle() << "," << this->getRentalType() << "," << this->getGenre() << "," << this->getLoanType() << "," << this->getStock() << "," << this->getRentalFee() << "," << this->getStatus();
	return ss.str();
}

// Operator Declaration
ostream& operator<< (ostream& out, const DVD& item) {
	DVD i = item;
	out << i.getID() << "," << i.getTitle() << "," << i.getRentalType() << "," << i.getGenre() << "," << i.getLoanType() << "," << i.getStock() << "," << i.getRentalFee() << "," << i.getStatus() << endl;
	return out;
}