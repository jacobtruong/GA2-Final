#include "VideoGame.h"

// Video game's contructor implementation 
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

// Video game's detructor implementation
VideoGame::~VideoGame() {
}

// write to File function
void VideoGame::writeToFile(string filename) {
	ofstream file;
	file.open(filename, ios::app);
	file << *this;
	file.close();
}

// display Video game item on the console.
void VideoGame::display() {
	cout << "Item: " << endl;
	cout << "- ID: " << getID() <<
		endl << "- Type: " << getTitle() <<
		endl << "- Loan Type: ";
	if (getLoanType() == 1) {
		cout << "2-day" << endl;
	}
	else {
		cout << "1-week" << endl;
	}
		cout << "- Stock: " << getStock() <<
		endl << "- Rental Fee: " << getRentalFee() << " USD" <<
		endl << "- Status: ";
	if (getStatus()) {
		cout << "True" << endl;
	}
	else {
		cout << "False" << endl;
	}
	cout << "\n";
}

string VideoGame::toStr()
{
	stringstream ss;
	ss << this->getID() << "," << this->getTitle() << "," << this->getRentalType() << "," << this->getLoanType() << "," << this->getStock() << "," << this->getRentalFee() << "," << this->getStatus();
	return ss.str();
}

// Operator declaration 
ostream& operator<< (ostream& out, const VideoGame& item) {
	VideoGame i = item;
	out << i.getID() << "," << i.getTitle() << "," << i.getRentalType() << "," << i.getLoanType() << "," << i.getStock() << "," << i.getRentalFee() << "," << i.getStatus() << endl;

	return out;
}