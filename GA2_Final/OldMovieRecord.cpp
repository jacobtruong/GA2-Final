#include "OldMovieRecord.h"

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

OldMovieRecord::~OldMovieRecord() {

}

void OldMovieRecord::setGenre(string genre) {
	this->genre = genre;
}

string OldMovieRecord::getGenre() {
	return genre;
}

void OldMovieRecord::writeToFile(string filename) {
	ofstream file;
	file.open(filename, ios::app);
	file << *this;
	file.close();
}

void OldMovieRecord::display() {
	cout << *this;
}

ostream& operator<< (ostream& out, const OldMovieRecord& item) {
	OldMovieRecord i = item;
	out << i.getID() << "," << i.getTitle() << "," << i.getRentalType() << "," << i.getGenre() << "," << i.getLoanType() << "," << i.getStock() << "," << i.getRentalFee() << "," << i.getStatus() << endl;
	return out;
}