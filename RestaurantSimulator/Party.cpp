#include "Server.h"
#include "Party.h"
#include <ctime>
#include <cstdlib>

using namespace std;

Party::Party(int numGuests, int timeEnter)
{
	setNumberOfGuests(numGuests);

	setTimeEntered(timeEnter);

	setTimeLeft(0);

	setWaitBegin(0);

	setWaitEnd(0);

	setID(idGenerator);

	unsigned seed = time(0);

	srand(seed);

	willWaitFor = (rand() % (20 - 10 + 1)) + 10;

	idGenerator++;
}

Party::Party()
{
	setNumberOfGuests(0);

	setTimeEntered(0);

	setTimeLeft(0);

	setWaitBegin(0);

	setWaitEnd(0);

	setID(idGenerator);

	unsigned seed = time(0);

	srand(seed);

	willWaitFor = (rand() % (30 - 5 + 1)) + 10;

	idGenerator++;
}

void Party::setNumberOfGuests(int numGuests)
{
	if (numGuests > 0)
		numberOfGuests = numGuests;
}

int Party::getNumberOfGuests()
{
	return numberOfGuests;
}

void Party::setTimeEntered(int timeEnter)
{
	timeEntered = timeEnter;
}

int Party::getTimeEntered()
{
	return timeEntered;
}

	
void Party::setTimeLeft(int time)
{
	timeLeft = timeEntered + time;
}

int Party::getTimeLeft()
{
	return timeLeft;
}

void Party::setWaitBegin(int time)
{
	waitBegin = time;
}

int Party::getWaitBegin()
{
	return waitBegin;
}

void Party::setWaitEnd(int time)
{
	waitEnd = time;
}

int Party::getWaitEnd()
{
	return waitEnd;
}

int Party::getID()
{
	return ID;
}

void Party::setID(int id)
{
	ID = id;
}

bool Party::operator==(const Party &otherParty)
{
	if (this->ID == otherParty.ID)
		return true;
	else
		return false;
}

void Party::setServerName(string n)
{
	serverName = n;
}

string Party::getServerName()
{
	return serverName;
}

int Party::getTotalTime()
{
	return timeLeft - timeEntered;
}

int Party::getWaitTime()
{
	return waitEnd - waitBegin;
}

int Party::getTimeWillingToWait()
{
	return willWaitFor;
}

int Party::idGenerator = 1;