#include "VideoGame.h"

VideoGame::VideoGame() {
	setAll("", "", "Video Game", 0, 0, 0, "");
}
VideoGame::VideoGame(string id, string title, int loan_type, int stock, float rental_fee, string status) {
	setAll(id, title, "Video Game", loan_type, stock, rental_fee, status);
}

VideoGame::~VideoGame() {

}