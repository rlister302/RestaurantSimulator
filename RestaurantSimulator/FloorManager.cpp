#include "FloorManager.h"
#include "Server.h"
#include "Professional.h"
#include "Newbie.h"
#include "Experienced.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include "Observer.h"
#include "Windows.h"

FloorManager::FloorManager(string name,int level, int type, int tables, int servers)
{

	businessName = name;
	levelOfBusiness = level;
	restaurantType = type;
	numberOfTables = tables;
	numberOfServers = servers;
	rotation = 0;
}

void FloorManager::setRotation(int newRotation)
{
	rotation = newRotation;
}

int FloorManager::getRotation()
{
	return rotation;
}

void FloorManager::setLevelOfBusiness(int level)
{
	 levelOfBusiness = level;
}

int FloorManager::getLevelOfBusiness()
{
	return levelOfBusiness;
}

void FloorManager::setNumberOfServers(int servers)
{
	numberOfServers = servers;
}

int FloorManager::getNumberOfServers()
{
	return numberOfServers;
}

void FloorManager::updateRotation()
{
	if (rotation != numberOfServers - 1)
		rotation++;
	else
		rotation = 0;
}

void FloorManager::runSimulation()
{

	Server** servers = new Server*[numberOfServers];

	servers = createServers();

	

	

	Observer oby;
		
	Floor floor(numberOfTables, numberOfServers);


	const int TIME_TO_EAT = 15;

	floor.setServers(servers);

	unsigned seed;

	seed = time(0);

	srand(seed);

	int partyCounter = 0;

	int partyControl;

	if (levelOfBusiness == 1)
		partyControl = 10;
	else if (levelOfBusiness == 2)
		partyControl = 5;
	else
		partyControl = 2;

		// Run the simulation for 24 hours
	for (int i = 0; i < 1440; i++)
	{

		if ((i + 1) % 60 == 0)
		{
			system("cls");

			cout << "\t\t*********************" << endl;
			cout << "\t\t*  CURRENT STATUS   *" << endl;
			cout << "\t\t*********************" << endl;

			cout << setw(25) << left << "RESTAURANT NAME " << right << businessName << endl;
			cout << "-----------------------------------" << endl;
			cout << setw(25) << left << "NUMBER OF SERVERS " << right << numberOfServers << endl;
			cout << "-----------------------------------" << endl;
			cout << setw(25) << left << "NUMBER OF TABLES " << right << numberOfTables << endl;
			cout << "-----------------------------------" << endl;
			cout << setw(25) << left << "CURRENT TABLES " << right << Floor::getTables().size() << endl;
			cout << "-----------------------------------" << endl;
			cout << setw(25) << left << "TOTAL TABLES " << right << oby.getTotalTables() << endl;
			cout << "-----------------------------------" << endl;
			cout << setw(25) << left << "TABLES WAITING" << right << Floor::getWaitList().size() << endl;
			cout << "-----------------------------------" << endl;


			Sleep(1000);
		}

		while (Floor::getWaitSize() > 0 && (Floor::getNumberOfTables() < floor.getMaxTables()) && (Floor::getNumberOfTables() < floor.getCapacity()))
		{
			

			Party waitParty;

			waitParty = Floor::getFront();
			waitParty.setWaitEnd(i);

			if (waitParty.getTimeWillingToWait() < waitParty.getWaitTime())
			{
				Floor::removeFromWait();
				oby.incrementTablesLeft();
			}
			else
			{
				oby.addWaitTime(waitParty.getWaitTime());

				if (!servers[getRotation()]->isFull())
				{

					waitParty.setServerName(servers[getRotation()]->getName());

					waitParty.setTimeLeft(servers[getRotation()]->calcServiceTime(waitParty.getNumberOfGuests()) + calcCookTime() + TIME_TO_EAT);

					updateRotation();

					Floor::addTable(waitParty);

					

					oby.addTable();

					oby.addServiceTime(waitParty.getTotalTime());

					oby.addGuests(waitParty.getNumberOfGuests());
				}
				else
				{
					// If they are full, find the next available server

					for (int i = 0; i < numberOfServers; i++)
					{
						// If we are checking the server that is full, then move on
						if (i == getRotation())
							continue;

						// Assign the table to the next available server
						if (!servers[i]->isFull())
						{
							waitParty.setServerName(servers[i]->getName());

							waitParty.setTimeLeft(servers[getRotation()]->calcServiceTime(waitParty.getNumberOfGuests()) + calcCookTime() + TIME_TO_EAT);

							Floor::addTable(waitParty);

							

							// Record the table
							oby.addTable();

							oby.addServiceTime(waitParty.getTotalTime());

							oby.addGuests(waitParty.getNumberOfGuests());
						}
					}
				}
				// Remove the party from the wait
				Floor::removeFromWait();


			}
			
		}
		


		if (((i + 1) % partyControl) == 0)
		{

			Party party((rand() % (4 - 2 + 1)) + 2, i);

			
			partyCounter++;



			// If there was a wait, then the tables waiting get sat first, but 
			if ((Floor::getTables().size() < floor.getCapacity()) && (Floor::getTables().size() < floor.getMaxTables()))
			{
				// This if statement assigns the table to the next available server

				// If the server next in rotation is available, seat them. 
				if (!servers[getRotation()]->isFull())
				{
					party.setServerName(servers[getRotation()]->getName());

					party.setTimeLeft(servers[getRotation()]->calcServiceTime(party.getNumberOfGuests()) + calcCookTime() + TIME_TO_EAT);

					
					
					Floor::addTable(party);

					updateRotation();

					

					// Record the data
					oby.addTable();

					oby.addServiceTime(party.getTotalTime());

					oby.addGuests(party.getNumberOfGuests());
				}
				else
				{
					// If they are full, find the next available server

					for (int i = 0; i < numberOfServers; i++)
					{
						if (i == getRotation())
							continue;

						if (!servers[i]->isFull())
						{
							party.setServerName(servers[i]->getName());

							party.setTimeLeft(servers[getRotation()]->calcServiceTime(party.getNumberOfGuests()) + calcCookTime() + TIME_TO_EAT);

							Floor::addTable(party);

							oby.addTable();

							oby.addServiceTime(party.getTotalTime());

							oby.addGuests(party.getNumberOfGuests());
						}
					}
				}
			}
			else
			{
				// If the floor is full, then add the party to the wait
				oby.addWaitTables();

				party.setWaitBegin(i);

				
				Floor::addToWait(party);
				
				

			}
		}

		// Check to see if any tables are ready to leave...
		Floor::setTables(checkTables(i, oby));

	

	}

	
		

	delete[] servers;

	cout << "\nSimulation Complete!" << endl << endl;

	string businessLevel;
	string businessType;

	if (levelOfBusiness == 1)
		businessLevel = "Slow";
	else if (levelOfBusiness == 2)
		businessLevel = "Busy";
	else
		businessLevel = "Slammed";

	if (restaurantType == 1)
		businessType = "Continental";
	else if (restaurantType == 2)
		businessType = "Bistro";
	else
		businessType = "Gourmet";

	

	cout << "\t\t*********************" << endl;
	cout << "\t\t* SIMULATION REPORT *" << endl;
	cout << "\t\t*********************" << endl;

	cout << setw(25) << left << "RESTAURANT NAME " << right <<  businessName << endl;
	cout << "-----------------------------------" << endl;
	cout << setw(25) << left << "NUMBER OF SERVERS " << right << numberOfServers << endl;
	cout << "-----------------------------------" << endl;
	cout << setw(25) << left << "NUMBER OF TABLES " << right << numberOfTables << endl;
	cout << "-----------------------------------" << endl;
	cout << setw(25) << left << "LEVEL OF BUSINESS " << right << businessLevel << endl;
	cout << "-----------------------------------" << endl;
	cout << setw(25) << left << "TOTAL TABLES " << right << oby.getTotalTables() << endl;
	cout << "-----------------------------------" << endl;
	cout << setw(25) << left << "TOTAL GUESTS " << right << oby.getTotalGuests() << endl;
	cout << "-----------------------------------" << endl;
	cout << setw(25) << left << "AVERAGE SERVICE TIME " << right << oby.calcAverageServiceTime() << " minutes" <<endl;
	cout << "-----------------------------------" << endl;
	cout << setw(25) << left << "WAIT TABLES " << right << oby.getTotalWaitTables() << endl;
	cout << "-----------------------------------" << endl;
	cout << setw(25) << left << "AVERAGE WAIT TIME" << right << oby.calcAverageWait() << " minutes" << endl;
	cout << "-----------------------------------" << endl;
	cout << setw(25) << left << "TABLES TURNED AWAY" << right << oby.getTablesLeft() << endl;
	cout << "-----------------------------------" << endl;
	cout << setw(25) << left << "TABLES WAITING" << right << Floor::getWaitList().size() << endl;
	cout << "-----------------------------------" << endl;
	cout << setw(25) << left << "TABLES EATING" << right << Floor::getTables().size() << endl;
	cout << "-----------------------------------" << endl << endl;

	
}



Server** FloorManager::createServers()
{
		// An array of names that can be used for the servers name field
	string names[20] = { "Ryan", "Kevin", "Lauryn", "John", "Jacob",
		"Abigail", "Casey", "Nick", "Maggie", "Jeremy",
		"Greg", "David", "Mark", "Adam", "Cathy", 
		"Ashton", "Carly" , "Cindy", "Liz", "Caitlin"};

	unsigned seed;

	seed = time(0);

	srand(seed);

	Server** servers = new Server*[numberOfServers];

	
	/*
		This loop creates the servers skill level based on a random number.
		The newbie is most likely to be created, and the reason why is to 
		offset how fast the experienced and professional servers work. 
	*/
	for (int i = 0; i < numberOfServers; i++)
	{

		int randomNumber = (rand() % (10 - 1 + 1)) + 1;

		if (randomNumber > 0 && randomNumber < 6)
		{
			if (i < 20)
				servers[i] = new Newbie(names[i]);
			else
				servers[i] = new Newbie("Arthur");
		}
		else if (randomNumber > 5 && randomNumber < 10)
		{
			if (i < 20)
				servers[i] = new Experienced(names[i]);
			else
				servers[i] = new Experienced("Arthur");
		}
		else
		{
			if (i < 20)
				servers[i] = new Professional(names[i]);
			else
				servers[i] = new Professional("Arthur");
		}


	}


	return servers;
}

list<Party> FloorManager::checkTables(int currentTime, Observer &oby)
{
	list<Party>::iterator iter;

	list<Party> tables = Floor::getTables();

	iter = tables.begin();  

	while (iter != tables.end())
	{
		if (iter->getTimeLeft() == currentTime)
			iter = tables.erase(iter);
		else
			iter++;
	}

	return tables;
}

int FloorManager::calcCookTime()
{
	int cookTime = 0;

	unsigned seed = time(0);

	srand(seed);

	(rand() % (5 - 3 + 1)) + 3;

	if (restaurantType == 1)
	{
		cookTime = (rand() % (5 - 1 + 1)) + 1;
	}
	else if (restaurantType == 2)
	{
		cookTime = (rand() % (12 - 10 + 1)) + 10;
	}
	else
	{
		cookTime = (rand() % (30 - 15 + 1)) + 15;
	}

	return cookTime;
}
