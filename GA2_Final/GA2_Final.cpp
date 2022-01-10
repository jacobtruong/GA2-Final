#include <iostream>
#include "Item.h"
#include "OldMovieRecord.h"
#include "DVD.h"
#include "VideoGame.h"
#include "Customer.h"
#include "GuestAccount.h"
#include "RegularAccount.h"
#include "VIPAccount.h"
#include "Header.h"

using namespace std;

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