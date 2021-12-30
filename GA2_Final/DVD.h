#pragma once
#include "Item.h"

class DVD : public Item {
private:
	string genre;
public:
	DVD();
	DVD(string id, string title, string genre, int loan_type, int stock, float rental_fee, string status);
	~DVD();

	void setGenre(string genre);
	string getGenre();
};
