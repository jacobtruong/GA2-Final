#include "RelatedFunctions.h"

int main(int argc, char* argv[]) {
    /*addItem("E:\\Users\\Raven\\Documents\\Test\\Items.txt");*/
    //updateItem("E:\\Users\\Raven\\Documents\\Test\\Items.txt");
    deleteItem("E:\\Users\\Raven\\Documents\\Test\\Items.txt");

    /*addCustomer("E:\\Users\\Raven\\Documents\\Test\\Customers.txt");
    addCustomer("E:\\Users\\Raven\\Documents\\Test\\Customers.txt");
    addCustomer("E:\\Users\\Raven\\Documents\\Test\\Customers.txt");*/

    //borrowFunc("E:\\Users\\Raven\\Documents\\Test\\Items.txt", "E:\\Users\\Raven\\Documents\\Test\\Customers.txt");
    returnFunc("E:\\Users\\Raven\\Documents\\Test\\Items.txt", "E:\\Users\\Raven\\Documents\\Test\\Customers.txt");

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

    print_menu();
    string user_choice;
    int user_choice_int;
    while (1) {
        if (check_user_input_menu(user_input(user_choice))) {
            if (check_user_input_int(user_choice.c_str())) {
                user_choice_int = covert_input(user_choice);
                switch (user_choice_int) {
                case 1:
                    print_sub_menu_1();
                    if (check_user_input_sub_menu_1(user_choice_int = stoi(user_input(user_choice)))) {
                        switch (user_choice_int) {
                        case 1:
                            //1.1 add new item function
                            addItem("Items.txt");
                            break;
                        case 2:
                            //1.2 Update the existing item function
                            updateItem("Items.txt");
                            break;
                        case 3:
                            //1.3 Delete the existing item
                            deleteItem("Items.txt");
                            break;
                        default:
                            break;
                        }
                    }
                    break;
                case 2:
                    print_sub_menu_2();
                    if (check_user_input_sub_menu_2(user_choice_int = stoi(user_input(user_choice)))) {
                        switch (user_choice_int) {
                        case 1:
                            //2.1 Add new customer
                            addCustomer("Customers.txt");
                            break;
                        case 2:
                            //2.2 Update the existing customers function
                            updateCustomer("Customers.txt");
                            break;
                        default:
                            break;
                        }
                    }
                    break;
                case 3:
                    // Promoting an existing customer
                    cout << "op3";
                    break;
                case 4:
                    //Rent an item
                    borrowFunc("Items.txt", "Customers.txt");
                    break;
                case 5:
                    //Return an item
                    returnFunc("Items.txt", "Customers.txt");
                    break;
                case 6:
                    //Display all items
                    cout << "op6";
                    break;
                case 7:
                    //Display out-of-stock items
                    cout << "op7";
                    break;
                case 8:
                    //Display all customers
                    cout << "op8";
                    break;
                case 9:
                    //Display a group of customers
                    print_sub_menu_9();
                    if (check_user_input_sub_menu_9(user_choice_int = stoi(user_input(user_choice)))) {
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
                    //Search items
                    print_sub_menu_10();
                    if (check_user_input_sub_menu_10(user_choice_int = stoi(user_input(user_choice)))) {
                        switch (user_choice_int) {
                        case 1:
                            //10.1 search items
                            print_sub_menu_10_1();
                            if (check_user_input_sub_menu_10(user_choice_int = stoi(user_input(user_choice)))) {
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
                            if (check_user_input_sub_menu_10(user_choice_int = stoi(user_input(user_choice)))) {
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
            cout << '\n';
            cout << "Back to main menu!" << endl;
            cout << '\n';
            print_menu();
        }
        else {
            exit(1);
        }
    }

    return 0;
}