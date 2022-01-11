#pragma once
#include "Item.h"

class OldMovieRecord : public Item {
private:
	string genre;
	void printOut(ostream& where) const;
public:
	OldMovieRecord();
	OldMovieRecord(string id, string title, string genre, int loan_type, int stock, float rental_fee);
	~OldMovieRecord();

	void setGenre(string genre);
	string getGenre();

	void writeToFile(string filename);
	void display();
	string toStr();

	friend ostream& operator<< (ostream& out, const OldMovieRecord& item);
};
