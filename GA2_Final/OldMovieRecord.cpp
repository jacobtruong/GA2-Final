#include "OldMovieRecord.h"

// Old Movie Record's contructor implementation
OldMovieRecord::OldMovieRecord() {
	setAll("", "", "Old Movie Record", 0, 0, 0);
}
OldMovieRecord::OldMovieRecord(string id, string title, string genre, int loan_type, int stock, float rental_fee) {
	setAll(id, title, "Old Movie Record", loan_type, stock, rental_fee);
	this->genre = genre;
	if (stock > 0) {
		this->setStatus(true);
	}
	else {
		this->setStatus(false);
	}
}

// Old Movie Record's detructor implementation
OldMovieRecord::~OldMovieRecord() {

}

// set functions
void OldMovieRecord::setGenre(string genre) {
	this->genre = genre;
}

string OldMovieRecord::getGenre() {
	return genre;
}

// Write to file functions
void OldMovieRecord::writeToFile(string filename) {
	ofstream file;
	file.open(filename, ios::app);
	file << *this;
	file.close();
}

// Display Old Movie Record on the console
void OldMovieRecord::display() {
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

string OldMovieRecord::toStr()
{
	stringstream ss;
	ss << this->getID() << "," << this->getTitle() << "," << this->getRentalType() << "," << this->getGenre() << "," << this->getLoanType() << "," << this->getStock() << "," << this->getRentalFee() << "," << this->getStatus();
	return ss.str();
}

// Operator Declaration
ostream& operator<< (ostream& out, const OldMovieRecord& item) {
	OldMovieRecord i = item;
	out << i.getID() << "," << i.getTitle() << "," << i.getRentalType() << "," << i.getGenre() << "," << i.getLoanType() << "," << i.getStock() << "," << i.getRentalFee() << "," << i.getStatus() << endl;
	return out;
}