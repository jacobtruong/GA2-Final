#include "RelatedFunctions.h"

int main(int argc, char* argv[]) {
    /*addItem("E:\\Users\\Raven\\Documents\\Test\\Items.txt");*/
    /*updateItem("E:\\Users\\Raven\\Documents\\Test\\Items.txt");*/
    //deleteItem("E:\\Users\\Raven\\Documents\\Test\\Items.txt");

    /*addCustomer("E:\\Users\\Raven\\Documents\\Test\\Customers.txt");
    addCustomer("E:\\Users\\Raven\\Documents\\Test\\Customers.txt");
    addCustomer("E:\\Users\\Raven\\Documents\\Test\\Customers.txt");*/

    /*updateCustomer("E:\\Users\\Raven\\Documents\\Test\\Customers.txt");*/
    addStock("E:\\Users\\Raven\\Documents\\Test\\Items.txt");

    //// Borrowing testing
    //Item* item[4];
    //item[0] = new VideoGame("I001-2022", "God of War", 2, 20, 10);
    //item[1] = new DVD("I002-2022", "007: No Time To Die", "Action", 2, 20, 15);
    //item[2] = new OldMovieRecord("I003-2022", "007: Dr. No", "Action", 2, 20, 20);
    //item[3] = new VideoGame("I004-2022", "The Witcher 3", 1, 20, 30);

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
    //    //c[i]->returning(item[0]);
    //    //c[i]->returning(item[1]);
    //    //c[i]->returning(item[2]);
    //    //c[i]->returning(item[3]);
    //    c[i]->writeToFile("E:\\Users\\Raven\\Documents\\Test\\Customers.txt");
    //    cout << endl;
    //}

    //for (Item * it : item) {
    //    it->display();
    //}

    //VideoGame* i0 = (VideoGame*)item[0];

    //cout << *i0;
    

    /*Item* item[4];
    item[0] = new VideoGame("I001-2022", "God of War", 2, 1, 10);

    cout << *item[0];

    fstream file;
    file.open("E:\\Users\\Raven\\Documents\\Test\\Test.txt", ios::out | ios::app);

    file << *item[0];

    return 0;*/
}