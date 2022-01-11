#include "RelatedFunctions.h"

int main(int argc, char* argv[]) {
    //addItem("E:\\Users\\Raven\\Documents\\Test\\Items.txt");
    //updateItem("E:\\Users\\Raven\\Documents\\Test\\Items.txt");
    //deleteItem("E:\\Users\\Raven\\Documents\\Test\\Items.txt");

    //addCustomer("E:\\Users\\Raven\\Documents\\Test\\Customers.txt");
    //updateCustomer("E:\\Users\\Raven\\Documents\\Test\\Customers.txt");

    //borrowFunc("E:\\Users\\Raven\\Documents\\Test\\Items.txt", "E:\\Users\\Raven\\Documents\\Test\\Customers.txt");
    //returnFunc("E:\\Users\\Raven\\Documents\\Test\\Items.txt", "E:\\Users\\Raven\\Documents\\Test\\Customers.txt");

    //promoteCustomer("E:\\Users\\Raven\\Documents\\Test\\Customers.txt");

    //displayAllItems("E:\\Users\\Raven\\Documents\\Test\\Items.txt");
    //displayAllCustomers("E:\\Users\\Raven\\Documents\\Test\\Customers.txt");

    //displayCustomersByType("E:\\Users\\Raven\\Documents\\Test\\Customers.txt");
    //displayItemsWithNoStocks("E:\\Users\\Raven\\Documents\\Test\\Items.txt");

    searchAndDisplayItems("E:\\Users\\Raven\\Documents\\Test\\Items.txt");
    searchAndDisplayCustomers("E:\\Users\\Raven\\Documents\\Test\\Customers.txt");

    /*vector<Customer*> vec = fetchCustomers("E:\\Users\\Raven\\Documents\\Test\\Customers.txt");
    for (Customer* i : vec) {
        i->display();
    }*/

    /*updateCustomer("E:\\Users\\Raven\\Documents\\Test\\Customers.txt");*/
    /*addStock("E:\\Users\\Raven\\Documents\\Test\\Items.txt");*/

    // Borrowing testing
    /*Item* item[4];
    item[0] = new VideoGame("I001-2022", "God of War", 2, 1, 10.12);
    item[1] = new DVD("I002-2022", "007: No Time To Die", "Action", 2, 1, 15.13);
    item[2] = new OldMovieRecord("I003-2022", "007: Dr. No", "Action", 2, 1, 20.14);
    item[3] = new VideoGame("I004-2022", "The Witcher 3", 1, 1, 30.15);

    Customer* c[3];
    c[0] = new GuestAccount("C001", "Alice", "HCMC", "0909090909");
    c[1] = new RegularAccount("C002", "Bob", "HCMC", "0909909090");
    c[2] = new VIPAccount("C003", "Carl", "HCMC", "0909090999");
    
    for (int i = 0; i < 3; i++) {
        c[i]->writeToFile("E:\\Users\\Raven\\Documents\\Test\\Customers.txt");
    }

    for (int i = 0; i < 4; i++) {
        item[i]->writeToFile("E:\\Users\\Raven\\Documents\\Test\\Items.txt");
    }*/

    //borrowFunc("E:\\Users\\Raven\\Documents\\Test\\Items.txt", "E:\\Users\\Raven\\Documents\\Test\\Customers.txt");

    //VideoGame* i0 = (VideoGame*)item[0];

    //cout << *i0;
    

    /*Item* item[4];
    item[0] = new VideoGame("I001-2022", "God of War", 2, 1, 10);

    cout << *item[0];

    fstream file;
    file.open("E:\\Users\\Raven\\Documents\\Test\\Test.txt", ios::out | ios::app);

    file << *item[0];

    return 0;*/
    

    return 0;
}