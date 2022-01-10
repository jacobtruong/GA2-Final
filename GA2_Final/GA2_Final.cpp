#include <iostream>
#include "Item.h"
#include "OldMovieRecord.h"
#include "DVD.h"
#include "VideoGame.h"
#include "Customer.h"
#include "GuestAccount.h"
#include "RegularAccount.h"
#include "VIPAccount.h"

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
        endl << "   1. Add a new item" <<
        endl << "   2. Update the existing item" <<
        endl << "   3. Delete the existing item" <<
        endl << "   4. Back to main menu." << endl;
}

void print_sub_menu_1_2() {
    cout << "2. Update the existing item" <<
        endl << "   1. Update ID for a specific item" <<
        endl << "   2. Update title for a specific item" <<
        endl << "   3. Update Loan Type for a specific item " <<
        endl << "   4. Update Stock for a specific item" <<
        endl << "   5. Update Rental Fee for a specific item" <<
        endl << "   6. Back to main menu" << endl;
}

void print_sub_menu_2() {
    cout << "2. Add new customer or update an existing customer" <<
        endl << "   1. Add new customer" <<
        endl << "   2. Update an existing customer" <<
        endl << "   3. Back to main menu." << endl;
}

void print_sub_menu_2_2() {
    cout << "2. Update an existing customer" <<
        endl << "   1. Update ID for a customer" <<
        endl << "   2. Update Name for a customer" <<
        endl << "   3. Update Address for a customer" <<
        endl << "   4. Update Phone number for a customer" <<
        endl << "   5. Back to main menu." << endl;
}

void print_sub_menu_9() {
    cout << "9. Display group of customers" <<
        endl << "   1. Display all Guest Accounts" <<
        endl << "   2. Display all Regular Accounts" <<
        endl << "   3. Display all VIP Accounts" <<
        endl << "   4. Back to main menu" << endl;
}

void print_sub_menu_10() {
    cout << "10. Search items or customers" <<
        endl << "   1. Search items" <<
        endl << "   2. Search customers" <<
        endl << "   3. Back to main menu" << endl;
}

void print_sub_menu_10_1() {
    cout << "10. Search items " <<
        endl << "   1. Search items by ID" <<
        endl << "   2. Search items by Title" <<
        endl << "   3. Back to main menu" << endl;
}

void print_sub_menu_10_2() {
    cout << "10. Search customers " <<
        endl << "   1. Search customers by ID" <<
        endl << "   2. Search customers by Name" <<
        endl << "   3. Back to main menu" << endl;
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
    else
        return true;
}

bool check_user_input_int(const char* input) {
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] >= '0' && input[i] <= '9') {
            return true;
        }
        else {
            return false;
            break;
        }
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

bool check_user_input_sub_menu_9(int input) {
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

bool check_user_input_sub_menu_2_2(int input) {
    if (input > 0 && input <= 5) {
        return true;
    }
    else {
        cout << "Not available. Please choose an action from the menu.";
        return false;
    }
}

bool check_user_input_sub_menu_1_2(int input) {
    if (input > 0 && input <= 6) {
        return true;
    }
    else {
        cout << "Not available. Please choose an action from the menu.";
        return false;
    }
}

bool check_user_input_sub_menu_10(int input) {
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

bool check_id_customer(const char* id) {
    bool invalid_id = false;
    if (strlen(id) != 4) {
        return invalid_id;
    }
    if (id[0] != 'C') {
        return invalid_id;
    }
    for (int i = 1; i < 4; i++) {
        if (id[i] < '0' || id[i] > '9') {
            return invalid_id;
            break;
        }
    }
    return true;
}

bool check_id_item(const char* id) {
    bool invalid_id = false;
    if (strlen(id) != 9) {
        return invalid_id;
    }
    if (id[0] != 'I') {
        return invalid_id;
    }
    for (int i = 1; i < 4; i++) {
        if (id[i] < '0' || id[i] > '9') {
            return invalid_id;
            break;
        }
    }
    if (id[4] != '-')
        return invalid_id;
    for (int i = 5; i < 9; i++) {
        if (id[i] < '0' || id[i] > '9') {
            return invalid_id;
            break;
        }
    }
    return true;
}

bool check_phone(const char* phone) {
    bool invalid_phone = false;
    int num = strlen(phone);
    if (num == 0)
        return invalid_phone;
    for (int i = 0; i < num; i++) {
        if (phone[i] < '0' || phone[i] > '9') {
            return invalid_phone;
            break;
        }
    }
    return true;
}

bool check_number_of_rentals(const char* num_rental) {
    bool invalid_num_rental = false;
    int num = strlen(num_rental);
    if (num == 0)
        return invalid_num_rental;
    for (int i = 0; i < num; i++) {
        if (num_rental[i] < '0' || num_rental[i] > '9') {
            return invalid_num_rental;
            break;
        }
    }
    return true;
}

bool check_number_of_copies(const char* copies) {
    bool invalid_num_copies = false;
    int num = strlen(copies);
    if (num == 0)
        return invalid_num_copies;
    for (int i = 0; i < num; i++) {
        if (copies[i] < '0' || copies[i] > '9') {
            return invalid_num_copies;
            break;
        }
    }
    return true;
}

bool check_rental_type(string rental_type) {
    bool invalid_rental_type = false;
    if (rental_type.compare("Record") == 0 || rental_type.compare("DVD") == 0 || rental_type.compare("Game") == 0)
        return true;
    else
        return invalid_rental_type;
}

bool check_loan_type(string loan_type) {
    bool invalid_loan_type = false;
    if (loan_type.compare("2-day") == 0 || loan_type.compare("1-week") == 0)
        return true;
    else
        return invalid_loan_type;
}
int main(int argc, char* argv[]) {
    print_menu();
    string user_choice;
    int user_choice_int;
    int user_choice_sub_1;
    int user_choice_sub_2;
    while (1) {
        if (check_user_input_menu(user_input(user_choice))) {
            if (check_user_input_int(user_choice.c_str())) {
                user_choice_int = covert_input(user_choice);
                switch (user_choice_int) {
                case 1:
                    print_sub_menu_1();
                    if (check_user_input_sub_menu_1(user_input(user_choice_int))) {
                        switch (user_choice_int) {
                        case 1:
                            //1.1 add new item function
                            cout << "opt1.1" << endl;
                            break;
                        case 2:
                            //1.2 Update the existing item function
                            print_sub_menu_1_2();
                            if (check_user_input_sub_menu_1_2(user_input(user_choice_int))) {
                                switch (user_choice_int) {
                                case 1:
                                    // 1.2.1 Update ID for a specific item
                                    cout << "Option 1.2.1" << endl;
                                    break;
                                case 2:
                                    // 1.2.2 Update title
                                    cout << "Option 1.2.2" << endl;
                                    break;
                                case 3:
                                    // 1.2.3 Update loan type
                                    cout << "Option 1.2.3" << endl;
                                    break;
                                case 4:
                                    // 1.2.4 Update Stock
                                    cout << "Option 1.2.4" << endl;
                                    break;
                                case 5:
                                    // 1.2.5 Update Rental fee
                                    cout << "Option 1.2.5" << endl;
                                    break;
                                default:
                                    break;
                                }
                            }
                            break;
                        case 3:
                            //1.3 Delete the existing item
                            cout << "opt1.3" << endl;
                            break;
                        default:
                            break;
                        }
                    }
                    break;
                case 2:
                    print_sub_menu_2();
                    if (check_user_input_sub_menu_2(user_input(user_choice_int))) {
                        switch (user_choice_int) {
                        case 1:
                            //2.1 Add new customer
                            cout << "opt2.1" << endl;
                            break;
                        case 2:
                            //2.2 Update the existing item function
                            print_sub_menu_2_2();
                            if (check_user_input_sub_menu_2_2(user_input(user_choice_int))) {
                                switch (user_choice_int) {
                                case 1:
                                    //2.2.1 Update ID customer
                                    cout << "opt2.2.1" << endl;
                                    break;
                                case 2:
                                    //2.2.2 Update Name
                                    cout << "Opt2.2.2" << endl;
                                    break;
                                case 3:
                                    //2.2.3 Update address
                                    cout << "Opt2.2.3" << endl;
                                    break;
                                case 4:
                                    //2.2.4 Update Phone
                                    cout << "Opt2.2.4" << endl;
                                    break;
                                default:
                                    break;
                                }
                            }
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
                    print_sub_menu_9();
                    if (check_user_input_sub_menu_9(user_input(user_choice_int))) {
                        switch (user_choice_int) {
                        case 1:
                            //9.1 Display all Guest Accounts
                            cout << "opt9.1" << endl;
                            break;
                        case 2:
                            //9.2 Display all Regular Accounts
                            cout << "opt9.2" << endl;
                            break;
                        case 3:
                            //9.3 Display all VIP Accounts
                            cout << "Opt9.3" << endl;
                            break;
                        default:
                            break;
                        }
                    }
                    break;
                case 10:
                    print_sub_menu_10();
                    if (check_user_input_sub_menu_10(user_input(user_choice_int))) {
                        switch (user_choice_int) {
                        case 1:
                            //10.1 search items
                            print_sub_menu_10_1();
                            if (check_user_input_sub_menu_10(user_input(user_choice_int))) {
                                switch (user_choice_int) {
                                case 1:
                                    //10.1.1 search items by ID;
                                    cout << "Opt10.1.1" << endl;
                                    break;
                                case 2:
                                    //10.1.2 search items by title
                                    cout << "Opt10.1.2" << endl;
                                    break;
                                default:
                                    break;
                                }
                            }
                            break;
                        case 2:
                            //10.2 search customers
                            print_sub_menu_10_2();
                            if (check_user_input_sub_menu_10(user_input(user_choice_int))) {
                                switch (user_choice_int) {
                                case 1:
                                    //10.2.1 search customers by ID;
                                    cout << "Opt10.2.1" << endl;
                                    break;
                                case 2:
                                    //10.2.2 search customers by title
                                    cout << "Opt10.2.2" << endl;
                                    break;
                                default:
                                    break;
                                }
                            }
                            break;
                        default:
                            break;
                        }
                    }
                    break;
                }    
            }
            cout << "Back to main menu!" << endl;
            print_menu();
        }
        else {
            exit(1);
        }
    }

    return 0;

    //Item* item[4];
    //item[0] = new VideoGame("I001-2022", "God of War", 2, 1, 10);
    //item[1] = new DVD("I002-2022", "007: No Time To Die", "Action", 2, 1, 15);
    //item[2] = new OldMovieRecord("I003-2022", "007: Dr. No", "Action", 2, 1, 20);
    //item[3] = new VideoGame("I004-2022", "The Witcher 3", 1, 1, 30);

    //Customer* c[3];
    //c[0] = new GuestAccount("C001", "Alice", "HCMC", "0909090909");
    //c[1] = new RegularAccount("C002", "Bob", "HCMC", "0909909090");
    //c[2] = new VIPAccount("C003", "Carl", "HCMC", "0909090999");

    //for (int i = 0; i < 3; i++) {
    //    cout << endl;
    //    c[i]->borrowing(item[0]);
    //    c[i]->borrowing(item[1]);
    //    c[i]->borrowing(item[2]);
    //    c[i]->borrowing(item[3]);
    //    cout << endl;
    //    c[i]->returning(item[0]);
    //    c[i]->returning(item[1]);
    //    c[i]->returning(item[2]);
    //    c[i]->returning(item[3]);
    //    cout << endl;
    //}

    //VIPAccount* c2 = (VIPAccount *)c[2];

    //cout << "Current Reward Points of Member " << c[2]->getName() << " (" << c[2]->getID() << ") is: " << c2->getPoint() << endl;
}