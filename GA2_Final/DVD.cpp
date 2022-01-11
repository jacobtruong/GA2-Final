#include "DVD.h"

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

DVD::~DVD() {

}

void DVD::setGenre(string genre) {
	this->genre = genre;
}

string DVD::getGenre() {
	return genre;
}

void DVD::writeToFile(string filename) {
	ofstream file;
	file.open(filename, ios::app);
	file << *this;
	file.close();
}

void DVD::display() {
	cout << "Item: " << endl;
	cout << "- ID: " << getID() <<
		endl << "- Type: " << getTitle() <<
		endl << "- Loan Type: " << getLoanType() <<
		endl << "- Genre: " << this->getGenre() <<
		endl << "- Stock: " << getStock() <<
		endl << "- Rental Fee: " << getRentalFee() <<
		endl << "- Status: ";
	if (getStatus()) {
		cout << "True" << endl;
	}
	else {
		cout << "False" << endl;
	}
}

string DVD::toStr()
{
	stringstream ss;
	ss << this->getID() << "," << this->getTitle() << "," << this->getRentalType() << "," << this->getGenre() << "," << this->getLoanType() << "," << this->getStock() << "," << this->getRentalFee() << "," << this->getStatus();
	return ss.str();
}

ostream& operator<< (ostream& out, const DVD& item) {
	DVD i = item;
	out << i.getID() << "," << i.getTitle() << "," << i.getRentalType() << "," << i.getGenre() << "," << i.getLoanType() << "," << i.getStock() << "," << i.getRentalFee() << "," << i.getStatus() << endl;
	return out;
}