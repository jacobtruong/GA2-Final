#pragma once
#include "Item.h";

class OldMovieRecord : public Item {
private:
	string genre;
public:
	OldMovieRecord();
	OldMovieRecord(string id, string title, string genre, int loan_type, int stock, float rental_fee, bool status);

	void setGenre(string genre);
	string getGenre();
};
