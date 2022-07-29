#include "Menu.h"
#include <conio.h>

Menu::Menu() {
	//запускает основное меню
	main();
}

//основное меню
void Menu::main(){
	int choose = -1;
	while (choose != 3) {
		system("cls");
		cout << "1.Cards" << endl;
		cout << "2.Payments" << endl;
		cout << "3.Exit" << endl;
		cin >> choose;
		switch (choose) {
			case 1:
			{
				cards();
				break;
			}
			case 2:
			{
				payments();
				break;
			}
			case 3:{
				break;
			}
		}
	}
}

//меню для работы с картами
void Menu::cards() {
	
	int choose = -1;
	while (choose != 3) {
		system("cls");
		cout << "1.All cards" << endl;
		cout << "2.Add money" << endl;
		cout << "3.Add card" << endl;
		cout << "4.Back" << endl;
		cin >> choose;
		switch (choose) {
			case 1:
			{
				store.getAllCards();
				_getch();
				break;
			}
			case 2:
			{
				int index;
				int money;
				store.getAllCards();
				cout << "Enter card number for adding money : ";
				cin >> index;
				cout << "Enter money amount : ";
				cin >> money;
				store.updateBalance(index, money);
				break;
			}
			case 3:
			{
				cin.ignore(numeric_limits<streamsize>::max(), '\n');//функция для игнорирования определенных символов. 
				string name;
				int balance;
				cout << "Enter card name" << endl;
				fflush(stdin);
				getline(cin, name);
				cout << "Enter card balance" << endl;
				cin >> balance;
				cout << "1.Debit" << endl;
				cout << "2.Credit" << endl;
				int type;
				cin >> type;
				Card card(name, balance, type == 1 ? false : true);
				store.addCard(card);
				break;
			}
			case 4:
			{
				main();
				break;
			}
		}
	}
}

//меню для работы с покупками(тратами)
void Menu::payments() {
	int choose = -1;

	while (choose != 13) {
		system("cls");
		cout << "1.All Payments" << endl;
		cout << "2.Make payment" << endl;
		cout << "3.Payment by day" << endl;
		cout << "4.Payment by week" << endl;
		cout << "5.Payment by month" << endl;
		cout << "6.Payment by day and category" << endl;
		cout << "7.Payment by week and category" << endl;
		cout << "8.Payment by month and category" << endl;
		cout << "9.TOP-3 Payment by week" << endl;
		cout << "10.TOP-3 Payment by month" << endl;
		cout << "11.TOP-3 Category by week" << endl;
		cout << "12.TOP-3 Category by month" << endl;
		cout << "13.Back" << endl;
		
		cin >> choose;

		switch (choose) {
			case 1:
			{
				store.getAllPayments();
				_getch();
				break;
			}
			case 2:
			{	
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				string name;
				int day;
				int month;
				int year;
				string category;
				int cost;
				cout << "Enter payment name" << endl;
				fflush(stdin);
				getline(cin, name);
				
				cout << "Enter day" << endl;
				cin >> day;
				cout << "Enter month" << endl;
				cin >> month;
				cout << "Enter year" << endl;
				cin >> year;
				cout << "Select category:" << endl;
				cout << "1.Product" << endl;
				cout << "2.Electoronic" << endl;
				cout << "3.Internet" << endl;
				cout << "4.Clothes" << endl;
				cout << "5.Comunality" << endl;
				cout << "6.Study" << endl;
				cout << "7.Other" << endl;
				
				int cat =-1;
				cin >> cat;

				switch (cat) {
					case 1: {
						category = "Product";
						break;
					}
					case 2: {
						category = "Electoronic";
						break;
					}
					case 3: {
						category = "Internet";
						break;
					}
					case 4: {
						category = "Clothes";
						break;
					}
					case 5: {
						category = "Comunality";
						break;
					}
					case 6: {
						category = "Study";
						break;
					}
					case 7: {
						category = "Other";
						break;
					}
				}

				cout << "Enter cost" << endl;
				cin >> cost;
				Payment payment(name, day, month, year, category, cost);
				int index;
				do {
					system("cls");
					store.getAllCards();
					cout << "Enter card number for making payment:";
					cin >> index;
				} while (!store.makePayment(payment, index));
				break;
			}
			case 3:
			{
				system("cls");
				int day;
				int month;
				int year;
				
				cout << "Enter day" << endl;
				cin >> day;
				cout << "Enter month" << endl;
				cin >> month;
				cout << "Enter year" << endl;
				cin >> year;
				
				store.getAllPaymentsByDay(day, month, year);
				_getch();

				break;
			}
			case 4:
			{	
				system("cls");
				int week;
				int month;
				int year;

				cout << "Enter week" << endl;
				cin >> week;
				cout << "Enter month" << endl;
				cin >> month;
				cout << "Enter year" << endl;
				cin >> year;

				store.getAllPaymentsByWeek(week, month, year);
				_getch();

				break;
			}
			case 5:
			{	system("cls");
				
				int month;
				int year;

				cout << "Enter month" << endl;
				cin >> month;
				cout << "Enter year" << endl;
				cin >> year;

				store.getAllPaymentsByMonth(month, year);
				_getch();
				break;
			}
			case 6:
			{	
				system("cls");
				int day;
				int month;
				int year;
				string category;

				cout << "Enter day" << endl;
				cin >> day;
				cout << "Enter month" << endl;
				cin >> month;
				cout << "Enter year" << endl;
				cin >> year;


				cout << "Select category:" << endl;
				cout << "1.Product" << endl;
				cout << "2.Electoronic" << endl;
				cout << "3.Internet" << endl;
				cout << "4.Clothes" << endl;
				cout << "5.Comunality" << endl;
				cout << "6.Study" << endl;
				cout << "7.Other" << endl;

				int cat = -1;
				cin >> cat;

				switch (cat) {
				case 1: {
					category = "Product";
					break;
				}
				case 2: {
					category = "Electoronic";
					break;
				}
				case 3: {
					category = "Internet";
					break;
				}
				case 4: {
					category = "Clothes";
					break;
				}
				case 5: {
					category = "Comunality";
					break;
				}
				case 6: {
					category = "Study";
					break;
				}
				case 7: {
					category = "Other";
					break;
				}
				}

				store.getAllPaymentsByDayAndCategory(day, month, year,category);
				_getch();
				break;
			}
			case 7:
			{
				system("cls");
				int week;
				int month;
				int year;
				string category;

				cout << "Enter week" << endl;
				cin >> week;
				cout << "Enter month" << endl;
				cin >> month;
				cout << "Enter year" << endl;
				cin >> year;


				cout << "Select category:" << endl;
				cout << "1.Product" << endl;
				cout << "2.Electoronic" << endl;
				cout << "3.Internet" << endl;
				cout << "4.Clothes" << endl;
				cout << "5.Comunality" << endl;
				cout << "6.Study" << endl;
				cout << "7.Other" << endl;

				int cat = -1;
				cin >> cat;

				switch (cat) {
				case 1: {
					category = "Product";
					break;
				}
				case 2: {
					category = "Electoronic";
					break;
				}
				case 3: {
					category = "Internet";
					break;
				}
				case 4: {
					category = "Clothes";
					break;
				}
				case 5: {
					category = "Comunality";
					break;
				}
				case 6: {
					category = "Study";
					break;
				}
				case 7: {
					category = "Other";
					break;
				}
				}

				store.getAllPaymentsByWeekAndCategory(week, month, year, category);
				_getch();
				break;
			}
			case 8:
			{
				system("cls");
				
				int month;
				int year;
				string category;

				cout << "Enter month" << endl;
				cin >> month;
				cout << "Enter year" << endl;
				cin >> year;


				cout << "Select category:" << endl;
				cout << "1.Product" << endl;
				cout << "2.Electoronic" << endl;
				cout << "3.Internet" << endl;
				cout << "4.Clothes" << endl;
				cout << "5.Comunality" << endl;
				cout << "6.Study" << endl;
				cout << "7.Other" << endl;

				int cat = -1;
				cin >> cat;

				switch (cat) {
				case 1: {
					category = "Product";
					break;
				}
				case 2: {
					category = "Electoronic";
					break;
				}
				case 3: {
					category = "Internet";
					break;
				}
				case 4: {
					category = "Clothes";
					break;
				}
				case 5: {
					category = "Comunality";
					break;
				}
				case 6: {
					category = "Study";
					break;
				}
				case 7: {
					category = "Other";
					break;
				}
				}
				store.getAllPaymentsByMonthAndCategory(month, year, category);
				_getch();
				break;
			}
			case 9:
			{
				system("cls");
				int week;
				int month;
				int year;

				cout << "Enter week" << endl;
				cin >> week;
				cout << "Enter month" << endl;
				cin >> month;
				cout << "Enter year" << endl;
				cin >> year;

				store.getTop3PaymentByWeek(week, month, year);
				_getch();

				break;
			}
			case 10:
			{
				system("cls");
				int month;
				int year;

				cout << "Enter month" << endl;
				cin >> month;
				cout << "Enter year" << endl;
				cin >> year;

				store.getTop3PaymentByMonth(month, year);
				_getch();

				break;
			}
			case 11:
			{
				system("cls");
				int week;
				int month;
				int year;

				cout << "Enter week" << endl;
				cin >> week;
				cout << "Enter month" << endl;
				cin >> month;
				cout << "Enter year" << endl;
				cin >> year;

				store.getTop3CategoryByWeek(week, month, year);
				_getch();
				break;
			}
			case 12:
			{
				system("cls");

				int month;
				int year;

				cout << "Enter month" << endl;
				cin >> month;
				cout << "Enter year" << endl;
				cin >> year;

				store.getTop3CategoryByMonth(month, year);
				_getch();
				break;
			}
			case 13:
			{
				main();
				break;
			}
		}
	}
}
