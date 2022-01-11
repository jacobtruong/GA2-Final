#include "RelatedFunctions.h"

int main(int argc, char* argv[]) {
	// Driver code - below is the menu navigation
	print_menu();
	string user_choice;
	int user_choice_int;
	while (1) {
		if (check_user_input_menu(user_input(user_choice))) {
			if (check_user_input_int(user_choice.c_str())) {
				user_choice_int = stoi((user_choice));
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
							print_sub_menu_1_2();
							if (check_user_input_sub_menu_1_2(user_choice_int = stoi(user_input(user_choice)))) {
								switch (user_choice_int) {
								case 1:
									updateItem("Items.txt");
										break;
								case 2:
									addStock("Items.txt");
										break;
								default:
									break;
								}
							}
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
					promoteCustomer("Customers.txt");
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
					displayAllItems("Items.txt");
					break;
				case 7:
					//Display out-of-stock items
					displayItemsWithNoStocks("Items.txt");
					break;
				case 8:
					//Display all customers
					displayAllCustomers("Customers.txt");
					break;
				case 9:
					//Display a group of customers
					displayCustomersByType("Customers.txt");
					break;
				case 10:
					//Search items
					print_sub_menu_10();
					if (check_user_input_sub_menu_10(user_choice_int = stoi(user_input(user_choice)))) {
						switch (user_choice_int) {
						case 1:
							//10.1 search items
							searchAndDisplayItems("Items.txt");
							break;
						case 2:
							//10.2 search customers
							searchAndDisplayCustomers("Customers.txt");
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

	// Prerequisite Team Information
	cout << "ASSIGNMENT 2 GROUP 23" << endl
		<< "s3878145, s3878145@rmit.edu.vn, Tri, Truong" << endl
		<< "s3878496, s3878496@rmit.edu.vn, Dat, Pham" << endl;

	return 0;
}