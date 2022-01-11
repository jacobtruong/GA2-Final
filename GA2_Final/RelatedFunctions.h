#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include "Item.h"
#include "OldMovieRecord.h"
#include "DVD.h"
#include "VideoGame.h"
#include "Customer.h"
#include "GuestAccount.h"
#include "RegularAccount.h"
#include "VIPAccount.h"
#include "Header.h"

// This function fetches items from an item file and return a vector of Item objects
vector<Item*> fetchItems(string filename) {

    // Open file
    ifstream ifile;
    ifile.open(filename);

    // Initialise Item * vector
    vector<Item*> item_list;

    string line, word;

    // Loop until the end of file
    while (getline(ifile, line)) {
        // Take in whole line
        stringstream ss(line);
        vector<string> words;

        // Breaking the line into smaller words
        while (getline(ss, word, ',')) {
            words.push_back(word);
        }

        // Depends on the item's rental type (words.at(2)), appropriate objects will be created and add to item_list
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

// This basically "update" the file by rewriting data to the file from the vector - Overloaded function
bool updateFile(string filename, vector<Customer*> &customers) {
    // Open file in truncate mode and close file to delete everything
    ofstream file;
    file.open(filename, ios::trunc);
    file.close();

    // Each customer object in the vector list will write to the output file
    for (Customer* c : customers) {
        c->writeToFile(filename);
    }

    return true;
}

// This basically "update" the file by rewriting data to the file from the vector - Overloaded function
bool updateFile(string filename, vector<Item*>& items) {
    // Open file in truncate mode and close file to delete everything
    ofstream file;
    file.open(filename, ios::trunc);
    file.close();

    // Each item object in the vector list will write to the output file
    for (Item * i : items) {
        i->writeToFile(filename);
    }

    return true;
}

// Search function that returns the index of the object with the given id - Overloaded function
int search(string id, vector<Item *> &items) {
    int index = 0;

    // If an ID match is found, return the index
    for (Item * i : items) {
        if (id == i->getID()) {
            return index;
        }
        index++;
    }

    // Else return -1 (This also means that item with the given id doesn't exist)
    return -1;
}

// Search function that returns the index of the object with the given id - Overloaded function
int search(string id, vector<Customer *>& customers) {
    int index = 0;

    // If an ID match is found, return the index
    for (Customer * c : customers) {
        if (id == c->getID()) {
            return index;
        }
        index++;
    }

    // Else return -1 (This also means that item with the given id doesn't exist)
    return -1;
}

// Below are functions relating to user inputs for the Items attributes

// Function to input item's ID
string inputItemID() {
    string string_input;
    do {
        cout << "Please input valid item ID (Format: Ixxx-yyyy): ";
        getline(cin, string_input);
    } while (!check_id_item(string_input)); // Check if ID has the correct format
    return string_input;
}

// Function to input item's title
string inputItemTitle() {
    string string_input;
    do {
        cout << "Please input title: ";
        getline(cin, string_input);
    } while (string_input == "");
    return string_input;
}

// Function to input item's rental type
string inputItemRentalType() {
    string string_input;
    do {
        cout << "Please input item type (Video Game, DVD, or Old Movie Record): ";
        getline(cin, string_input);
    } while (string_input != "Video Game" && string_input != "DVD" && string_input != "Old Movie Record");
    return string_input;
}

// Function to input item's genre
string inputItemGenre() {
    string string_input;
    do {
        cout << "Please input genre (Action, Horror, Drama, or Comedy): ";
        getline(cin, string_input);
    } while (string_input != "Action" && string_input != "Horror" && string_input != "Drama" && string_input != "Comedy");
    return string_input;
}

// Function to input item's loan type
int inputItemLoanType() {
    string string_input;
    do {
        cout << "Please input valid loan type (1 for 2-day, 2 for 1-week): ";
        getline(cin, string_input);
    } while (!check_user_input_int(string_input) || (stoi(string_input) != 1 && stoi(string_input) != 2));
    return stoi(string_input);
}

// Function to input item's stock
int inputItemStock() {
    string string_input;
    do {
        cout << "Please input valid stock number (integer only): ";
        getline(cin, string_input);
    } while (!check_user_input_int(string_input) || (stoi(string_input) < 0));
    return stoi(string_input);
}

// Function to input item's rental fee
float inputItemRentalFee() {
    string float_input;
    do {
        cout << "Please input valid rental fee: ";
        getline(cin, float_input);
    } while (stof(float_input) < 0);
    return stof(float_input);
}

// Function to input customer's ID
string inputCustomerID() {
    string string_input;
    do {
        cout << "Please input valid customer ID (Format: Cxxx): ";
        getline(cin, string_input);
    } while (!check_id_customer(string_input)); // Check if ID has the correct format
    return string_input;
}

// Function to input customer's name
string inputCustomerName() {
    string string_input;
    do {
        cout << "Please input customer's name: ";
        getline(cin, string_input);
    } while (string_input == "");
    return string_input;
}

// Function to input customer's address
string inputCustomerAddress() {
    string string_input;
    do {
        cout << "Please input customer's address: ";
        getline(cin, string_input);
    } while (string_input == "");
    return string_input;
}

// Function to input customer's phone number
string inputCustomerPhone() {
    string string_input;
    do {
        cout << "Please input customer's phone number: ";
        getline(cin, string_input);
    } while (string_input == "");
    return string_input;
}

// Function to input customer's account type
string inputCustomerType() {
    string string_input;
    do {
        cout << "Please input customer's account type (Guest, Regular, or VIP): ";
        getline(cin, string_input);
    } while (string_input != "Guest" && string_input != "Regular" && string_input != "VIP");
    return string_input;
}

// Function to input VIP customer's reward points
int inputCustomerPoint() {
    string string_input;
    do {
        cout << "Please input customer's total number reward points: ";
        getline(cin, string_input);
    } while (!check_user_input_int(string_input));
    return stoi(string_input);
}

// Below are features required in the specifications
// "The ability to add, update and delete items from the database of stocked items."

// Function to add new item
bool addItem(string filename) {
    // Fetch all current items from file
    vector<Item*> items = fetchItems(filename);

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
    
    // Asking user to input ID details
    id = inputItemID();

    // If the inputted item is the same as that of an existing item, print error
    if (search(id, items) != -1) {
        cout << "Item with the same ID (" << id << ") already existed! Please try again!\n";
        return false;
    }

    // Asking user to input other details
    title = inputItemTitle();
    if (choice != 1) {
        genre = inputItemGenre();
    }
    type = inputItemLoanType();
    stock = inputItemStock();
    fee = inputItemRentalFee();

    // Open file in append mode
    ofstream file;
    file.open(filename, ios::app);

    // Depends on the item type, the appropriate object will be created and written directly to file
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

    // Close file
    file.close();
    return true;
}

// Function to update item
bool updateItem(string filename) {
    // Fetch all current items file
    vector<Item*> items = fetchItems(filename);

    int updating_item_index;
    string string_input;

    cout << "Input the item you want to update!\n";
    string_input = inputItemID();

    // If item is not found in the list, return false and stop the function
    if (search(string_input, items) != -1) {
        updating_item_index = search(string_input, items);
    }
    else {
        cout << "Item not found in database. Please try again\n";
        return false;
    }

    items.at(updating_item_index)->display();

    cout << "Please re-input all information to update the selected item:\n";

    // Item attributes
    string id, title, genre, rental_type;
    int type, stock;
    float fee;

    // Item attributes input
    id = inputItemID();
    title = inputItemTitle();
    rental_type = inputItemRentalType();

    if (rental_type != "Video Game") {
        genre = inputItemGenre();
    }

    type = inputItemLoanType();
    stock = inputItemStock();
    fee = inputItemRentalFee();

    // Depends on the inputted rental type, appropriate objects will be created and updated to the item vector
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

    // Call function to update the file with updated list
    updateFile(filename, items);

    return true;
}

// Delete
bool deleteItem(string filename) {
    // Fetch all current items from file
    vector<Item*> items = fetchItems(filename);

    int updating_item_index;
    string string_input, item_id;

    cout << "Input the item you want to delete!\n";
    string_input = inputItemID();
    item_id = string_input;

    // If item is not found in the list, return false and stop the function
    if (search(string_input, items) != -1) {
        updating_item_index = search(string_input, items);
    }
    else {
        cout << "Item not found in database. Please try again\n";
        return false;
    }
    items.at(updating_item_index)->display();

    // 1 more verification before item deletion
    do {
        cout << "ARE YOU SURE YOU WANT TO DELETE THIS ITEM? THIS COULD LEAD TO DATA MISMATCH! (Y/N): ";
        getline(cin, string_input);
    } while (string_input != "Y" && string_input != "y" && string_input != "N" && string_input != "n");

    if (string_input == "N" || string_input == "n") {
        cout << "\nDeletion has been cancelled!\n";
        return false;
    }

    // Erase item from vector list
    items.erase(items.begin() + updating_item_index);

    // Call function to update the file with updated list
    updateFile(filename, items);

    cout << "Item " << item_id << " has been deleted\n";

    return true;
}

// This function fetches items from an item file and return a vector of Customers objects
vector<Customer *> fetchCustomers(string filename) {
    // Open file
    ifstream ifile;
    ifile.open(filename);

    // Initialise Item * vector
    vector<Customer *> customer_list;

    string line, word;

    int num_items = 0;

    // Loop until the end of file
    while (getline(ifile, line)) {
        stringstream ss(line);
        vector<string> words;
        vector<string> items;

        // Breaking the line into smaller words
        while (getline(ss, word, ',')) {
            words.push_back(word);
        }

        int num_word = words.size();

        // Depends on the Customer's account type (words.at(4)), appropriate objects will be created and add to item_list
        if (words.at(4) == "Guest") {
            GuestAccount* ga = new GuestAccount(words.at(0), words.at(1), words.at(2), words.at(3), stoi(words.at(6)), stoi(words.at(5)), items);
            if (num_word == 7) {
                customer_list.push_back(ga);
                continue;
            }
            // After the first 7 strings (attributes), if there are any more afterwards, they are the ID of the borrowed items => Add them into the "items" list
            else if (num_word > 7) {
                for (int i = 7; i < num_word; i++) {
                    items.push_back(words.at(i));
                }
                customer_list.push_back(ga);
            }
            ga->setBorrowedItems(items); // set borrowed_item with "items" (which could be empty)

        }
        else if (words.at(4) == "Regular") {
            RegularAccount* ra = new RegularAccount(words.at(0), words.at(1), words.at(2), words.at(3), stoi(words.at(6)), stoi(words.at(5)), items);
            if (num_word == 7) {
                customer_list.push_back(ra);
                continue;
            }
            // After the first 7 strings (attributes), if there are any more afterwards, they are the ID of the borrowed items => Add them into the "items" list
            else if (num_word > 7) {
                for (int i = 7; i < num_word; i++) {
                    items.push_back(words.at(i));
                }
                customer_list.push_back(ra);
            }
            ra->setBorrowedItems(items); // set borrowed_item with "items" (which could be empty)

        }
        else if (words.at(4) == "VIP") {
            VIPAccount* va = new VIPAccount(words.at(0), words.at(1), words.at(2), words.at(3), stoi(words.at(6)), stoi(words.at(5)), stoi(words.at(7)), items);
            if (num_word == 8) {
                customer_list.push_back(va);
                continue;
            }
            // After the first 8 strings (attributes), if there are any more afterwards, they are the ID of the borrowed items => Add them into the "items" list
            else if (num_word > 8) {
                for (int i = 8; i < num_word; i++) {
                    items.push_back(words.at(i));
                }
                customer_list.push_back(va);
            }
            va->setBorrowedItems(items); // set borrowed_item with "items" (which could be empty)
        }
    }
    return customer_list;
}

// "The ability to add, update customer from the database."

// Function to add customer
bool addCustomer(string filename) {
    // Fetch all current customers from file
    vector<Customer*> customers = fetchCustomers(filename);
    
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

    // Asking user to input ID details
    id = inputCustomerID();

    // If the inputted Customer ID is the same as that of an existing item, print error 
    if (search(id, customers) != -1) {
        cout << "Customer with the same ID (" << id << ") already existed! Please try again!\n";
        return false;
    }

    // Asking user to input other details
    name = inputCustomerName();
    address = inputCustomerAddress();
    phone = inputCustomerPhone();
    if (choice == 3) {
        point = inputCustomerPoint();
    }

    // Open file in append mode
    ofstream file;
    file.open(filename, ios::app);

    // Depends on the item type, the appropriate object will be created and written directly to file
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

    // Close file
    file.close();

    return true;
}

// Function to update item
// Special note: As not to interfere with the system, only ID, Name, Address, Phone, and Type could be updated
bool updateCustomer(string filename) {
    // Fetch all current customers from file
    vector<Customer *> customers = fetchCustomers(filename);

    int updating_item_index;
    string string_input;
    
    cout << "Input the customer you want to update!\n";
    string_input = inputCustomerID();

    // If customer is not found in the list, return false and stop the function
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

    // Item attributes input
    id = inputCustomerID();
    name = inputCustomerName();
    address = inputCustomerAddress();
    phone = inputCustomerPhone();
    type = inputCustomerType();

    if (type == "VIP") {
        point = inputCustomerPoint();
    }

    // Depends on the inputted rental type, appropriate objects will be created and updated to the item vector
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

    // Call function to update the file with updated list
    updateFile(filename, customers);

    return true;
}

//• The ability to increase the number of copies of an existing item (this is done when new stock arrives).
bool addStock(string filename) {
    // Fetch all current items from file
    vector<Item*> items = fetchItems(filename);

    string input, item_id;
    int updating_item_index, increment;


    cout << "Input the item to increase the stock!\n";
    item_id = inputItemID();

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

// The ability to read data from and save the data to disk (e.g. text files). This applied for any updates to the customer list and the item list, as described above.
// Applied throughout the program to make sure everything works correctly

// The ability to rent an item (hence decreasing the number of copies held in stock). It should not be possible to rent an item for which there are no copies held in stock. In this case, the item’s rental status should be ‘not available’ or ‘borrowed’.
bool borrowFunc(string items_file, string customers_file) {
    vector<Item*> items = fetchItems(items_file);
    vector<Customer *> customers = fetchCustomers(customers_file);
    string input;
    int updating_customer_index, updating_item_index;

    cout << "Input the borrowing customer!\n";
    input = inputCustomerID();

    if (search(input, customers) != -1) {
        updating_customer_index = search(input, customers);
    }
    else {
        cout << "Customer not found in database. Please try again\n";
        return false;
    }

    cout << "Input the item being borrowed!\n";
    input = inputItemID();

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

    return true;
}

//• The ability to return an item (hence increasing the number of copies held in stock).
bool returnFunc(string items_file, string customers_file) {
    vector<Item*> items = fetchItems(items_file);
    vector<Customer*> customers = fetchCustomers(customers_file);
    string input;
    int updating_customer_index, updating_item_index;

    cout << "Input the returning customer!\n";
    input = inputCustomerID();

    if (search(input, customers) != -1) {
        updating_customer_index = search(input, customers);
    }
    else {
        cout << "Customer not found in database. Please try again\n";
        return false;
    }

    cout << "Input the item being returned!\n";
    input = inputItemID();

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

    return true;
}

// The ability to promote a customer (from Guest to Regular or from Regular to VIP).
bool promoteCustomer(string filename) {
    vector<Customer*> customers = fetchCustomers(filename);
    
    string input;
    int updating_customer_index;

    cout << "Input the customer you want to promote!\n";
    input = inputCustomerID();

    if (search(input, customers) != -1) {
        updating_customer_index = search(input, customers);
    }
    else {
        cout << "Customer not found in database. Please try again\n";
        return false;
    }

    Customer* csm = customers.at(updating_customer_index);

    if (csm->getType() == "VIP") {
        cout << "VIP Customer cannot be promoted!\n";
        return false;
    }

    if (csm->getReturnCount() < 3) {
        cout << csm->getType() << " Customer " << csm->getName() << " (" << csm->getID() << ")" << " has not returned sufficient number of items (Current return count: " << csm->getReturnCount() << ")\n";
        return false;
    }

    if (csm->getType() == "Guest") {
        RegularAccount* ra = new RegularAccount(csm->getID(), csm->getName(), csm->getAddress(), csm->getPhone(), csm->getNumBorrowed(), 0, csm->getBorrowedItems());
        customers.at(updating_customer_index) = ra;
        cout << "Guest Customer " << csm->getName() << " (" << csm->getID() << ")" << " has been promoted to Regular Customer!\n";
    }
    else if (csm->getType() == "Regular") {
        VIPAccount* va = new VIPAccount(csm->getID(), csm->getName(), csm->getAddress(), csm->getPhone(), csm->getNumBorrowed(), 0, 0, csm->getBorrowedItems());
        customers.at(updating_customer_index) = va;
        cout << "Regular Customer " << csm->getName() << " (" << csm->getID() << ")" << " has been promoted to VIP Customer!\n";
    }

    updateFile(filename, customers);
    return true;
}


// SORTS
void sortByName(vector<Item* >* items) {
    int size = items->size();

    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (items->at(j)->getTitle().compare(items->at(j + 1)->getTitle()) > 0)
                swap(items->at(j), items->at(j + 1));
}

void sortByID(vector<Item* >* items) {
    int size = items->size();

    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (items->at(j)->getID().compare(items->at(j + 1)->getID()) > 0)
                swap(items->at(j), items->at(j + 1));
}

void sortByName(vector<Customer * >* customers) {
    int size = customers->size();

    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (customers->at(j)->getName().compare(customers->at(j + 1)->getName()) > 0)
                swap(customers->at(j), customers->at(j + 1));
}

void sortByID(vector<Customer * >* customers) {
    int size = customers->size();

    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (customers->at(j)->getID().compare(customers->at(j + 1)->getID()) > 0)
                swap(customers->at(j), customers->at(j + 1));
}

//• The ability to display all items, sorted by titles or IDs.
bool displayAllItems(string filename) {
    vector<Item*> items = fetchItems(filename);
    string input;

    cout << "Would you like to sort the items by: \n";
    cout << "1. Name/Title\n";
    cout << "2. ID\n";

    do {
        cout << "Your choice: ";
        getline(cin, input);
    } while (!check_user_input_int(input) || stoi(input) != 1 && stoi(input) != 2);
    int choice = stoi(input);

    if (choice == 1) {
        sortByName(&items);
    }
    else if (choice == 2) {
        sortByID(&items);
    }

    for (Item* item : items) {
        item->display();
    }

    return true;
}

//• The ability to display all customer, sorted by names or IDs.
bool displayAllCustomers(string filename) {
    vector<Customer *> customers = fetchCustomers(filename);
    string input;

    cout << "Would you like to sort the customers by: \n";
    cout << "1. Name\n";
    cout << "2. ID\n";
    do {
        cout << "Your choice: ";
        getline(cin, input);
    } while (!check_user_input_int(input) || stoi(input) != 1 && stoi(input) != 2);
    int choice = stoi(input);

    if (choice == 1) {
        sortByName(&customers);
    }
    else if (choice == 2) {
        sortByID(&customers);
    }

    for (Customer * customer : customers) {
        customer->display();
    }

    return true;
}
 
//• The ability to display a group of customers according to their level (e.g. Guest, Regular, or VIP).
bool displayCustomersByType(string filename) {
    vector<Customer*> customers = fetchCustomers(filename);
    string input;

    cout << "Select your type customers level: \n";
    cout << "1. Guest Customers\n";
    cout << "2. Regular Customers\n";
    cout << "3. VIP Customers\n";

    do {
        cout << "Your choice: ";
        getline(cin, input);
    } while (!check_user_input_int(input) || stoi(input) != 1 && stoi(input) != 2 && stoi(input) != 3);

    int choice = stoi(input);

    string check;
    if (choice == 1) {
        check = "Guest";
    }
    else if (choice == 2) {
        check = "Regular";
    }
    else {
        check = "VIP";
    }

    cout << endl;

    for (Customer* csm : customers) {
        if (csm->getType() == check) {
            csm->display();
        }
    }

    return true;
}

//• The ability to display all items that have no copies in stock.
bool displayItemsWithNoStocks(string filename) {
    // Fetch all current items from file
    vector<Item*> items = fetchItems(filename);

    cout << "Below are items with no stocks:\n";

    for (Item* item : items) {
        if (item->getStock() == 0) {
            item->display();
        }
    }

    return true;
}

//• The ability to search for an item that matches a specified title or ID.
//   o Searches that match titles should display the information about that item, including title, genre, rental type, and the number of copies available.
bool searchAndDisplayItems(string filename) {
    // Fetch all current items from file
    vector<Item*> items = fetchItems(filename);
    string input;
    bool has_required_item = false;

    cout << "Would you like to search for Items by: \n";
    cout << "1. Name/Title\n";
    cout << "2. ID\n";

    do {
        cout << "Your choice: ";
        getline(cin, input);
    } while (!check_user_input_int(input) || stoi(input) != 1 && stoi(input) != 2);
    int choice = stoi(input);

    cout << "Please input your search query: ";
    getline(cin, input);

    if (choice == 1) {
        for (Item * item : items) {
            if (item->getTitle() == input) {
                has_required_item = true;
                item->display();
            }
        }
    }
    else if (choice == 2) {
        for (Item* item : items) {
            if (item->getID() == input) {
                has_required_item = true;
                item->display();
            }
        }
    }

    if (!has_required_item) {
        cout << "\nNo items found with the inputted query!\n";
    }

    return has_required_item;
}

//• The ability to search for a customer that matches a specified name or ID.
//    o Searches that match a customer should display the information about that customer including customer name and customer ID, phone, address
bool searchAndDisplayCustomers(string filename) {
    // Fetch all current customers from file
    vector<Customer *> customers = fetchCustomers(filename);
    string input;
    bool has_required_item = false;

    cout << "Would you like to search for Customers by: \n";
    cout << "1. Name\n";
    cout << "2. ID\n";

    do {
        cout << "Your choice: ";
        getline(cin, input);
    } while (!check_user_input_int(input) || stoi(input) != 1 && stoi(input) != 2);
    int choice = stoi(input);

    cout << "Please input your search query: ";
    getline(cin, input);

    if (choice == 1) {
        for (Customer * customer : customers) {
            if (customer->getName() == input) {
                has_required_item = true;
                customer->display();
            }
        }
    }
    else if (choice == 2) {
        for (Customer * customer : customers) {
            if (customer->getID() == input) {
                has_required_item = true;
                customer->display();
            }
        }
    }

    if (!has_required_item) {
        cout << "\nNo items found with the inputted query!\n";
    }

    return has_required_item;
}