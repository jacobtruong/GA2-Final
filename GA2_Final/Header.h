#pragma once
#include <iostream>
#include <string>

using namespace std;

//Print menu interface
void print_menu() {
	cout << "Welcome to Genie's video store" <<
		endl << "Enter an option below." <<
		endl << "1. Add a new item, update or delete existing item" <<
		endl << "2. Add new customer or update an existing customer" <<
		endl << "3. Promote an existing customer" <<
		endl << "4. Rent an item" <<
		endl << "5. Return an item" <<
		endl << "6. Display all items" <<
		endl << "7. Display out-of-stock items" <<
		endl << "8. Display all customers" <<
		endl << "9. Display group of customers" <<
		endl << "10. Search items or customers" <<
		endl << "Exit." << endl;
}

// Print sub menu 1 interface
void print_sub_menu_1() {
	cout << "1. Add a new item, update or delete existing item" <<
		endl << " 1. Add a new item" <<
		endl << " 2. Update the existing item" <<
		endl << " 3. Delete the existing item" <<
		endl << " 4. Back to main menu." << endl;
}

// Print sub menu 2 interface
void print_sub_menu_2() {
	cout << "2. Add new customer or update an existing customer" <<
		endl << " 1. Add new customer" <<
		endl << " 2. Update an existing customer" <<
		endl << " 3. Back to main menu." << endl;
}

// Print sub menu 9 interface
void print_sub_menu_9() {
	cout << "9. Display group of customers" <<
		endl << " 1. Display all Guest Accounts" <<
		endl << " 2. Display all Regular Accounts" <<
		endl << " 3. Display all VIP Accounts" <<
		endl << " 4. Back to main menu" << endl;
}

// Print sub menu 10 interface
void print_sub_menu_10() {
	cout << "10. Search items or customers" <<
		endl << " 1. Search items" <<
		endl << " 2. Search customers" <<
		endl << " 3. Back to main menu" << endl;
}

// Take user's string input function
string user_input(string& input) {
	cout << "Choose the action you want to do: ";
	getline(cin, input);
	cout << '\n';
	return input;
}

// Checking the Exit string
bool check_user_input_menu(string input) {
	if (input == "Exit") {
		cout << "The program exits.";
		return false;
	}
	else
		return true;
}

// Checking the valid int input
bool check_user_input_int(string input) {
	for (int i = 0; i < input.size(); i++) {
		if (input[i] >= '0' && input[i] <= '9') {
			return true;
		}
		else {
			return false;
			break;
		}
	}
}

// Checking the value of input for sub menu 1
bool check_user_input_sub_menu_1(int input) {
	if (input > 0 && input <= 4) {
		return true;
	}
	else {
		cout << "Not available. Please choose an action from the menu." << endl;
		return false;
	}
}

// Checking the value of input for sub menu 2
bool check_user_input_sub_menu_2(int input) {
	if (input > 0 && input <= 3) {
		return true;
	}
	else {
		cout << "Not available. Please choose an action from the menu." << endl;
		return false;
	}
}

// Checking the value of input for sub menu 10
bool check_user_input_sub_menu_10(int input) {
	if (input > 0 && input <= 3) {
		return true;
	}
	else {
		cout << "Not available. Please choose an action from the menu." << endl;
		return false;
	}

}

// Validating the customer's ID
bool check_id_customer(string id) {
	bool invalid_id = false;
	// Check the size of the ID
	if (strlen(id.c_str()) != 4) {
		return invalid_id;
	}
	// Check if the first element is 'C'
	if (id[0] != 'C') {
		return invalid_id;
	}
	// Check if the rest of the string is int
	for (int i = 1; i < 4; i++) {
		if (id[i] < '0' || id[i] > '9') {
			return invalid_id;
			break;
		}
	}
	return true;
}

// Validating the item's ID
bool check_id_item(string id) {
	bool invalid_id = false;
	// Check the size of item's ID
	if (strlen(id.c_str()) != 9) {
		return invalid_id;
	}
	// Check if the first element is 'I'
	if (id[0] != 'I') {
		return invalid_id;
	}
	// Check if 2nd to 4th element are int
	for (int i = 1; i < 4; i++) {
		if (id[i] < '0' || id[i] > '9') {
			return invalid_id;
			break;
		}
	}
	// Check if the 5th element is -
	if (id[4] != '-')
		return invalid_id;
	// Check the rest of the string is int
	for (int i = 5; i < 9; i++) {
		if (id[i] < '0' || id[i] > '9') {
			return invalid_id;
			break;
		}
	}
	return true;
}

// Validating phone number
bool check_phone(string phone) {
	bool invalid_phone = false;
	int num = strlen(phone.c_str());
	//check the size of phone number
	if (num <= 0)
		return invalid_phone;
	//check if the string contains only int 
	for (int i = 0; i < num; i++) {
		if (phone[i] < '0' || phone[i] > '9') {
			return invalid_phone;
			break;
		}
	}
	return true;
}

// Validating number of rentals
bool check_number_of_rentals(string num_rental) {
	bool invalid_num_rental = false;
	int num = strlen(num_rental.c_str());
	//check the size of number of rentals
	if (num <= 0)
		return invalid_num_rental;
	//check if the string contains only int 
	for (int i = 0; i < num; i++) {
		if (num_rental[i] < '0' || num_rental[i] > '9') {
			return invalid_num_rental;
			break;
		}
	}
	return true;
}

// Validating number of copies
bool check_number_of_copies(string copies) {
	bool invalid_num_copies = false;
	//check the size of number of copies
	int num = strlen(copies.c_str());
	//check if the string contains only int 
	if (num <= 0)
		return invalid_num_copies;
	for (int i = 0; i < num; i++) {
		if (copies[i] < '0' || copies[i] > '9') {
			return invalid_num_copies;
			break;
		}
	}
	return true;
}

// Validating the rental type
bool check_rental_type(string rental_type) {
	bool invalid_rental_type = false;
	if (rental_type.compare("Record") == 0 || rental_type.compare("DVD") == 0 || rental_type.compare("Game") == 0)
		return true;
	else
		return invalid_rental_type;
}

// Validating the loan type
bool check_loan_type(string loan_type) {
	bool invalid_loan_type = false;
	if (loan_type.compare("2-day") == 0 || loan_type.compare("1-week") == 0)
		return true;
	else
		return invalid_loan_type;
}

