//start of program//
#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <conio.h> 
using namespace std;

#include "item.h"
#include "itemManager.h"
#include "customer.h"
#include "CustomerManager.h"
#include "order.h"
#include "OrderManager.h"
#include "OrderProduct.h"
#include "OrderProductManager.h"

//Function prototype//
void login();
int mainmenu();
void header();
void ItemMenu();
void CustomerMenu();
void CuOrderMenu();
void CoOrderMenu();
void OrderProductMenu();


void login()
{
	string username, password, answer;
	int attempt=0;

	system("cls");
	system("color F0");
	header();
	cout << endl;
	cout << setw(86) << " " << "********** Login **********" << endl;
	cout << endl;

	do
	{
		cout << setw(80) << " " << "Please enter username and password to login:" << endl;
		cout << endl;
		cout << setw(90) << " " << "Username: ";
		getline(cin, username);
		cout <<setw(90)<< " " << "Password: ";
		char ch = _getch();
		while (ch != 13) {//character 13 is enter
			password.push_back(ch);
			cout << '*';
			ch = _getch();
		}

		if (username=="user"&&password == "user123")
		{
			mainmenu();
		}
		else
		{
			cout << endl;
			cout << endl;
			cout << setw(85) << " " << "Incorrect username and password! " << endl;
			cout<<setw(83)<<" "<<"Please try again. " << (2 - attempt) << " attempt(s) left." << endl;
			cout << endl;
			cout << endl;
			username.clear();
			password.clear();
			attempt++;
		}

	} while (attempt < 3);

	string numberplate;
	cout << endl;
	cout << setw(55) <<" " << "******To reveal correct username and password. Please answer this security question correctly in one attempt******" << endl;
	cout << endl;
	cout << setw(70) <<" " << "Question: What is the number plate of the first car that Anne owned? (Eg: ABC123)" << endl;
	cout << setw(80) << " " << "Answer: ";
	getline(cin, numberplate);

	if (numberplate == "ABC123")
	{
		cout << endl;
		cout << setw(90) << " " << "Correct username: user" << endl;
		cout << setw(90) << " " << "Correct password: user123" << endl;
		cout << setw(80) << " " << "Please login again with the correct username and password:" << endl;
		cout << endl;
		cout << setw(90) <<""<< "Please enter 'Y' to continue:";
		char continue1;
		cin >> continue1;
		if (continue1 == 'Y' || continue1 == 'y')
		{
			cin.ignore(1);
			login();
		}
		else
			exit(1);
	}
}

void header()
{
	cout << endl;
	cout << endl;
	cout << setw(65) << " " << "===============================================================================" << setw(27) << endl;
	cout << endl;
	cout << setw(85) << " " << "Home Bakery Order Management System" << endl;
	cout << endl;
	cout << setw(92) << " " << "Delicieux Home Bakery" << endl;
	cout << setw(90) << " " << "1900, Jalan Pasir Pinji 6" << endl;
	cout << setw(93) << " " << "31650, Ipoh, Perak" << endl;
	cout << endl;
	cout << setw(90) <<" "<<"Contacts: 019-5734152 (Anne) " << endl;
	cout << setw(80) <<" "<<"Facebook: Delicieux Home Bakery    IG: Delicieux Home Bakery" << endl;
	cout << endl;
	cout << setw(65) << " " << "==============================================================================" << setw(27) << endl;
	cout << endl;
}

int main()
{
	login();
}

int mainmenu()
{
		//main menu//
		system("cls");
		system("color F0");
		int choice;
		header();

		// choose which menu to access//
		cout << setw(100) << " " << "Main Menu" << endl;
		cout << endl;
		cout << setw(85) << " " << "1. Item Menu (Add/View/Edit/Delete)" << endl;
		cout << setw(85) << " " << "2. Current Order (Add/View/Edit/Delete)" << endl;
		cout << setw(85) << " " << "3. Report of Completed Order (View/Average rating Report/Total Sales Report)" << endl;
		cout << setw(85) << " " << "4. Order_Product Menu (Add/View/Edit/Delete)" << endl;
		cout << setw(85) << " " << "5. Customer Info (Add/View/Edit)" << endl;
		cout << setw(85) << " " << "6. Exit" << endl;
		cout << endl;
		cout << setw(80) << " " << "Please enter the number of the menu you would like to access: ";
		cin >> choice;

		while (1)
		{
			if (cin.fail()) //user enter non-integer
			{
				cin.clear();
				cin.ignore(2);
				cout << endl;
				cout << setw(130) << "You have entered wrong input,please try again." << endl;
				cout << setw(80) << " " << "Please enter the number of the menu you would like to access:";
				cin >> choice;
			}
			else if (!cin.fail()) //user enter integer
			{
				while (choice < 1 || choice>6)
				{
					cout << endl;
					cout << setw(90) << " " << "Choice not valid. Please try again." << endl;
					cout << setw(80) << " " << "Please enter the number of the menu you would like to access:";
					cin >> choice;
					break;
				}
				if (choice == 1)
					ItemMenu();
				else if (choice == 2)
					CuOrderMenu();
				else if (choice == 3)
					CoOrderMenu();
				else if (choice == 4)
					OrderProductMenu();
				else if (choice == 5)
					CustomerMenu();
				else if (choice == 6)
					exit(0);
			}
		}
	return 0;
}

void ItemMenu()
{
	//choose which submenu to access//
	system("cls");
	system("color F0");
	int itemchoice;
	header();
	cout << setw(98) << " " << "Item Menu" << endl;
	cout << endl;
	cout << setw(95) << " " << "1. Add item" << endl;
	cout << setw(95) << " " << "2. View item" << endl;
	cout << setw(95) << " " << "3. Edit item" << endl;
	cout << setw(95) << " " << "4. Delete item" << endl;
	cout << setw(95) << " " << "5. Back" << endl;
	cout << endl;
	cout << setw(80) << " " << "Please enter the number of the menu you would like to access: ";
	cin >> itemchoice;

	//validate user input//
	while (1)
	{
		//if user input non integer
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(2);
			cout << endl;
			cout << setw(90) <<" "<< "You have entered wrong input,please try again." << endl;
			cout << setw(80) << " " << "Please enter the number of the menu you would like to access: ";
			cin >> itemchoice;
		}
		else if (!cin.fail()) //if user insert integer
		{
			while (itemchoice < 1 || itemchoice>5) //if user input invalid choice
			{
				cout << endl;
				cout << setw(90) << " " << "Choice not valid. Please try again." << endl;
				cout << setw(80) << " " << "Please enter the number of the menu you would like to access: ";
				cin >> itemchoice;
				break;
			}

			if (itemchoice == 1) //user choose add item
			{
				char again;
				do
				{
					Item* item1 = new Item();
					ItemManager itemmanager;

					system("cls");
					system("Color F0");

					header();

					cout << setw(87) << " " << "---------- Item Available ----------" << endl;
					cout << endl;
					
					string itemId, itemName, itemIngredients, typeName;
					double itemPrice;

					itemmanager.ViewItem();
					cout << endl;
					cout << endl;
					cout << setw(86) << " " << "********** Add New Item **********" << endl;
					cout << endl;
					cout << endl;
					cout << setw(85) << " " << "1. Please enter item's id (Eg: I001): ";
					cin.ignore(1);
					getline(cin, itemId);

					bool IDexist = itemmanager.IDexist(itemId);

					if (itemId.front() == '0') //quit add item//
					{
						ItemMenu();
					}

					while (itemId.front()!='I' || !IDexist)
					{
						while (!IDexist) //ID already exist
						{
							cout << endl;
							cout << setw(85) <<" "<<"Item id existed. Please enter a new item id: ";
							getline(cin, itemId);
							IDexist = itemmanager.IDexist(itemId);
						}
						while (itemId.front() != 'I')
						{
							cout << endl;
							cout << setw(80) <<" "<<"Item id must starts with 'I'.Please enter the correct id: "; //ID doesnt start with I
							getline(cin, itemId);
							IDexist = itemmanager.IDexist(itemId);
						}
						
					}

					cout << endl;
					cout << setw(85) << " " << "2. Please enter item's name:";
					getline(cin, itemName);
					cout << endl;

					cout << setw(85) << " " << "3. Please enter item's price:";
					cin >> itemPrice;
					while (1) //validate user input
					{
						if (cin.fail())
						{
							cin.clear();
							cin.ignore(2);
							cout << endl;
							cout << setw(80) << "" << "You have entered wrong input,please enter the correct item price: ";
							cin >> itemPrice;
						}
						if (!cin.fail())
							break;
					}

					cout << endl;
					cout << setw(85) << " " << "4. Please enter item's ingredients: ";
					cin.ignore(1);
					getline(cin, itemIngredients);
					cout << endl;

					cout << setw(85) << " " << "5. Please enter type's name: ";
					getline(cin, typeName);
					cout << endl;

					item1->item_id = itemId;
					item1->item_ingredients = itemIngredients;
					item1->item_name = itemName;
					item1->item_price = itemPrice;
					item1->type_name = typeName;

					int status = itemmanager.AddItem(item1);

					if (status != 0)
					{
						cout << endl;
						itemmanager.ViewItem();
						cout << endl;
						cout << setw(90) << " " << "Successfully added a new item." << endl;
						cout << setw(80) << " " << "Add more item? ('Y' to add more/'N' to back to item menu)" << endl;
						cout << setw(90) << " " << "Ans: ";
						cin >> again;
					}

					else
					{
						cout << endl;
						itemmanager.ViewItem();
						cout << endl;
						cout << setw(90) << " "<< "Unable to add a new item.";
						cout << setw(80) << " " << "Add more item? ('Y' to add more/'N' to back to item menu)" << endl;
						cout << setw(90) << " " << "Ans: ";
						cin >> again;
					}
				} while (again == 'Y' || again == 'y');
				ItemMenu();
			}
			else if (itemchoice == 2)//view list of item//
			{
				Item* item2 = new Item();
				ItemManager itemmanager1;
				char back;

				system("cls");
				system("Color F0");

				header();
				cout << setw(87) << " " << "---------- Item Available ----------" << endl;
				cout << endl;

				itemmanager1.ViewItem();
				cout << endl;
				cout << "\n" << setw(90) << " " << "Back to item menu? (Y): ";
				cin >> back;

				while (back != 'y' && back != 'Y')
				{
					cout << endl;
					cout << setw(85) << " " << "Invalid choice. Please enter again: ";
					cin >> back;
				}
				ItemMenu();
			}
			else if (itemchoice == 3) //user choose edit item
			{
				char again;
				do
				{
					Item* item5 = new Item();
					ItemManager itemmanager4;

					system("cls");
					system("Color F0");

					header();
					cout << setw(87) << " " << "---------- Item Available ----------" << endl;
					cout << endl;

					itemmanager4.ViewItem();
					cout << endl;
					cout << endl;
					cout << setw(87) << " " << "********** Edit Item **********" << endl;
					cout << endl;

					string ItemID2;
					int editchoice;
					cout << setw(80) << " " << "1. Please enter item's id to be edited (Eg: I001): ";
					cin.ignore(1);
					getline(cin, ItemID2);

					if (ItemID2.front() == '0') //quit add item//
					{
						ItemMenu();
					}

					bool IDexist = itemmanager4.IDexist(ItemID2);

					while (IDexist) //itemID not exist
					{
						cout << endl;
						cout << setw(83) << " " << "Item ID not exist. Please enter the correct id: ";
						getline(cin, ItemID2);
						IDexist = itemmanager4.IDexist(ItemID2);
					}

					cout << endl;
					cout << setw(95) << " " << "0. Quit Editing" << endl;
					cout << setw(95) << " " << "1. Item name" << endl;
					cout << setw(95) << " " << "2. Item Price" << endl;
					cout << setw(95) << " " << "3. Item ingredients" << endl;
					cout << setw(95) << " " << "4. Type name" << endl;
					cout << endl;
					cout << setw(80) << " " << "Please enter the number you would like to edit: ";
					cin >> editchoice;


					if (editchoice==0) //quit edit item//
					{
						ItemMenu();
					}

					while (editchoice < 0 || editchoice>4)
					{
						if (cin.fail()) //if user input non integer
						{
							cin.clear();
							cin.ignore(2);
							cout << endl;
							cout << setw(80) << " " << "You have entered wrong input,please try again." << endl;
							cout << setw(80) << " " << "Please enter the number you would like to edit: ";
							cin >> editchoice;
						}
						else if (!cin.fail()) //if user insert integer
						{
								cout << endl;
								cout << setw(90) << " " << "Choice not valid. Please try again." << endl;
								cout << setw(80) << " " << "Please enter the number you would like to edit: ";
								cin >> editchoice;
								break;
						}
					}

							if (editchoice == 1) //edit name
							{
								string newName;
								cout << endl;
								cout << setw(93) << " " << "Please enter new name: ";
								cin.ignore(1);
								getline(cin, newName);
								int status2 = itemmanager4.editIName(ItemID2, newName);

								if (status2 != 0)
								{
									cout << endl;
									itemmanager4.ViewItem();
									cout << endl;
									cout << setw(90) << " " << "Successfully edited item with ID: " << ItemID2 << endl;
									cout << setw(80) << " " << "Edit more item? ('Y' to edit more/'N' to back to item menu)" << endl;
									cout << setw(90) << " " << "Ans: ";
									cin >> again;
								}

								else
								{
									cout << endl;
									itemmanager4.ViewItem();
									cout << endl;
									cout << setw(90) << " " << "Unable to edit item" << endl;
									cout << setw(80) << " " << "Edit more item? ('Y' to edit more/'N' to back to item menu)" << endl;
									cout << setw(90) << " " << "Ans: ";
									cin >> again;
								}

							}
							if (editchoice == 2) //edit price
							{
								double newPrice;
								cout << endl;
								cout << setw(93) << " " << "Please enter new price: ";
								cin >> newPrice;

								while (1) // validate user input
								{
									if (cin.fail())
									{
										cin.clear();
										cin.ignore(2);
										cout << setw(80) << "" << "You have entered wrong input,please enter the correct item price: ";
										cin >> newPrice;
									}
									if (!cin.fail())
										break;
								}

								int status3 = itemmanager4.editIPrice(ItemID2, newPrice);

								if (status3 != 0)
								{
									cout << endl;
									itemmanager4.ViewItem();
									cout << endl;
									cout << setw(90) << " " << "Successfully edited item with ID: " << ItemID2 << endl;
									cout << setw(80) << " " << "Edit more item? ('Y' to edit more/'N' to back to item menu)" << endl;
									cout << setw(90) << " " << "Ans: ";
									cin >> again;
								}

								else
								{
									cout << endl;
									itemmanager4.ViewItem();
									cout << endl;
									cout << setw(90) << " " << "Unable to edit item" << endl;
									cout << setw(80) << " " << "Edit more item? ('Y' to edit more/'N' to back to item menu)" << endl;
									cout << setw(90) << " " << "Ans: ";
									cin >> again;
								}
							}
							if (editchoice == 3) //edit ingredients
							{
								string newIngredients;
								cout << endl;
								cout << setw(90) << " " << "Please enter new ingredients: ";
								cin.ignore(1);
								getline(cin, newIngredients);
								int status4 = itemmanager4.editIIngredients(ItemID2, newIngredients);

								if (status4 != 0)
								{
									cout << endl;
									itemmanager4.ViewItem();
									cout << endl;
									cout << setw(90) << " " << "Successfully edited item with ID: " << ItemID2 << endl;
									cout << setw(80) << " " << "Edit more item? ('Y' to edit more/'N' to back to item menu)" << endl;
									cout << setw(90) << " " << "Ans: ";
									cin >> again;
								}

								else
								{
									cout << endl;
									itemmanager4.ViewItem();
									cout << endl;
									cout << setw(90) << " " << "Unable to edit item." << endl;
									cout << setw(80) << " " << "Edit more item? ('Y' to edit more/'N' to back to item menu)" << endl;
									cout << setw(90) << " " << "Ans: ";
									cin >> again;
								}
							}
							if (editchoice == 4) //edit type name
							{
								string newType;
								cout << endl;
								cout << setw(90) << " " << "Please enter new type name: ";
								cin.ignore(1);
								getline(cin, newType);
								int status5 = itemmanager4.editIType(ItemID2, newType);

								if (status5 != 0)
								{
									cout << endl;
									itemmanager4.ViewItem();
									cout << endl;
									cout << setw(90) << " " << "Successfully edited item with ID: " << ItemID2 << endl;
									cout << setw(80) << " " << "Edit more item? ('Y' to edit more/'N' to back to item menu)" << endl;
									cout << setw(90) << " " << "Ans: ";
									cin >> again;
								}

								else
								{
									cout << endl;
									itemmanager4.ViewItem();
									cout << endl;
									cout << setw(90) << " " << "Unable to edit item." << endl;
									cout << setw(80) << " " << "Edit more item? ('Y' to edit more/'N' to back to item menu)" << endl;
									cout << setw(90) << " " << "Ans: ";
									cin >> again;
								}
							}
					} while (again == 'Y' || again == 'y');
					ItemMenu();
			}

			else if (itemchoice == 4) //user choose delete item
			{
				char again;
				do
				{
					Item* item4 = new Item();
					ItemManager itemmanager3;

					system("cls");
					system("Color F0");

					header();

					cout << setw(87) << " " << "---------- Item Available ----------" << endl;
					cout << endl;
					
					itemmanager3.ViewItem();
					cout << endl;
					cout << endl;
					
					cout << setw(87) << " " << "********** Delete Item **********" << endl;

					string itemID1;
					cout << endl;
					cout << setw(80) << " " << "1. Please enter item's id to be deleted (Eg: I001): ";
					cin.ignore(1);
					getline(cin, itemID1);

					if (itemID1.front() == '0') //quit add item//
					{
						ItemMenu();
					}

					bool checkID = itemmanager3.checkID(itemID1);
					bool IDexist = itemmanager3.IDexist(itemID1);

					while (IDexist || !checkID)
					{
						while (IDexist) // Id not exist
						{
							cout << endl;
							cout << setw(82) << " " << "Item ID not exist. Please enter the correct item id: ";
							getline(cin, itemID1);
							IDexist = itemmanager3.IDexist(itemID1);
							checkID = itemmanager3.checkID(itemID1);
						}

						while (!checkID) //ID exist in order_product table
						{
							cout << endl;
							cout << setw(80) << " " << "Item ID exist in 'Order_Product' table. Please enter the correct item id: ";
							getline(cin, itemID1);
							checkID = itemmanager3.checkID(itemID1);
							IDexist = itemmanager3.IDexist(itemID1);
						}
					}

					char confirm;
					int status6;
					cout << endl;
					cout << setw(90) << " " << "Confirm delete item " << itemID1 << " ? (Y/N): ";
					cin >> confirm;
					if (confirm == 'y' || confirm == 'Y')
						status6 = itemmanager3.DeleteItem(itemID1);
					else
						status6 = 0;

					if (status6 != 0)
					{
						cout << endl;
						itemmanager3.ViewItem();
						cout << endl;
						cout << setw(90) << " " << "Successfully deleted item with ID: " << itemID1<< endl;
						cout << setw(80) << " " << "Delete more item? ('Y' to add more/'N' to back to item menu)" << endl;
						cout << setw(90) << " " << "Ans: ";
						cin >> again;
					}

					else
					{
						cout << endl;
						itemmanager3.ViewItem();
						cout << endl;
						cout << setw(90) << " " << "Unable to delete item." << endl;
						cout << setw(80) << " " << "Delete more item? ('Y' to add more/'N' to back to item menu)" << endl;
						cout << setw(90) << " " << "Ans: ";
						cin >> again;
					}
				} while (again == 'Y' || again == 'y');
				ItemMenu();
			}
			else if (itemchoice == 5)
				mainmenu();
		}
	}
}


void CustomerMenu()
{
	//choose which submenu to access//
	system("cls");
	system("color F0");
	int cuschoice;
	header();

	cout << setw(98) << " " << "Customer Info" << endl;
	cout << endl;
	cout << setw(95) << " " << "1. Add customer" << endl;
	cout << setw(95) << " " << "2. View Customer" << endl;
	cout << setw(95) << " " << "3. Edit Customer" << endl;
	cout << setw(95) << " " << "4. Back" << endl;
	cout << endl;
	cout << setw(80) << " " << "Please enter the number of the menu you would like to access: ";
	cin >> cuschoice;

	//validate user input//
	while (1)
	{

		//if user input non integer
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(2);
			cout << endl;
			cout << setw(90) << " " << "You have entered wrong input,please try again." << endl;
			cout << setw(80) << " " << "Please enter the number of the menu you would like to access: ";
			cin >> cuschoice;
		}
		else if (!cin.fail()) //if user insert integer
		{
			while (cuschoice < 1 || cuschoice>4) //if user input invalid choice
			{
				cout << endl;
				cout << setw(90) << " " << "Choice not valid. Please try again." << endl;
				cout << setw(80) << " " << "Please enter the number of the menu you would like to access: ";
				cin >> cuschoice;
				break;
			}
			if (cuschoice == 1) //user choose add customer
			{
				char again;
				do
				{
					//add a new customer//
					Customer* customer1 = new Customer();
					CustomerManager customermanager;

					system("cls");
					system("Color F0");

					header();

					cout << setw(92) << " " << "----- List of Customer -----" << endl;
					cout << endl;
					customermanager.ViewCustomer();
					cout << endl;
					cout << endl;
					cout << endl;
					cout << setw(90) << " " << "***** Add New Customer *****" << endl;

					string cusID, cusName, cusContacts, cusAddress;
					cout << endl;
					cout << setw(84) << " " << "1. Please enter customer's id (Eg: C0001): ";
					cin.ignore(1);
					getline(cin, cusID);

					bool IDexist = customermanager.checkcus(cusID);

					if (cusID.front() == '0') //quit add item//
					{
						CustomerMenu();
					}

					while (cusID.front() != 'C' || !IDexist)
					{
						while (!IDexist) //ID already exist
						{
							cout << endl;
							cout << setw(85) << " " << "Customer id existed. Please enter a new customer id: ";
							getline(cin, cusID);
							IDexist = customermanager.checkcus(cusID);
						}

						while (cusID.front() != 'C')
						{
							cout << endl;
							cout << setw(80) << " " << "Customer id must starts with 'C'.Please enter the correct id: ";
							getline(cin, cusID);
							IDexist = customermanager.checkcus(cusID);
						}
					}

					cout << endl;
					cout << setw(88) << " " << "2. Please enter customer's name: ";
					getline(cin, cusName);
					cout << endl;

					cout << setw(82) << " " << "3. Please enter customer_contacts (Without '-'): ";
					getline(cin, cusContacts);
					cout << endl;

					cout << setw(88) << " " << "4. Please enter customer_address: ";
					getline(cin, cusAddress);
					cout << endl;

					customer1->customer_id = cusID;
					customer1->customer_name = cusName;
					customer1->customer_contacts = cusContacts;
					customer1->customer_address = cusAddress;

					int status7 = customermanager.AddCustomer(customer1);

					if (status7 != 0)
					{
						customermanager.ViewCustomer();
						cout << endl;
						cout << endl;
						cout << setw(90) << " " << "Successfully added a new customer." << endl;
						cout << setw(80) << " " << "Add more customer? ('Y' to add more/'N' to back to customer menu)" << endl;
						cout << setw(90) << " " << "Ans: ";
						cin >> again;
					}

					else
					{
						customermanager.ViewCustomer();
						cout << endl;
						cout << "Unable to add a new item.";
						cout << setw(80) << " " << "Add more item? ('Y' to add more/'N' to back to item menu)" << endl;
						cout << setw(90) << " " << "Ans: ";
						cin >> again;
					}
				} while (again == 'Y' || again == 'y');
				CustomerMenu();
			}
			else if (cuschoice == 2)
			{
				//view list of customer//
				Customer* customer2 = new Customer();
				CustomerManager customermanager1;
				char back;

				system("cls");
				system("Color F0");

				header();
				cout << endl;
				cout << setw(92) << " " << "----- List of Customer -----" << endl;
				cout << endl;

				customermanager1.ViewCustomer();
				cout << endl;
				cout << "\n" << setw(90) << " " << "Back to item menu? (Y): ";
				cin >> back;

				while (back != 'y' && back != 'Y')
				{
					cout << endl;
					cout << setw(85) << " " << "Invalid choice. Please enter again: ";
					cin >> back;
				}
				CustomerMenu();
			}

			else if (cuschoice == 3) //user choose edit customer
			{
				char again;
				do
				{
					Customer* customer3 = new Customer();
					CustomerManager customermanager2;

					system("cls");
					system("Color F0");

					header();
					cout << setw(88) << " " << "---------- List of Customer ----------" << endl;
					cout << endl;

					customermanager2.ViewCustomer();
					cout << endl;
					cout << endl;
					cout << endl;
					cout << setw(88) << " " << "********** Edit Customer **********" << endl;
					cout << endl;

					string cusID2;
					int cuseditchoice;
					cout << setw(80) << " " << "1. Please enter customer's id to be edited (Eg: C0001): ";
					cin.ignore(1);
					getline(cin, cusID2);

					if (cusID2.front() == '0') //quit edit customer//
					{
						CustomerMenu();
					}

					bool IDexist2 = customermanager2.checkcus(cusID2);

					while (IDexist2) //cusID not exist
					{
						cout << endl;
						cout << setw(83) << " " << "Customer ID not exist. Please enter the correct id: ";
						getline(cin, cusID2);
						cout << endl;
						IDexist2 = customermanager2.checkcus(cusID2);
					}

					cout << endl;
					cout<< setw(95) << " " << "0. Quit Editing" << endl;
					cout << setw(95) << " " << "1. Customer Name" << endl;
					cout << setw(95) << " " << "2. Customer Contacts" << endl;
					cout << setw(95) << " " << "3. Customer Address" << endl;
					cout << endl;
					cout << setw(80) << " " << "Please enter the number you would like to edit: ";
					cin >> cuseditchoice;

					if (cuseditchoice== 0) //quit edit customer//
					{
						CustomerMenu();
					}

					while (cuseditchoice < 1 || cuseditchoice>3)
					{
						if (cin.fail()) //if user input non integer
						{
							cin.clear();
							cin.ignore(2);
							cout << endl;
							cout << setw(80) << " " << "You have entered wrong input,please try again." << endl;
							cout << setw(80) << " " << "Please enter the number you would like to edit: ";
							cin >> cuseditchoice;
						}
						else if (!cin.fail()) //if user insert integer
						{
							cout << endl;
							cout << setw(90) << " " << "Choice not valid. Please try again." << endl;
							cout << setw(80) << " " << "Please enter the number you would like to edit: ";
							cin >> cuseditchoice;
							break;
						}
					}

							if (cuseditchoice == 1) //edit name
							{
								string newName2;
								cout << endl;
								cout << setw(93) << " " << "Please enter new name: ";
								cin.ignore(1);
								getline(cin, newName2);
								int status8 = customermanager2.editIName(cusID2, newName2);

								if (status8 != 0)
								{
									cout << endl;
									customermanager2.ViewCustomer();
									cout << endl;
									cout << endl;
									cout << setw(85) << " " << "Successfully edited customer with ID: " << cusID2 << endl;
									cout << setw(80) << " " << "Edit more customer? ('Y' to edit more/'N' to back to customer menu)" << endl;
									cout << setw(90) << " " << "Ans: ";
									cin >> again;
								}

								else
								{
									cout << endl;
									customermanager2.ViewCustomer();
									cout << endl;
									cout << endl;
									cout << setw(90) << " " << "Unable to edit customer." << endl;
									cout << setw(80) << " " << "Edit more customer? ('Y' to edit more/'N' to back to customer menu)" << endl;
									cout << setw(90) << " " << "Ans: ";
									cin >> again;
								}

							}
							if (cuseditchoice == 2) //edit contacts
							{
								string newContacts;
								cout << endl;
								cout << setw(90) << " " << "Please enter new contacts: ";
								cin.ignore(1);
								getline(cin, newContacts);
								int status9 = customermanager2.editContacts(cusID2, newContacts);

								if (status9 != 0)
								{
									cout << endl;
									customermanager2.ViewCustomer();
									cout << endl;
									cout << endl;
									cout << setw(85) << " " << "Successfully edited customer with ID: " << cusID2 << endl;
									cout << setw(80) << " " << "Edit more customer? ('Y' to edit more/'N' to back to customer menu)" << endl;
									cout << setw(90) << " " << "Ans: ";
									cin >> again;
								}

								else
								{
									cout << endl;
									customermanager2.ViewCustomer();
									cout << endl;
									cout << endl;
									cout << setw(90) << " " << "Unable to edit customer." << endl;
									cout << setw(80) << " " << "Edit more customer? ('Y' to edit more/'N' to back to customer menu)" << endl;
									cout << setw(90) << " " << "Ans: ";
									cin >> again;
								}
							}
							if (cuseditchoice == 3) //edit address
							{
								string newAddress;
								cout << endl;
								cout << setw(93) << " " << "Please enter new address: ";
								cin.ignore(1);
								getline(cin, newAddress);

								int status10 = customermanager2.editAddress(cusID2, newAddress);

								if (status10 != 0)
								{
									cout << endl;
									customermanager2.ViewCustomer();
									cout << endl;
									cout << endl;
									cout << setw(85) << " " << "Successfully edited customer with ID: " << cusID2 << endl;
									cout << setw(80) << " " << "Edit more customer? ('Y' to edit more/'N' to back to customer menu)" << endl;
									cout << setw(90) << " " << "Ans: ";
									cin >> again;
								}

								else
								{
									cout << endl;
									customermanager2.ViewCustomer();
									cout << endl;
									cout << endl;
									cout << setw(90) << " " << "Unable to edit customer." << endl;
									cout << setw(80) << " " << "Edit more customer? ('Y' to edit more/'N' to back to customer menu)" << endl;
									cout << setw(90) << " " << "Ans: ";
									cin >> again;
								}
							}	
				} while (again == 'Y' || again == 'y');
				CustomerMenu();
			}
			else if (cuschoice == 4) //user choose back
				mainmenu();
		}

	}
}

void CuOrderMenu()
{
	//choose which submenu to access//
	system("cls");
	system("color F0");
	int curchoice;
	header();

	cout << setw(98) << " " << "Current Order Menu" << endl;
	cout << endl;
	cout << setw(95) << " " << "1. Add new order" << endl;
	cout << setw(95) << " " << "2. View order" << endl;
	cout << setw(95) << " " << "3. Edit order" << endl;
	cout << setw(95) << " " << "4. Delete order" << endl;
	cout << setw(95) << " " << "5. Back" << endl;
	cout << endl;
	cout << setw(80) << " " << "Please enter the number of the menu you would like to access: ";
	cin >> curchoice;

	//validate user input//
	while (1)
	{
		//if user input non integer
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(2);
			cout << endl;
			cout << setw(90) << " " << "You have entered wrong input,please try again." << endl;
			cout << setw(80) << " " << "Please enter the number of the menu you would like to access: ";
			cin >> curchoice;
		}
		else if (!cin.fail()) //if user insert integer
		{
			while (curchoice < 1 || curchoice>5) //if user input invalid choice
			{
				cout << endl;
				cout << setw(90) << " " << "Choice not valid. Please try again." << endl;
				cout << setw(80) << " " << "Please enter the number of the menu you would like to access: ";
				cin >> curchoice;
				break;
			}
			if (curchoice == 1) //user choose add new order
			{
				char again;
				do
				{
					//add a new order//
					Order* order1 = new Order();
					OrderManager ordermanager;
					CustomerManager customermanager3;

					system("cls");
					system("Color F0");

					header();

					cout << setw(92) << " " << "----- List of All Order -----" << endl;
					cout << endl;
					ordermanager.ViewAllOrder();
					cout << endl;
					cout << endl;
					cout << endl;
					cout << setw(92) << " " << "----- List of Customer -----" << endl;
					cout << endl;
					customermanager3.ViewCustomer();
					cout << endl;
					cout << endl;
					cout << endl;
					cout << setw(92) << " " << "***** Add New Order *****" << endl;
					cout << endl;

					string orderID, customerID, orderStatus, orderDate, paymentStatus;
					int orderRating;
					double orderPrice;

					cin.ignore(1);
					cout << setw(85) << " " << "1. Please enter order's id: (Eg: O00001): ";
					getline(cin, orderID);
					bool orderexist = ordermanager.checkOrderExist1(orderID);

					if (orderID.front() == '0') //quit add item//
					{
						CuOrderMenu();
					}

					while (orderID.front() != 'O' || !(orderexist))
					{
						while (orderID.front() != 'O')
						{
							cout << endl;
							cout << setw(80) << " " << "Order id must starts with 'O'.Please enter the correct id: "; //ID doesnt start with O
							getline(cin, orderID);
							orderexist = ordermanager.checkOrderExist1(orderID);
						}
						while (!orderexist)
						{
							cout << endl;
							cout << setw(85) << " " << "Order id existed. Please enter a new order id: ";
							getline(cin, orderID);
							orderexist = ordermanager.checkOrderExist1(orderID);
						}

					}

					cout << endl;
					cout << setw(85) << " " << "2. Please enter customer's id (Eg:C0001): ";
					getline(cin, customerID);

					//check customer exist//
					bool cusIDexist = customermanager3.checkcus(customerID);

					while (cusIDexist) //cusID not exist
					{
						cout << endl;
						cout << setw(90) << " " << "Customer ID not exist. Failed to edit." << endl;
						cout << setw(90) << " " << "Please enter customer's id again: ";
						getline(cin, customerID);
						cusIDexist = customermanager3.checkcus(customerID);
					}

					cout << endl;
					cout << setw(85) << " " << "3. Please enter order's status (C/N): ";
					getline(cin, orderStatus);
					while ((orderStatus.front() != 'C') && (orderStatus.front() != 'N'))
					{
						cout << endl;
						cout << setw(85) << " " << "Enter 'C' or 'N' only. Please enter order status again: ";
						getline(cin, orderStatus);
					}

					cout << endl;
					cout << setw(85) << " " << "4. Please enter order's rating (1-5,0 for incomplete order): ";
					cin >> orderRating;

					while (1)
					{
						if (cin.fail()) //user enter non integer
						{
							cin.clear();
							cin.ignore(2);
							cout << endl;
							cout << setw(85) << " " << "You have entered wrong input,please try again." << endl;
							cout << setw(85) << " " << "Please enter the order rating again: ";
							cin >> orderRating;
						}

						if (!cin.fail()) //user enter integer
						{
							if (orderRating < 0 || orderRating>5)
							{
								cout << endl;
								cout << setw(85) << " " << "Enter number between 0 to 5 only, please enter the order rating again: ";
								cin >> orderRating;
							}
							else
								break;
						}

					}

					cout << endl;
					cout << setw(85) << " " << "5. Please enter order's total price: ";
					cin >> orderPrice;
					while (1)
					{
						if (cin.fail())
						{
							cin.clear();
							cin.ignore(2);
							cout << endl;
							cout << setw(85) << " " << "You have entered wrong input,please try again." << endl;
							cout << setw(85) << " " << "Please enter the total price again: ";
							cin >> orderPrice;
						}
						if (!cin.fail())
							break;
					}

					cout << endl;
					cout << setw(85) << " " << "6. Please enter order's date (YYYY-MM-DD): ";
					cin.ignore(1);
					cin >> orderDate;
					cout << endl;

					cout << setw(86) << " " << "7. Please enter payment's status (P/U): ";
					cin.ignore(1);
					getline(cin, paymentStatus);
					while ((paymentStatus.front() != 'P') && (paymentStatus.front() != 'U'))
					{
						cout << endl;
						cout << setw(85) << " " << "Enter 'P' or 'U' only. Please enter the payment status again: ";
						getline(cin, paymentStatus);
						cout << endl;
					}

					order1->order_id = orderID;
					order1->customer_id = customerID;
					order1->order_status = orderStatus;
					order1->order_rating = orderRating;
					order1->order_totalprice = orderPrice;
					order1->order_date = orderDate;
					order1->payment_status = paymentStatus;

					int status11 = ordermanager.AddOrder(order1);

					if (status11 != 0)
					{
						cout << endl;
						ordermanager.ViewAllOrder();
						cout << endl;
						cout << endl;
						cout << setw(90) << " " << "Successfully added a new order." << endl;
						cout << setw(80) << " " << "Add more order? ('Y' to add more/'N' to back to current order menu)" << endl;
						cout << setw(90) << " " << "Ans: ";
						cin >> again;
					}

					else
					{
						cout << endl;
						ordermanager.ViewAllOrder();
						cout << endl;
						cout << endl;
						cout << setw(90) << " " << "Unable to add a new order.";
						cout << setw(80) << " " << "Add more order? ('Y' to add more/'N' to back to order menu)" << endl;
						cout << setw(90) << " " << "Ans: ";
						cin >> again;
					}
				} while (again == 'Y' || again == 'y');
				CuOrderMenu();

			}
			else if (curchoice == 2) //user choose to view order
			{
				//view list of order//
				Order* order2 = new Order();
				OrderManager ordermanager1;
				char back;

				system("cls");
				system("Color F0");

				header();
				cout << endl;
				cout << setw(90) << " " << "----List of Current Order----" << endl;
				cout << endl;
				ordermanager1.ViewCurrentOrder();
				cout << endl;
				cout << "\n" << setw(90) << " " << "Back to current order menu? (Y): ";
				cin >> back;

				while (back != 'y' && back != 'Y')
				{
					cout << endl;
					cout << setw(88) << " " << "Invalid choice. Please enter again: ";
					cin >> back;
				}
				CuOrderMenu();
			}

			else if (curchoice == 3) //user choose edit order
			{
				char again;
				do
				{
					Order* Order3 = new Order();
					OrderManager ordermanager2;
					CustomerManager customermanager4;

					system("cls");
					system("Color F0");

					header();
					cout << endl;
					cout << setw(90) << " " << "----List of Current Order----" << endl;
					cout << endl;

					ordermanager2.ViewCurrentOrder();
					cout << endl;
					cout << endl;
					cout << endl;
					cout << setw(92) << " " << "----- List of Customer -----" << endl;
					cout << endl;
					customermanager4.ViewCustomer();
					cout << endl;
					cout << endl;
					cout << endl;
					cout << setw(90) << " " << "********** Edit Current Order **********" << endl;

					string OrderID2;
					int cureditchoice;
					cout << endl;
					cout << setw(80) << " " << "1. Please enter order's id to be edited (Eg: O00001): ";
					cin.ignore(1);
					getline(cin, OrderID2);

					if (OrderID2.front() == '0') //quit add item//
					{
						CuOrderMenu();
					}

					bool IDexist3 = ordermanager2.checkOrderExist(OrderID2);

					while (IDexist3) //OrderID not exist
					{
						cout << endl;
						cout << setw(85) << " " << "Order ID not exist. Failed to edit." << endl;
						cout << setw(90) << " " << "Please enter order's id again: ";
						getline(cin, OrderID2);
						IDexist3 = ordermanager2.checkOrderExist(OrderID2);
					}

					cout << endl;
					cout << setw(95) << " " << "0. Quit Editing" << endl;
					cout << setw(95) << " " << "1. Customer ID" << endl;
					cout << setw(95) << " " << "2. Order Status" << endl;
					cout << setw(95) << " " << "3. Order Rating" << endl;
					cout << setw(95) << " " << "4. Order Total Price" << endl;
					cout << setw(95) << " " << "5. Order Date" << endl;
					cout << setw(95) << " " << "6. Payment Status" << endl;
					cout << endl;
					cout << setw(80) << " " << "Please enter the number of you would like to edit: ";
					cin >> cureditchoice;

					if (cureditchoice ==0) //quit edit order//
					{
						CuOrderMenu();
					}

					while (cureditchoice < 1 || cureditchoice>6)
					{
						if (cin.fail())
						{
							cin.clear();
							cin.ignore(2);
							cout << endl;
							cout << setw(80) << " " << "You have entered wrong input,please try again." << endl;
							cout << setw(80) << " " << "Please enter the number you would like to edit:";
							cin >> cureditchoice;
						}
						else if (!cin.fail())
						{
							cout << endl;
							cout << setw(90) << " " << "Choice not valid. Please try again." << endl;
							cout << setw(80) << " " << "Please enter the number you would like to edit: ";
							cin >> cureditchoice;
							break;
						}
					}

					if (cureditchoice == 1) //edit customer id
					{
						string newcusID;
						cout << endl;
						cout << setw(85) << " " << "Please enter new customer ID (Eg: C0001): ";
						cin.ignore(1);
						getline(cin, newcusID);

						bool cusIDexist2 = customermanager4.checkcus(newcusID);

						while (cusIDexist2) //cusID not exist
						{
							cout << endl;
							cout << setw(85) << " " << "Customer ID not exist. Failed to edit." << endl;
							cout << setw(90) << " " << "Please enter customer id again: ";
							getline(cin, newcusID);
							cusIDexist2 = customermanager4.checkcus(newcusID);
						}

						int status15 = ordermanager2.editcusID(OrderID2, newcusID);

						if (status15 != 0)
						{
							cout << endl;
							ordermanager2.ViewCurrentOrder();
							cout << endl;
							cout << endl;
							cout << setw(90) << " " << "Successfully edited order with ID: " << OrderID2 << endl;
							cout << setw(80) << " " << "Edit more order? ('Y' to edit more/'N' to back to current order menu)" << endl;
							cout << setw(90) << " " << "Ans: ";
							cin >> again;
						}

						else
						{
							cout << endl;
							ordermanager2.ViewCurrentOrder();
							cout << endl;
							cout << endl;
							cout << setw(90) << " " << "Unable to edit order" << endl;
							cout << setw(80) << " " << "Edit more order? ('Y' to edit more/'N' to back to current order menu)" << endl;
							cout << setw(90) << " " << "Ans: ";
							cin >> again;
						}

					}
					if (cureditchoice == 2) //edit order status
					{
						string neworderStatus;
						cout << endl;
						cout << setw(90) << " " << "Please enter new order status (C/N): ";
						cin.ignore(1);
						getline(cin, neworderStatus);

						while ((neworderStatus.front() != 'C') && (neworderStatus.front() != 'N'))
						{
							cout << setw(85) <<" "<< "Enter 'C' or 'N' only. Please enter order status again: ";
							getline(cin, neworderStatus);
						}

						int status16 = ordermanager2.editOrderStatus(OrderID2, neworderStatus);

						if (status16 != 0)
						{
							cout << endl;
							ordermanager2.ViewCompletedOrder();
							cout << endl;
							cout << endl;
							cout << setw(90) << " " << "Successfully edited order with ID: " << OrderID2 << endl;
							cout << setw(80) << " " << "Edit more order? ('Y' to edit more/'N' to back to current order menu)" << endl;
							cout << setw(90) << " " << "Ans: ";
							cin >> again;
						}

						else
						{
							cout << endl;
							ordermanager2.ViewCurrentOrder();
							cout << endl;
							cout << endl;
							cout << setw(90) << " " << "Unable to edit order" << endl;
							cout << setw(80) << " " << "Edit more order? ('Y' to edit more/'N' to back to current order menu)" << endl;
							cout << setw(90) << " " << "Ans: ";
							cin >> again;
						}
					}
					if (cureditchoice == 3) //edit order rating
					{
						int neworderRating;
						cout << endl;
						cout << setw(80) << " " << "Please enter new rating (1-5, 0 for incomplete order): ";
						cin >> neworderRating;

						while (1)
						{
							if (cin.fail()) //user enter non integer
							{
								cin.clear();
								cin.ignore(2);
								cout << endl;
								cout << setw(85) << " " << "You have entered wrong input,please try again." << endl;
								cout << setw(85) << " " << "Please enter the order status again: ";
								cin >> neworderRating;
							}

							if (!cin.fail()) //user enter integer
							{
								if (neworderRating < 0 || neworderRating>5)
								{
									cout << endl;
									cout << setw(77) << " " << "Enter number between 0 to 5 only, please enter the order rating again: ";
									cin >> neworderRating;
								}
								else
									break;
							}
						}

						int status17 = ordermanager2.editOrderRating(OrderID2, neworderRating);

						if (status17 != 0)
						{

							cout << endl;
							ordermanager2.ViewCurrentOrder();
							cout << endl;
							cout << endl;
							cout << setw(90) << " " << "Successfully edited order with ID: " << OrderID2 << endl;
							cout << setw(80) << " " << "Edit more order? ('Y' to edit more/'N' to back to current order menu)" << endl;
							cout << setw(90) << " " << "Ans: ";
							cin >> again;
						}

						else
						{
							cout << endl;
							ordermanager2.ViewCurrentOrder();
							cout << endl;
							cout << endl;
							cout << setw(90) << " " << "Unable to edit order" << endl;
							cout << setw(80) << " " << "Edit more order? ('Y' to edit more/'N' to back to current order menu)" << endl;
							cout << setw(90) << " " << "Ans: ";
							cin >> again;
						}
					}

					if (cureditchoice == 4) //edit order total price
					{
						double newTotalPrice;
						cout << endl;
						cout << setw(90) << " " << "Please enter new total price: ";
						cin >> newTotalPrice;

						while (1)
						{
							if (cin.fail())
							{
								cin.clear();
								cin.ignore(2);
								cout << endl;
								cout << setw(85) << " " << "You have entered wrong input,please try again." << endl;
								cout << setw(85) << " " << "Please enter the order total price again: ";
								cin >> newTotalPrice;
							}
							if (!cin.fail())
								break;
						}

						int status18 = ordermanager2.editTotalPrice(OrderID2, newTotalPrice);

						if (status18 != 0)
						{

							cout << endl;
							ordermanager2.ViewCurrentOrder();
							cout << endl;
							cout << endl;
							cout << setw(90) << " " << "Successfully edited order with ID: " << OrderID2 << endl;
							cout << setw(80) << " " << "Edit more order? ('Y' to edit more/'N' to back to current order menu)" << endl;
							cout << setw(90) << " " << "Ans: ";
							cin >> again;
						}

						else
						{
							cout << endl;
							ordermanager2.ViewCurrentOrder();
							cout << endl;
							cout << endl;
							cout << setw(90) << " " << "Unable to edit order" << endl;
							cout << setw(80) << " " << "Edit more order? ('Y' to edit more/'N' to back to current order menu)" << endl;
							cout << setw(90) << " " << "Ans: ";
							cin >> again;
						}
					}

					if (cureditchoice == 5) //edit order date
					{
						string newOrderDate;
						cout << endl;
						cout << setw(80) << " " << "Please enter new order date (YYYY-MM-DD): ";
						cin.ignore(1);
						getline(cin, newOrderDate);

						int status19 = ordermanager2.editOrderDate(OrderID2, newOrderDate);

						if (status19 != 0)
						{
							cout << endl;
							ordermanager2.ViewCurrentOrder();
							cout << endl;
							cout << endl;
							cout << setw(90) << " " << "Successfully edited order with ID: " << OrderID2 << endl;
							cout << setw(80) << " " << "Edit more order? ('Y' to edit more/'N' to back to current order menu)" << endl;
							cout << setw(90) << " " << "Ans: ";
							cin >> again;
						}

						else
						{
							cout << endl;
							ordermanager2.ViewCurrentOrder();
							cout << endl;
							cout << endl;
							cout << setw(90) << " " << "Unable to edit order" << endl;
							cout << setw(80) << " " << "Edit more order? ('Y' to edit more/'N' to back to current order menu)" << endl;
							cout << setw(90) << " " << "Ans: ";
							cin >> again;
						}
					}

					if (cureditchoice == 6) //edit payment status
					{
						string newPaymentStatus;
						cout << endl;
						cout << setw(90) << " " << "Please enter payment status (P/U): ";
						cin.ignore(1);
						getline(cin, newPaymentStatus);

							while ((newPaymentStatus.front() != 'P') && (newPaymentStatus.front() != 'U'))
							{
								cout << endl;
								cout << setw(80) <<" "<< "Enter 'P' or 'U' only. Please enter the payment status again: ";
								getline(cin, newPaymentStatus);
							}

						int status20 = ordermanager2.editPaymentStatus(OrderID2, newPaymentStatus);

						if (status20 != 0)
						{
							cout << endl;
							ordermanager2.ViewCurrentOrder();
							cout << endl;
							cout << endl;
							cout << setw(90) << " " << "Successfully edited order with ID: " << OrderID2 << endl;
							cout << setw(80) << " " << "Edit more order? ('Y' to edit more/'N' to back to current order menu)" << endl;
							cout << setw(90) << " " << "Ans: ";
							cin >> again;
						}

						else
						{
							cout << endl;
							ordermanager2.ViewCurrentOrder();
							cout << endl;
							cout << endl;
							cout << setw(90) << " " << "Unable to edit order" << endl;
							cout << setw(80) << " " << "Edit more order? ('Y' to edit more/'N' to back to current order menu)" << endl;
							cout << setw(90) << " " << "Ans: ";
							cin >> again;
						}
					}
				} while (again == 'Y' || again == 'y');
				CuOrderMenu();
			}


			else if (curchoice == 4) //user choose delete order
			{
				char again;
				do
				{
					Order* order4 = new Order();
					OrderManager ordermanager3;
					OrderProductManager orderproductmanager4;

					system("cls");
					system("Color F0");

					header();
					cout << endl;
					cout << setw(92) << " " << "----- List of Current Order -----" << endl;
					cout << endl;
					ordermanager3.ViewCurrentOrder();
					cout << endl;
					cout << endl;
					cout << endl;
					cout << setw(92) << " " << "----- List of Order_product -----" << endl;
					cout << endl;
					orderproductmanager4.ViewOrderProduct();
					cout << endl;
					cout << endl;
					cout << endl;
					cout << setw(90) << " " << "********** Delete Order **********" << endl;
					cout << endl;

					string curID1;
					cout << setw(75) << " " << "1. Please enter order's id to be deleted (Eg: O00001): ";
					cin.ignore(1);
					getline(cin, curID1);

					if (curID1.front() =='0') //quit edit order//
					{
						CuOrderMenu();
					}

					bool checkcurID = ordermanager3.checkcurID(curID1);
					bool checkcoID = ordermanager3.checkcoID(curID1);

					while ((!checkcurID) || (!checkcoID))
					{
						while (!checkcurID)
						{
							cout << endl;
							cout << setw(75) << " " << "Order ID exist in 'Order_Product' table. Failed to delete." << endl;
							cout << setw(88) << " " << "Please enter order's id again: ";
							getline(cin, curID1);
							checkcurID = ordermanager3.checkcurID(curID1);
							checkcoID = ordermanager3.checkcoID(curID1);
							break;
						}


						while (!checkcoID)
						{
							cout << endl;
							cout << setw(88) << " " << "Unable to delete completed order." << endl;
							cout << setw(88) << " " << "Please enter order's id again: ";
							getline(cin, curID1);
							checkcoID = ordermanager3.checkcoID(curID1);
							checkcurID = ordermanager3.checkcurID(curID1);
						}
					}


					char confirm;
					int status12;
					cout << endl;
					cout << setw(90) << " " << "Confirm delete order " << curID1 << " ? (Y/N): ";
					cin >> confirm;
					if (confirm == 'y' || confirm == 'Y')
						status12 = ordermanager3.DeleteOrder(curID1);
					else CuOrderMenu();

					if (status12 != 0)
					{
						cout << endl;
						ordermanager3.ViewCurrentOrder();
						cout << endl;
						cout << endl;
						cout << setw(90) << " " << "Successfully deleted order with ID: " << curID1 << endl;
						cout << setw(80) << " " << "Delete more order? ('Y' to add more/'N' to back to current order menu)" << endl;
						cout << setw(90) << " " << "Ans: ";
						cin >> again;
					}

					else
					{
						cout << endl;
						ordermanager3.ViewCurrentOrder();
						cout << endl;
						cout << endl;
						cout << setw(90) << " " << "Unable to delete order." << endl;
						cout << setw(80) << " " << "Delete more order? ('Y' to add more/'N' to back to current order menu)" << endl;
						cout << setw(90) << " " << "Ans: ";
						cin >> again;
					}
				} while (again == 'Y' || again == 'y');
				CuOrderMenu();
			}
			else if (curchoice == 5)
				mainmenu();
		}
	}
}


void CoOrderMenu()
{
	//choose which submenu to access//
	system("cls");
	system("color F0");
	int cochoice;
	header();

	cout << setw(90) << " " << "Report of Completed Order Menu" << endl;
	cout << endl;
	cout << setw(92) << " " << "1. View Completed Order" << endl;
	cout << setw(92) << " " << "2. Report of Average Rating" << endl;
	cout << setw(92) << " " << "3. Report of Total Sales" << endl;
	cout << setw(92) << " " << "4. Back" << endl;
	cout << endl;
	cout << setw(80) << " " << "Please enter the number of the menu you would like to access: ";
	cin.ignore(1);
	cin >> cochoice;

	//validate user input//
	while (1)
	{
		//if user input non integer
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(2);
			cout << endl;
			cout << setw(130) << "You have entered wrong input,please try again." << endl;
			cout << setw(80) << " " << "Please enter the number of the menu you would like to access:";
			cin >> cochoice;
		}
		else if (!cin.fail()) //if user insert integer
		{
			while (cochoice < 1 || cochoice>4) //if user input invalid choice
			{
				cout << endl;
				cout << setw(90) << " " << "Choice not valid. Please try again." << endl;
				cout << setw(80) << " " << "Please enter the number of the menu you would like to access:";
				cin >> cochoice;
				break;
			}
			if (cochoice == 1) //user choose view completed order
			{
				//view completed order//
				Order* order1 = new Order();
				OrderManager ordermanager;
				char back;

				system("cls");
				system("Color F0");

				header();
				cout << setw(80) << " " << "---------- List of Completed Order ----------" << endl;
				cout << endl;
				ordermanager.ViewCompletedOrder();
				cout << endl;
				cout << endl;
				cout << "\n" << setw(85) << " " << "Back to completed order menu? (Y): ";
				cin >> back;

				while (back != 'y' && back != 'Y')
				{
					cout << endl;
					cout << endl;
					cout << setw(85) << " " << "Invalid choice. Please enter again: ";
					cin >> back;
				}
				CoOrderMenu();
			}
			if (cochoice == 2) //user choose view average rating
			{
				//view average rating//
				Order* order2 = new Order();
				OrderManager ordermanager1;
				string beginDate, endDate;
				char back;

				system("cls");
				system("Color F0");

				header();
				cout << setw(80) <<" " << "Report of Average Rating of Orders Given By Buyers" << endl;
				cout << "\n" << setw(55) << " " << "Please enter the beginning of the date of average rating you would like to view: (Eg: YYYY-MM-DD): ";
				cin.ignore(1);
				getline(cin, beginDate);

				cout << "\n" << setw(55) << " " << "Please enter the end of the date of average rating you would like to view (Eg: YYYY-MM-DD): ";
				getline(cin, endDate);

				cout << endl;
				cout << endl;
				cout << setw(70) <<" " << "--- List of completed orders between " << beginDate << " and " << endDate << " ---" << endl;
				cout << endl;
				ordermanager1.ViewRating(beginDate, endDate);
				ordermanager1.viewAverageRating(beginDate, endDate);
				cout << endl;
				cout << "\n" << setw(90) << " " << "Back to completed order menu? (Y): ";
				cin >> back;

				while (back != 'y' && back != 'Y')
				{
					cout << endl;
					cout << setw(88) << " " << "Invalid choice. Please enter again: ";
					cin >> back;
				}
				CoOrderMenu();
			}
			if (cochoice == 3) //user choose view total sales
			{
				//view total sales//
				Order* order2 = new Order();
				OrderManager ordermanager1;
				string beginDate, endDate;
				char back;

				system("cls");
				system("Color F0");
				header();
				cout << setw(90) << " " << "Report of Total Sales" << endl;
				cout << "\n" << setw(55) << " " << "Please enter the beginning of the date of average rating you would like to view (Eg: YYYY-MM-DD): ";
				cin.ignore(1);
				getline(cin, beginDate);

				cout << "\n" << setw(55) << " " << "Please enter the end of the date of average rating you would like to view (Eg: YYYY-MM-DD): ";
				getline(cin, endDate);

				cout << endl;
				cout << endl;
				cout << setw(70) << " " << "--- List of completed orders between " << beginDate << " and " << endDate << " ---" << endl;

				ordermanager1.ViewSales(beginDate,endDate);
				ordermanager1.ViewTotalSales(beginDate, endDate);
				cout << endl;
				cout << "\n" << setw(90) << " " << "Back to completed order menu? (Y): ";
				cin >> back;

				while (back != 'y' && back != 'Y')
				{
					cout << endl;
					cout << setw(88) << " " << "Invalid choice. Please enter again: ";
					cin >> back;
				}
				CoOrderMenu();
			}
			else if (cochoice == 4)
				mainmenu();
		}
	}

}

void OrderProductMenu()
{
	//choose which submenu to access//
	system("cls");
	system("color F0");
	int opchoice;

	header();
	cout << setw(95) << " " << "Order_product Menu" << endl;
	cout << endl;
	cout << setw(92) << " " << "1. Add order_product" << endl;
	cout << setw(92) << " " << "2. View order_product" << endl;
	cout << setw(92) << " " << "3. Edit order_product" << endl;
	cout << setw(92) << " " << "4. Delete order_product" << endl;
	cout << setw(92) << " " << "5. Back" << endl;
	cout << endl;
	cout << setw(80) << " " << "Please enter the number of the menu you would like to access: ";
	cin >> opchoice;

	//validate user input//
	while (1)
	{
		//if user input non integer
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(2);
			cout << endl;
			cout << setw(90) << " " << "You have entered wrong input,please try again." << endl;
			cout << setw(80) << " " << "Please enter the number of the menu you would like to access: ";
			cin >> opchoice;
		}
		else if (!cin.fail()) //if user insert integer
		{
			while (opchoice < 1 || opchoice>5) //if user input invalid choice
			{
				cout << endl;
				cout << setw(90) << " " << "Choice not valid. Please try again." << endl;
				cout << setw(80) << " " << "Please enter the number of the menu you would like to access: ";
				cin >> opchoice;
				break;
			}
			if (opchoice == 1) //user choose add new order_product
			{
				char again;
				do
				{
					//add a order_product//
					OrderProduct* orderproduct1 = new OrderProduct();
					OrderProductManager orderproductmanager;
					OrderManager ordermanager5;
					ItemManager itemmanager5;

					system("cls");
					system("Color F0");

					header();

					cout << setw(92) << " " << "----- List of Order_product -----" << endl;
					cout << endl;
					orderproductmanager.ViewOrderProduct();
					cout << endl;
					cout << endl;
					cout << endl;
					cout << setw(92) << " " << "----- List of Current Order -----" << endl;
					cout << endl;
					ordermanager5.ViewCurrentOrder();
					cout << endl;
					cout << endl;
					cout << endl;
					cout << setw(92) << " " << "----- List of Item Available -----" << endl;
					cout << endl;
					itemmanager5.ViewItem();
					cout << endl;
					cout << endl;
					cout << endl;
					cout << setw(90) << " " << "***** Add New Order_Product *****" << endl;
					cout << endl;

					string orderID1, itemID1, customerRemark;
					int itemquantity;


					cout << setw(85) << " " << "1. Please enter order's id (Eg:O00001): ";
					cin.ignore(1);
					getline(cin, orderID1);

					bool OPexist1 = orderproductmanager.checkOPexist(orderID1, itemID1);
					do
					{
						if (orderID1.front() == '0') //quit add item//
						{
							OrderProductMenu();
						}

						//check if order exist//
						bool IDexist4 = ordermanager5.checkOrderExist(orderID1);

						while (IDexist4) //OrderID not exist
						{
							cout << endl;
							cout << setw(90) << " " << "Order ID not exist. Failed to edit." << endl;
							cout << setw(90) << " " << "Please enter order's id again: ";
							getline(cin, orderID1);
							IDexist4 = ordermanager5.checkOrderExist(orderID1);
						}
						cout << endl;
						cout << setw(85) << " " << "2. Please enter item's id (Eg:I001): ";
						getline(cin, itemID1);

						//check if item exist//
						bool IDexist5 = itemmanager5.IDexist(itemID1);

						while (IDexist5) //itemID not exist
						{
							cout << endl;
							cout << setw(90) << " " << "Item ID not exist. Failed to add." << endl;
							cout << setw(90) << " " << "Please enter item's id again: ";
							getline(cin, itemID1);
							IDexist5 = itemmanager5.IDexist(itemID1);
						}

						bool OPexist1 = orderproductmanager.checkOPexist(orderID1, itemID1);
						while (!OPexist1) //itemID not exist
						{
							cout << endl;
							cout << setw(90) << " " << "Order_product existed." << endl;
							cout << setw(90) << " " << "Please enter new order's id: ";
							getline(cin, orderID1);
							cout << endl;
							cout << setw(90) << " " << "Please enter new item's id: ";
							getline(cin, itemID1);
							OPexist1 = orderproductmanager.checkOPexist(orderID1, itemID1);;
						}

					} while (OPexist1=false); 
					

					cout << endl;
					cout << setw(85) << " " << "3. Please enter item's quantity: ";
					cin >> itemquantity;
					while (1)
					{
						if (cin.fail())
						{
							cin.clear();
							cin.ignore(2);
							cout << endl;
							cout << setw(85) << " " << "You have entered wrong input,please try again." << endl;
							cout << setw(85) << " " << "Please enter the item quantity again: ";
							cin >> itemquantity;
						}
						if (!cin.fail())
							break;
					}

					cout << endl;
					cout << setw(85) << " " << "4. Please enter customer's remark: ";
					cin.ignore(1);
					getline(cin, customerRemark);
					cout << endl;

					orderproduct1->order_id = orderID1;
					orderproduct1->item_id = itemID1;
					orderproduct1->item_quantity = itemquantity;
					orderproduct1->customer_remark = customerRemark;

					int status13 = orderproductmanager.AddOrderProduct(orderproduct1);

					if (status13 != 0)
					{
						cout << endl;
						orderproductmanager.ViewOrderProduct();
						cout << endl;
						cout << endl;
						cout << setw(90) << " " << "Successfully added a new order_product." << endl;
						cout << setw(80) << " " << "Add more order_product? ('Y' to add more/'N' to back to order_product menu)" << endl;
						cout << setw(90) << " " << "Ans: ";
						cin >> again;
					}

					else
					{
						cout << endl;
						orderproductmanager.ViewOrderProduct();
						cout << endl;
						cout << endl;
						cout << setw(90) << " " << "Unable to add a new order_product.";
						cout << setw(80) << " " << "Add more order_product? ('Y' to add more/'N' to back to order_product menu)" << endl;
						cout << setw(90) << " " << "Ans: ";
						cin >> again;
					}
				} while (again == 'Y' || again == 'y');
				OrderProductMenu();
			}
			else if (opchoice == 2)
			{
				//view list of order_product
				OrderProduct* orderproduct2 = new OrderProduct();
				OrderProductManager orderproductmanager1;
				char back;

				system("cls");
				system("Color F0");

				header();
				cout << endl;
				cout << setw(92) << " " << "----- List of Order_product -----" << endl;
				cout << endl;
				orderproductmanager1.ViewOrderProduct();
				cout << endl;
				cout << "\n" << setw(90) << " " << "Back to order_product menu? (Y): ";
				cin >> back;

				while (back != 'y' && back != 'Y')
				{
					cout << endl;
					cout << setw(88) << " " << "Invalid choice. Please enter again: ";
					cin >> back;
				}
				OrderProductMenu();
			}

			else if (opchoice == 3)
			{
				char again;
				do
				{
					OrderProduct* orderproduct3 = new OrderProduct();
					OrderProductManager orderproductmanager2;

					system("cls");
					system("Color F0");

					header();
					cout << endl;
					cout << setw(92) << " " << "----- List of Order_product -----" << endl;
					cout << endl;
					orderproductmanager2.ViewOrderProduct();
					cout << endl;
					cout << endl;
					cout << endl;
					cout << setw(87) << " " << "********** Edit Order_product **********" << endl;

					string orderID3, itemID3;
					int OPeditchoice;
					cout << endl;
					cout << setw(80) << " " << "1. Please enter order id to be edited (Eg: O00001): ";
					cin.ignore(1);
					getline(cin, orderID3);

					if (orderID3.front() == '0') //quit add item//
					{
						OrderProductMenu();
					}

					cout << endl;
					cout << setw(80) << " " << "2. Please enter item id to be edited (Eg: I001): ";
					getline(cin, itemID3);

					if (itemID3.front() == '0') //quit add item//
					{
						OrderProductMenu();
					}

					bool OPexist = orderproductmanager2.checkOPexist(orderID3, itemID3);

					while (OPexist) //itemID not exist
					{
						cout << endl;
						cout << setw(85) << " " << "Order_product not exist. Failed to edit." << endl;
						cout << setw(90) << " " << "Please enter order's id again: ";
						getline(cin, orderID3);
						cout << endl;
						cout << setw(90) << " " << "Please enter item's id again: ";
						getline(cin, itemID3);
						OPexist = orderproductmanager2.checkOPexist(orderID3, itemID3);
					}

					cout << endl;
					cout << setw(95) << " " << "0. Quit Editing" << endl;
					cout << setw(95) << " " << "1. Item Quantity" << endl;
					cout << setw(95) << " " << "2. Customer Remark" << endl;
					cout << endl;
					cout << setw(80) << " " << "Please enter the number you would like to edit: ";
					cin >> OPeditchoice;

					if (OPeditchoice == 0) //quit add item//
					{
						OrderProductMenu();
					}

					while (OPeditchoice < 1 || OPeditchoice>2) //if user input invalid choice
					{
						if (cin.fail())
						{
							cin.clear();
							cin.ignore(2);
							cout << endl;
							cout << setw(80) << " " << "You have entered wrong input,please try again." << endl;
							cout << setw(80) << " " << "Please enter the number you would like to edit:";
							cin >> OPeditchoice;
						}
						else if (!cin.fail())
						{
							cout << endl;
							cout << setw(90) << " " << "Choice not valid. Please try again." << endl;
							cout << setw(80) << " " << "Please enter the number you would like to edit:";
							cin >> OPeditchoice;
							break;
						}
					}

					if (OPeditchoice == 1) //edit item quantity
					{
						int newQuantity;
						cout << endl;
						cout << setw(90) << " " << "Please enter new item quantity: ";
						cin >> newQuantity;

						while (1)
						{
							if (cin.fail())
							{
								cin.clear();
								cin.ignore(2);
								cout << endl;
								cout << setw(85) << " " << "You have entered wrong input,please try again." << endl;
								cout << setw(85) << " " << "Please enter the new quantity again: ";
								cin >> newQuantity;
							}
							if (!cin.fail())
								break;
						}

						int status21 = orderproductmanager2.editQuantity(orderID3, itemID3, newQuantity);

						if (status21 != 0)
						{
							cout << endl;
							orderproductmanager2.ViewOrderProduct();
							cout << endl;
							cout << endl;
							cout << setw(80) << " " << "Successfully edited order_product with order ID || item ID " << orderID3 << " || " << itemID3 << endl;
							cout << setw(80) << " " << "Edit more item? ('Y' to edit more/'N' to back to order_product menu)" << endl;
							cout << setw(90) << " " << "Ans: ";
							cin >> again;
						}

						else
						{
							cout << endl;
							orderproductmanager2.ViewOrderProduct();
							cout << endl;
							cout << endl;
							cout << setw(90) << " " << "Unable to edit order_product" << endl;
							cout << setw(80) << " " << "Edit more item? ('Y' to edit more/'N' to back to order_product menu)" << endl;
							cout << setw(90) << " " << "Ans: ";
							cin >> again;
						}

					}
					if (OPeditchoice == 2) //edit customer_remark
					{
						string newRemark;
						cout << endl;
						cout << setw(90) << " " << "Please enter new customer remark: ";
						cin.ignore(1);
						getline(cin, newRemark);

						int status22 = orderproductmanager2.editRemark(orderID3, itemID3, newRemark);

						if (status22 != 0)
						{
							cout << endl;
							orderproductmanager2.ViewOrderProduct();
							cout << endl;
							cout << endl;
							cout << setw(80) << " " << "Successfully edited order_product with order ID || item ID " << orderID3 << " || " << itemID3 << endl;
							cout << setw(80) << " " << "Edit more item? ('Y' to edit more/'N' to back to order_product menu)" << endl;
							cout << setw(90) << " " << "Ans: ";
							cin >> again;
						}

						else
						{
							cout << endl;
							orderproductmanager2.ViewOrderProduct();
							cout << endl;
							cout << endl;
							cout << setw(90) << " " << "Unable to edit order_product" << endl;
							cout << setw(80) << " " << "Edit more item? ('Y' to edit more/'N' to back to order_product menu)" << endl;
							cout << setw(90) << " " << "Ans: ";
							cin >> again;
						}
					}

			} while (again == 'Y' || again == 'y');
			OrderProductMenu();
			}
 
			else if (opchoice == 4) //user choose delete order_product
			{
				char again;
				do
				{
					OrderProduct* orderproduct4 = new OrderProduct();
					OrderProductManager orderproductmanager3;

					system("cls");
					system("Color F0");

					header();

					cout << endl;
					cout << setw(92) << " " << "----- List of Order_product -----" << endl;
					cout << endl;
					orderproductmanager3.ViewOrderProduct();
					cout << endl;
					cout << endl;
					cout << endl;
					cout << setw(87) << " " << "********** Delete Order_product **********" << endl;
					cout << endl;

					string itemID2, orderID2;

					cout << endl;
					cout << setw(80) << " " << "1. Please enter order's id to be deleted (Eg: O00001): ";
					cin.ignore(1);
					getline(cin, orderID2);

					if (orderID2.front() == '0') //quit add item//
					{
						OrderProductMenu();
					}

					cout << endl;
					cout << setw(80) << " " << "2. Please enter item's id to be deleted (Eg: I001): ";
					getline(cin, itemID2);

					char confirm;
					int status14;
					cout << endl;
					cout << setw(80) << " " << "Confirm delete order_product " << orderID2 << " || " << itemID2 << " ? (Y/N): ";
					cin >> confirm;
					 if(confirm == 'y' || confirm == 'Y')
						status14 = orderproductmanager3.DeleteOrderProduct(itemID2, orderID2);
					else
						OrderProductMenu();

					if (status14 != 0)
					{
						cout << endl;
						orderproductmanager3.ViewOrderProduct();
						cout << endl;
						cout << endl;
						cout << setw(80) << " " << "Successfully delete order_product with ID: " << itemID2 << " || " << orderID2 << endl;
						cout << setw(80) << " " << "Delete more order? ('Y' to add more/'N' to back to order_product menu)" << endl;
						cout << setw(90) << " " << "Ans: ";
						cin >> again;
					}

					else
					{
						cout << endl;
						orderproductmanager3.ViewOrderProduct();
						cout << endl;
						cout << endl;
						cout << setw(90) << " " << "Unable to delete order_product." << endl;
						cout << setw(80) << " " << "Delete more order? ('Y' to add more/'N' to back to order_product menu)" << endl;
						cout << setw(90) << " " << "Ans: ";
						cin >> again;
					}
				} while (again == 'Y' || again == 'y');
				OrderProductMenu();
			}
			else if (opchoice == 5)
			mainmenu();

		}
	}
}



