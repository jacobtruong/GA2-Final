#include <iostream>
#include "Item.h"
#include "OldMovieRecord.h"
#include "DVD.h"
#include "VideoGame.h"
#include <string>

using namespace std;

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

string user_input() {
    string input;
    cout << "Choose the action you want to do: ";
    cin >> input;
    return input;
}

bool check_user_input(string input) {
    if (input == "Exit") {
        cout << "The program exits.";
        return false;
    }
    int num = stoi(input);
    if (num > 0 && num <= 10) {
        return true;
    }
    else {
        cout << "Not available. Please choose an action from the menu.";
        return false;
    }
}

int main(int argc, char* argv[]) {
    print_menu();

    if (check_user_input(user_input())) {
        cout << "succes";
    }
    else {
        cout << "fail";
    }
    return 0;
}