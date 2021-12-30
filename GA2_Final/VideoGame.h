#pragma once
#include "Item.h"

class VideoGame : public Item {
public:
	VideoGame();
	VideoGame(string id, string title, int loan_type, int stock, float rental_fee, string status);
	~VideoGame();
};
