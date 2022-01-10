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

//• The ability to add, update and delete items from the database of stocked items.
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

    ofstream file;
    file.open(filename, ios::trunc);
    file.close();

    for (Item* i : items) {
        i->writeToFile(filename);
    }

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

//• The ability to add, update customer from the database.
//• The ability to increase the number of copies of an existing item (this is done when new stock arrives).
//• The ability to read data from and save the data to disk (e.g. text files). This applied for any updates to the customer list and the item list, as described above.
//• The ability to rent an item (hence decreasing the number of copies held in stock). It should not be possible to rent an item for which there are no copies held in stock. In this case, the item’s rental status should be ‘not available’ or ‘borrowed’.
//• The ability to return an item (hence increasing the number of copies held in stock).
//• The ability to promote a customer (from Guest to Regular or from Regular to VIP).
//• The ability to display all items, sorted by titles or IDs.
//• The ability to display all customer, sorted by names or IDs.
//• The ability to display a group of customers according to their level (e.g. Guest, Regular, or VIP).
//• The ability to display all items that have no copies in stock.
//• The ability to search for an item that matches a specified title or ID.
//   o Searches that match titles should display the information about that item, including title, genre, rental type, and the number of copies available.
//• The ability to search for a customer that matches a specified name or ID.
//    o Searches that match a customer should display the information about that customer including customer name and customer ID, phone, address

