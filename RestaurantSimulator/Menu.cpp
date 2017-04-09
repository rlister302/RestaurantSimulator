


#include <iostream>
#include <string>
#include "Menu.h"
#include "FloorManager.h"
using namespace std;

Menu::Menu()
{

}

void Menu::greetings()
{
	int choice;

	do
	{
		cout << "\t\t\tRESTAURANT SIMULATOR" << endl;
		cout << "\nWelcome to the Restaurant Simulator! This program will" <<
			"\nsimulate a business day based on the type of business you are, " <<
			"\nand the level of business that you select." << endl;

		cout << "\n\nPlease select an option" << endl;
		cout << "1: Instructions" << endl;
		cout << "2: Run Simulation" << endl;
		cout << "3: Exit Program" << endl;
		cin >> choice;

		while (choice > 3 || choice < 1 || cin.fail())
		{
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "\nThere was something wrong with that input..." << endl;
				cout << "Please try again." << endl;

			}

			if (choice > 3 || choice < 1)
			{

				cout << "\nThat was not a valid choice." << endl;
				cout << "Choose 1 for Instructions and 2 to run the simulation." << endl;

			}

			cin >> choice;
		}

		switch (choice)
		{
		case 1:instructions();
			break;
		case 2:
			mainMenu();
			break;
		case 3:
			break;
		}


	} while (choice != 3);
	

}

void Menu::mainMenu()
{
	string businessName;
	int businessLevel;
	int restaurantType;
	int numberOfTables;
	int numberOfServers;

	cin.ignore();

	cout << "\nPlease enter the name of your business." << endl;
	getline(cin, businessName); 

	
	

	cout << "\nNext, choose a level of business." << endl;
	cout << "1: Slow" << endl;
	cout << "2: Busy" << endl; 
	cout << "3: Slammed" << endl;
	
	cin >> businessLevel;

	while ((businessLevel > 3 || businessLevel < 1 ) || cin.fail())
	{

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "There was an error with that input." << endl;
			cout << "Please enter 1, 2, or 3 to indicate the level of business." << endl;
		}

		if (businessLevel > 3 ||  businessLevel < 1)
		{
			cout << "\nThat is not a valid level of business." << endl;
			cout << "Please enter 1, 2, or 3 to indicate the level of business." << endl;

		}

		cin >> businessLevel;
	}

	cout << "\nNext, choose the type of cuisine your restaurant serves." << endl;
	cout << "1: Continental" << endl;
	cout << "2: Bistro " << endl;
	cout << "3: Gourmet" << endl;
	cin >> restaurantType;

	while (restaurantType > 3 || restaurantType < 1 || cin.fail())
	{

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "There was an error with that input." << endl;
			cout << "Please enter 1, 2, or 3 to indicate the type of cuisine." << endl;
		}

		if (restaurantType > 3 < restaurantType < 1)
		{
			cout << "\nThat is not a valid type of cuisine.." << endl;
			cout << "Please enter 1, 2, or 3 to indicate the type of cuisine." << endl;

		}

		cin >> restaurantType;
	}

	cout << "\nPlease enter the number of tables in your restaurant." << endl;
	cin >> numberOfTables;

	while (numberOfTables < 1 || cin.fail())
	{
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "\nThere was an error with that input." << endl;
			cout << "Please enter the number of tables." << endl;
		}

		if (numberOfTables < 1)
		{
			cout << "\nYour restaurant must have at least one table. " << endl;
			cout << "Please enter a valid number of tables." << endl;
		}

		cin >> numberOfTables;
	}


	/*
		If there is time, get the price range of food from the user here
	*/

	cout << "\nNext, enter the number of servers that will be working the shift. " << endl;
	cin >> numberOfServers;

	while (cin.fail() || numberOfServers < 1)
	{
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(10000, '\n');

			cout << "\nThere was an error with that input." << endl;
			cout << "Please enter the number of servers." << endl;
		}

		if (numberOfServers < 1)
		{
			cout << "\nThere must be at least one server." << endl;
			cout << "Please enter the number of servers." << endl;

		}

		cin >> numberOfServers;
	}

	

	FloorManager manager(businessName, businessLevel, restaurantType, numberOfTables, numberOfServers);

	manager.runSimulation();
	
}

void Menu::instructions()
{

	cout << "\t\t\t**********************" << endl;
	cout << "\t\t\t*    INSTRUCTIONS    *" << endl;
	cout << "\t\t\t**********************" << endl;

	cout << "\nThe simulator will ask for some data about your restaurant, and will run" <<
		"\na simulation. The parameters that will be used are:\n" <<
		"\n1:Type of Restaurant" <<
		"\n2:The Level of Business" <<
		"\n3:The Number of Tables" <<
		"\n4:The Number of Service Staff" << endl;

	cout << "\n\nThe type of restaurant dictates how long the kitchen takes to prepare food." <<
		"\nA continental restaurant will take up to five minutes. A Bistro style \nrestaurant will take between 10 and 12 minutes," <<
		"and a Gourmet restaurant will \ntake 15-30 minutes to prepare the food." << endl;

	cout << "\nThe Level of Business controls how quickly tables enter the restaurant." <<
		"\nTables will come in at a slower pace when set to slow, and will be " <<
		"\nrelentless when set higher." << endl;

	cout << "\nThe Number of Tables sets how many tables the restaurant will have," <<
		"\nbut this is not the only variable that restricts tables from entering." <<
		"\nThe Number of Servers also affects the ability for tables to be sat." <<
		"\nServers can only take a certain number of tables based on their" <<
		"\nskill level." << endl; 

	cout << "\nThis simulator is meant to help you optimize scheduling your service staff." << endl;
	cout << "It will track the number of tables that enter your restaurant, and \nwill also keep track" <<
	 "of how many tables leave due to a long wait." << endl;

	


}