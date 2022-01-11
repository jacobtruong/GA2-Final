#pragma once

#include <iostream>
#include <fstream>
#include <ostream>
#include <sstream>
#include <vector>

#include "Item.h"
#include "OldMovieRecord.h"
#include "DVD.h"
#include "VideoGame.h"
#include "Customer.h"
#include "GuestAccount.h"
#include "RegularAccount.h"
#include "VIPAccount.h"
#include "Header.h"

vector<Item*> fetchItems(string filename) {
    ifstream ifile;
    ifile.open(filename);

    vector<Item*> item_list;

    string line, word;

    while (getline(ifile, line)) {
        stringstream ss(line);
        vector<string> words;
        while (getline(ss, word, ',')) {
            words.push_back(word);
        }
        if (words.at(2) == "Video Game") {
            VideoGame* vg = new VideoGame(words.at(0), words.at(1), stoi(words.at(3)), stoi(words.at(4)), stof(words.at(5)));
            item_list.push_back(vg);
        }
        else if (words.at(2) == "DVD") {
            DVD* dvd = new DVD(words.at(0), words.at(1), words.at(3), stoi(words.at(4)), stoi(words.at(5)), stof(words.at(6)));
            item_list.push_back(dvd);
        }
        else if (words.at(2) == "Old Movie Record") {
            OldMovieRecord* omr = new OldMovieRecord(words.at(0), words.at(1), words.at(3), stoi(words.at(4)), stoi(words.at(5)), stof(words.at(6)));
            item_list.push_back(omr);
        }
    }

    return item_list;
}

bool updateFile(string filename, vector<Customer*> &customers) {
    ofstream file;
    file.open(filename, ios::trunc);
    file.close();

    for (Customer* c : customers) {
        c->writeToFile(filename);
    }

    return true;
}

bool updateFile(string filename, vector<Item*>& items) {
    ofstream file;
    file.open(filename, ios::trunc);
    file.close();

    for (Item * i : items) {
        i->writeToFile(filename);
    }

    return true;
}

int search(string id, vector<Item *> &items) {
    int index = 0;
    for (Item * i : items) {
        if (id == i->getID()) {
            return index;
        }
        index++;
    }
    return -1;
}

int search(string id, vector<Customer *>& customers) {
    int index = 0;
    for (Customer * c : customers) {
        if (id == c->getID()) {
            return index;
        }
        index++;
    }
    return -1;
}

string inputItemID() {
    string string_input;
    do {
        cout << "Please input valid item ID (Format: Ixxx-yyyy): ";
        getline(cin, string_input);
    } while (!check_id_item(string_input));
    return string_input;
}

string inputItemTitle() {
    string string_input;
    do {
        cout << "Please input title: ";
        getline(cin, string_input);
    } while (string_input == "");
    return string_input;
}

string inputItemRentalType() {
    string string_input;
    do {
        cout << "Please input item type: ";
        getline(cin, string_input);
    } while (string_input != "Video Game" && string_input != "DVD" && string_input != "Old Movie Record");
    return string_input;
}

string inputItemGenre() {
    string string_input;
    do {
        cout << "Please input genre: ";
        getline(cin, string_input);
    } while (string_input == "");
    return string_input;
}

int inputItemLoanType() {
    string string_input;
    do {
        cout << "Please input valid loan type (1 for 2-day, 2 for 1-week): ";
        getline(cin, string_input);
    } while (!check_user_input_int(string_input) || (stoi(string_input) != 1 && stoi(string_input) != 2));
    return stoi(string_input);
}

int inputItemStock() {
    string string_input;
    do {
        cout << "Please input valid stock number (integer only): ";
        getline(cin, string_input);
    } while (!check_user_input_int(string_input) || (stoi(string_input) < 0));
    return stoi(string_input);
}

float inputItemRentalFee() {
    float float_input;
    do {
        cout << "Please input valid rental fee: ";
        cin >> float_input;
    } while (float_input < 0);
    return float_input;
}

//� The ability to add, update and delete items from the database of stocked items.
    // Add
bool addItem(string filename) {
    // For input validation
    int choice;
    string string_input;

    // Item attributes
    string id, title, genre;
    int type, stock;
    float fee;

    cout << "Please select which type of item you would like to add:" << endl;
    cout << "1. Video Game" << endl;
    cout << "2. DVD" << endl;
    cout << "3. Old Movie Record" << endl;

    do {
        cout << "Your choice: ";
        getline(cin, string_input);
    } while (stoi(string_input) < 1 || stoi(string_input) > 3);
    choice = stoi(string_input);

    cout << endl;

    
    id = inputItemID();
    title = inputItemTitle();

    if (choice != 1) {
        genre = inputItemGenre();
    }
    type = inputItemLoanType();
    stock = inputItemStock();
    fee = inputItemRentalFee();

    // Open file
    ofstream file;
    file.open(filename, ios::app);

    if (choice == 1) {
        VideoGame* vg = new VideoGame(id, title, type, stock, fee);
        file << *vg;
    }
    else if (choice == 2) {
        DVD* dvd = new DVD(id, title, genre, type, stock, fee);
        file << *dvd;
    }
    else {
        OldMovieRecord* omr = new OldMovieRecord(id, title, genre, type, stock, fee);
        file << *omr;
    }

    return true;
}

// Update
bool updateItem(string filename) {
    vector<Item*> items = fetchItems(filename);
    int updating_item_index;
    string string_input;

    cout << "Please enter the ID of the item you want to update: ";
    getline(cin, string_input);

    if (search(string_input, items) != -1) {
        updating_item_index = search(string_input, items);
    }
    else {
        cout << "Item not found in database. Please try again\n";
        return false;
    }

    items.at(updating_item_index)->display();

    cout << "\nPlease re-input all information to update the selected item:\n";
    // Item attributes
    string id, title, genre, rental_type;
    int type, stock;
    float fee;

    id = inputItemID();
    title = inputItemTitle();
    rental_type = inputItemRentalType();

    if (rental_type != "Video Game") {
        genre = inputItemGenre();
    }

    type = inputItemLoanType();
    stock = inputItemStock();
    fee = inputItemRentalFee();

    if (rental_type == "Video Game") {
        VideoGame* vg = new VideoGame(id, title, type, stock, fee);
        items.at(updating_item_index) = vg;
    }
    else if (rental_type == "DVD") {
        DVD* dvd = new DVD(id, title, genre, type, stock, fee);
        items.at(updating_item_index) = dvd;
    }
    else {
        OldMovieRecord* omr = new OldMovieRecord(id, title, genre, type, stock, fee);
        items.at(updating_item_index) = omr;
    }

    updateFile(filename, items);

    return true;
}

// Delete
bool deleteItem(string filename) {
    vector<Item*> items = fetchItems(filename);
    int updating_item_index;
    string string_input;

    cout << "Please enter the ID of the item you want to delete: ";
    getline(cin, string_input);

    if (search(string_input, items) != -1) {
        updating_item_index = search(string_input, items);
    }
    else {
        cout << "Item not found in database. Please try again\n";
        return false;
    }

    items.at(updating_item_index)->display();


    items.at(updating_item_index) = NULL;

    ofstream file;
    file.open(filename, ios::trunc);
    file.close();

    items.erase(items.begin() + updating_item_index);

    for (Item* i : items) {
        i->writeToFile(filename);
    }

    cout << "Item " << string_input << " has been deleted\n";

    return true;
}

string inputCustomerID() {
    string string_input;
    do {
        cout << "Please input valid customer ID (Format: Cxxx): ";
        getline(cin, string_input);
    } while (!check_id_customer(string_input));
    return string_input;
}

string inputCustomerName() {
    string string_input;
    do {
        cout << "Please input customer's name: ";
        getline(cin, string_input);
    } while (string_input == "");
    return string_input;
}

string inputCustomerAddress() {
    string string_input;
    do {
        cout << "Please input customer's address: ";
        getline(cin, string_input);
    } while (string_input == "");
    return string_input;
}

string inputCustomerPhone() {
    string string_input;
    do {
        cout << "Please input customer's phone number: ";
        getline(cin, string_input);
    } while (string_input == "");
    return string_input;
}

string inputCustomerType() {
    string string_input;
    do {
        cout << "Please input customer's account type (Guest, Regular, or VIP): ";
        getline(cin, string_input);
    } while (string_input != "Guest" && string_input != "Regular" && string_input != "VIP");
    return string_input;
}

int inputCustomerPoint() {
    string string_input;
    do {
        cout << "Please input customer's total number reward points: ";
        getline(cin, string_input);
    } while (!check_user_input_int(string_input));
    return stoi(string_input);
}

//void inputCustomerBorrow() {
//    string string_input;
//    do {
//        cout << "How many items are the customer borrowing: ";
//        getline(cin, string_input);
//    } while (stoi(string_input) < 0);
//
//    int num = stoi(string_input);
//    int count = 0;
//
//    if (num == 0) {
//        return;
//    }
//    else {
//        while (count != num) {
//            do {
//                cout << "Which items are the customer borrowing: ";
//                getline(cin, string_input);
//            } while (stoi(string_input) < 0);
//        }
//    }
//}

Item* processItemFromCustomer(string str) {
    Item* item;

    stringstream ss(str.substr(1, str.size() - 2));
    
    string word;

    vector<string> words;

    while (getline(ss, word, ',')) {
        words.push_back(word);
    }

    if (words.at(2) == "Video Game") {
        item = new VideoGame(words.at(0), words.at(1), stoi(words.at(3)), stoi(words.at(4)), stof(words.at(5)));
    }
    else if (words.at(2) == "DVD") {
        item = new DVD(words.at(0), words.at(1), words.at(3), stoi(words.at(4)), stoi(words.at(5)), stof(words.at(6)));
    }
    else {
        item = new OldMovieRecord(words.at(0), words.at(1), words.at(3), stoi(words.at(4)), stoi(words.at(5)), stof(words.at(6)));
    }

    return item;
}

vector<Customer *> fetchCustomers(string filename) {
    ifstream ifile;
    ifile.open(filename);

    vector<Customer *> customer_list;

    string line, word;

    int num_items = 0;

    while (getline(ifile, line)) {
        stringstream ss(line);
        vector<string> words;
        vector<string> items;
        while (getline(ss, word, ',')) {
            words.push_back(word);
        }

        int num_word = words.size();

        if (words.at(4) == "Guest") {
            GuestAccount* ga = new GuestAccount(words.at(0), words.at(1), words.at(2), words.at(3), stoi(words.at(6)), stoi(words.at(5)), items);
            if (num_word == 7) {
                customer_list.push_back(ga);
                continue;
            }
            else if (num_word > 7) {
                for (int i = 7; i < num_word; i++) {
                    items.push_back(words.at(i));
                }
                customer_list.push_back(ga);
            }
            ga->setBorrowedItems(items);

        }
        else if (words.at(4) == "Regular") {
            RegularAccount* ra = new RegularAccount(words.at(0), words.at(1), words.at(2), words.at(3), stoi(words.at(6)), stoi(words.at(5)), items);
            if (num_word == 7) {
                customer_list.push_back(ra);
                continue;
            }
            else if (num_word > 7) {
                for (int i = 7; i < num_word; i++) {
                    items.push_back(words.at(i));
                }
                customer_list.push_back(ra);
            }
            ra->setBorrowedItems(items);

        }
        else if (words.at(4) == "VIP") {
            VIPAccount* va = new VIPAccount(words.at(0), words.at(1), words.at(2), words.at(3), stoi(words.at(6)), stoi(words.at(5)), stoi(words.at(7)), items);
            if (num_word == 8) {
                customer_list.push_back(va);
                continue;
            }
            else if (num_word > 8) {
                for (int i = 8; i < num_word; i++) {
                    items.push_back(words.at(i));
                }
                va->setBorrowedItems(items);
            }
        }
    }
    return customer_list;
}

//� The ability to add, update customer from the database.
// Add
bool addCustomer(string filename) {
    // For input validation
    int choice;
    string string_input;

    // Account attributes
    string id, name, address, phone, type;
    int point = 0;
    vector<Item *> list;

    cout << "Please select which type of Account you would like to add:" << endl;
    cout << "1. Guest Account" << endl;
    cout << "2. Regular Account" << endl;
    cout << "3. VIP Account" << endl;

    do {
        cout << "Your choice: ";
        getline(cin, string_input);
    } while (stoi(string_input) < 1 || stoi(string_input) > 3);
    choice = stoi(string_input);

    id = inputCustomerID();
    name = inputCustomerName();
    address = inputCustomerAddress();
    phone = inputCustomerPhone();
    if (choice == 3) {
        point = inputCustomerPoint();
    }

    // Open file
    ofstream file;
    file.open(filename, ios::app);

    if (choice == 1) {
        GuestAccount* ga = new GuestAccount(id, name, address, phone);
        file << * ga;
    }
    else if (choice == 2) {
        RegularAccount* ra = new RegularAccount(id, name, address, phone);
        file << * ra;
    }
    else {
        VIPAccount* va = new VIPAccount(id, name, address, phone, 0, point);
        file << * va;
    }

    return true;
}

// Update
// Special note: As not to interfere with the system, only ID, Name, Address, Phone, and Type could be changed
bool updateCustomer(string filename) {
    vector<Customer *> customers = fetchCustomers(filename);
    int updating_item_index;
    string string_input;

    cout << "Please enter the ID of the Customer you want to update: ";
    getline(cin, string_input);

    if (search(string_input, customers) != -1) {
        updating_item_index = search(string_input, customers);
    }
    else {
        cout << "Customer not found in database. Please try again\n";
        return false;
    }

    customers.at(updating_item_index)->display();

    cout << "\nPlease re-input the following information to update the selected customer:\n";
    // Item attributes
    string id, name, address, phone, type;
    int point;

    id = inputCustomerID();
    name = inputCustomerName();
    address = inputCustomerAddress();
    phone = inputCustomerPhone();
    type = inputCustomerType();

    if (type == "VIP") {
        point = inputCustomerPoint();
    }

    if (type == "Guest") {
        GuestAccount* ga = new GuestAccount(id, name, address, phone, customers.at(updating_item_index)->getNumBorrowed(), customers.at(updating_item_index)->getReturnCount(), customers.at(updating_item_index)->getBorrowedItems());
        customers.at(updating_item_index) = ga;
    }
    else if (type == "Regular") {
        RegularAccount* ra = new RegularAccount(id, name, address, phone, customers.at(updating_item_index)->getNumBorrowed(), customers.at(updating_item_index)->getReturnCount(), customers.at(updating_item_index)->getBorrowedItems());
        customers.at(updating_item_index) = ra;
    }
    else {
        VIPAccount* va = new VIPAccount(id, name, address, phone, customers.at(updating_item_index)->getNumBorrowed(), customers.at(updating_item_index)->getReturnCount(), point, customers.at(updating_item_index)->getBorrowedItems());
        customers.at(updating_item_index) = va;
    }

    updateFile(filename, customers);

    return true;
}

//� The ability to increase the number of copies of an existing item (this is done when new stock arrives).
bool addStock(string filename) {
    string input, item_id;
    int updating_item_index, increment;
    vector<Item*> items = fetchItems(filename);

    cout << "Please enter item ID to add to stock: ";
    getline(cin, item_id);

    if (search(item_id, items) != -1) {
        updating_item_index = search(item_id, items);
    }
    else {
        cout << "Item not found in database. Please try again\n";
        return false;
    }

    do {
        cout << "Please enter number of items being added: ";
        getline(cin, input);
    } while (!check_user_input_int(input));
    increment = stoi(input);

    items.at(updating_item_index)->setStock(items.at(updating_item_index)->getStock() + increment);

    updateFile(filename, items);

    return true;
}

//� The ability to read data from and save the data to disk (e.g. text files). This applied for any updates to the customer list and the item list, as described above.
// Done

//� The ability to rent an item (hence decreasing the number of copies held in stock). It should not be possible to rent an item for which there are no copies held in stock. In this case, the item�s rental status should be �not available� or �borrowed�.
bool borrowFunc(string items_file, string customers_file) {
    vector<Item*> items = fetchItems(items_file);
    vector<Customer *> customers = fetchCustomers(customers_file);
    string input;
    int updating_customer_index, updating_item_index;

    cout << "Please input borrower's ID: ";
    getline(cin, input);

    if (search(input, customers) != -1) {
        updating_customer_index = search(input, customers);
    }
    else {
        cout << "Customer not found in database. Please try again\n";
        return false;
    }

    cout << "Please input the ID of the item being borrowed: ";
    getline(cin, input);

    if (search(input, items) != -1) {
        updating_item_index = search(input, items);
    }
    else {
        cout << "Item not found in database. Please try again\n";
        return false;
    }

    customers.at(updating_customer_index)->borrowing(items.at(updating_item_index));

    updateFile(items_file, items);
    updateFile(customers_file, customers);
}

//� The ability to return an item (hence increasing the number of copies held in stock).
bool returnFunc(string items_file, string customers_file) {
    vector<Item*> items = fetchItems(items_file);
    vector<Customer*> customers = fetchCustomers(customers_file);
    string input;
    int updating_customer_index, updating_item_index;

    cout << "Please input returner's ID: ";
    getline(cin, input);

    if (search(input, customers) != -1) {
        updating_customer_index = search(input, customers);
    }
    else {
        cout << "Customer not found in database. Please try again\n";
        return false;
    }

    cout << "Please input the ID of the item being returned: ";
    getline(cin, input);

    if (search(input, items) != -1) {
        updating_item_index = search(input, items);
    }
    else {
        cout << "Item not found in database. Please try again\n";
        return false;
    }

    customers.at(updating_customer_index)->returning(items.at(updating_item_index));

    updateFile(items_file, items);
    updateFile(customers_file, customers);
}

//� The ability to promote a customer (from Guest to Regular or from Regular to VIP).
//� The ability to display all items, sorted by titles or IDs.
//� The ability to display all customer, sorted by names or IDs.
//� The ability to display a group of customers according to their level (e.g. Guest, Regular, or VIP).
//� The ability to display all items that have no copies in stock.
//� The ability to search for an item that matches a specified title or ID.
//   o Searches that match titles should display the information about that item, including title, genre, rental type, and the number of copies available.
//� The ability to search for a customer that matches a specified name or ID.
//    o Searches that match a customer should display the information about that customer including customer name and customer ID, phone, address
