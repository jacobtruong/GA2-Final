#include "VideoGame.h"

VideoGame::VideoGame() {
	setAll("", "", "Video Game", 0, 0, 0);
}
VideoGame::VideoGame(string id, string title, int loan_type, int stock, float rental_fee) {
	setAll(id, title, "Video Game", loan_type, stock, rental_fee);
	if (stock > 0) {
		this->setStatus(true);
	}
	else {
		this->setStatus(false);
	}
}
VideoGame::~VideoGame() {

}

void VideoGame::writeToFile(string filename) {
	ofstream file;
	file.open(filename, ios::app);
	file << *this;
	file.close();
}

void VideoGame::display() {
	cout << *this;
}

string VideoGame::toStr()
{
	stringstream ss;
	ss << this->getID() << "," << this->getTitle() << "," << this->getRentalType() << "," << this->getLoanType() << "," << this->getStock() << "," << this->getRentalFee() << "," << this->getStatus();
	return ss.str();
}

ostream& operator<< (ostream& out, const VideoGame& item) {
	VideoGame i = item;
	out << i.getID() << "," << i.getTitle() << "," << i.getRentalType() << "," << i.getLoanType() << "," << i.getStock() << "," << i.getRentalFee() << "," << i.getStatus() << endl;

	return out;
}