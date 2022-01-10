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

