#include "Server.h"
#include "Party.h"
#include <string>

using namespace std;

Server::Server()
{
	name = "";
	maxTables = 0;
	numberOfGuests = 0;
	numberOfTables = 0;
	revenue = 0;
	ID = idGenerator;
	idGenerator++;
	
}

Server::~Server()
{

}

string Server::getName()
{
	return name;
}

void Server::setName(string n)
{
	name = n;
}

int Server::getMaxTables()
{
	return maxTables;
}

void Server::setMaxTables(int t)
{
	if (t > 0)
		maxTables = t;
	else
		maxTables = -1;

}

void Server::setNumberOfTables(int tables)
{
	numberOfTables = tables;
}

int Server::getNumberOfTables()
{
	return numberOfTables;
}

void Server::addRevenue(double r)
{
	revenue += r;
}

double Server::calcPPA()
{
	return (revenue / numberOfGuests);
}

int Server::getNumberOfGuests()
{
	return numberOfGuests;
}

double Server::getRevenue()
{
	return revenue;
}

void Server::operator=(const Server* other)
{
	name = other->name;
	maxTables = other->maxTables;
	numberOfGuests = other->numberOfGuests;
	revenue = other->revenue;

}

int Server::getID()
{
	return ID;
}

bool Server::isFull()
{
	return numberOfTables == maxTables;
}

int Server::idGenerator = 1;
