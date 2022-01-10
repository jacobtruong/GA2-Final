#include "OldMovieRecord.h"

OldMovieRecord::OldMovieRecord() {
	setAll("", "", "Old Movie Record", 0, 0, 0);
}
OldMovieRecord::OldMovieRecord(string id, string title, string genre, int loan_type, int stock, float rental_fee) {
	setAll(id, title, "Old Movie Record", loan_type, stock, rental_fee);
	this->genre = genre;
}

OldMovieRecord::~OldMovieRecord() {

}

void OldMovieRecord::setGenre(string genre) {
	this->genre = genre;
}

string OldMovieRecord::getGenre() {
	return genre;
}