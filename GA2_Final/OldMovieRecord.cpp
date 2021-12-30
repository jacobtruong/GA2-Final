#include "OldMovieRecord.h"

OldMovieRecord::OldMovieRecord() {
	setID("");
	setTitle("");
	setRentalType("Old Movie Record");
}
OldMovieRecord(string id, string title, string genre, int loan_type, int stock, float rental_fee, bool status);

void setGenre(string genre);
string getGenre();