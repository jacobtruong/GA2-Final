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

void print_sub_menu_1() {
    cout << "1. Add a new item, update or delete existing item" <<
        endl << "   1 Add a new item" <<
        endl << "   2 Update the existing item" <<
        endl << "   3 Delete the existing item" <<
        endl << "   4 Back to main menu." << endl;
}

void print_sub_menu_2() {
    cout << "2. Add new customer or update an existing customer" <<
        endl << "   1 Add new customer" <<
        endl << "   2 Update an existing customer" <<
        endl << "   3 Back to main menu." << endl;
}

string user_input(string& input) {
    cout << "Choose the action you want to do: ";
    cin >> input;
    return input;
}

int user_input(int& input) {
    cout << "Choose the action you want to do: ";
    cin >> input;
    return input;
}

bool check_user_input_menu(string input) {
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

bool check_user_input_sub_menu_1(int input) {
    if (input > 0 && input <= 4) {
        return true;
    }
    else {
        cout << "Not available. Please choose an action from the menu.";
        return false;
    }
}

bool check_user_input_sub_menu_2(int input) {
    if (input > 0 && input <= 3) {
        return true;
    }
    else {
        cout << "Not available. Please choose an action from the menu.";
        return false;
    }
}

int covert_input(string input) {
    int tmp;
    tmp = stoi(input);
    return tmp;
}

int main(int argc, char* argv[]) {
    print_menu();
    string user_choice;
    int user_choice_int;
    int user_choice_sub_1;
    int user_choice_sub_2;
    while (1) {
        if (check_user_input_menu(user_input(user_choice))) {
            user_choice_int = covert_input(user_choice);
            switch (user_choice_int) {
            case 1:
                print_sub_menu_1();
                if (check_user_input_sub_menu_1(user_input(user_choice_sub_1))) {
                    switch (user_choice_sub_1) {
                    case 1:
                        //1.1 add new item function
                        cout << "opt1.1" << endl;
                        break;
                    case 2:
                        //1.2 Update the existing item function
                        cout << "opt1.2" << endl;
                        break;
                    case 3:
                        //1.3 
                        cout << "opt1.3" << endl;
                        break;
                    default:
                        break;
                    }
                }
                break;
            case 2:
                print_sub_menu_2();
                if (check_user_input_sub_menu_2(user_input(user_choice_sub_2))) {
                    switch (user_choice_sub_2) {
                    case 1:
                        //2.1 Add new customer
                        cout << "opt2.1" << endl;
                        break;
                    case 2:
                        //2.2 Update the existing item function
                        cout << "opt2.2" << endl;
                        break;
                    default:
                        break;
                    }
                }
                break;
            case 3:
                cout << "op3";
                break;
            case 4:
                cout << "op4";
                break;
            case 5:
                cout << "op5";
                break;
            case 6:
                cout << "op6";
                break;
            case 7:
                cout << "op7";
                break;
            case 8:
                cout << "op8";
                break;
            case 9:
                cout << "op9";
                break;
            case 10:
                cout << "op10";
                break;
            }
            cout << "Back to main menu!" << endl;
            print_menu();
        }
        else {
            exit(1);
        }
    }

    return 0;
}