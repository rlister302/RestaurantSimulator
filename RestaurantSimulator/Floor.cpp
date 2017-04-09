

#include "Floor.h"


Floor::Floor(int numTables, int numServers)
{
	setMaxTables(numTables);
	setNumberOfServers(numServers);

	servers = new Server*[numberOfServers];

}

Floor::~Floor()
{
	
}

void Floor::setMaxTables(int tables)
{
	if (tables > 0)
		maxTables = tables;
}

int Floor::getMaxTables()
{
	return maxTables;
}

void Floor::setNumberOfServers(int servers)
{
	if (servers > 0)
		numberOfServers = servers;
}

int Floor::getNumberOfServers()
{
	return numberOfServers;
}

list<Party> Floor::getTables()
{
	return tables;
}

void Floor::addTable(Party p)
{
	tables.push_front(p);
}

void Floor::removeTable(Party p)
{
	tables.remove(p);
}



int Floor::getNumberOfTables()
{
	return tables.size();
}

Server** Floor::getServers()
{
	return servers;
}

void Floor::setServers(Server** servers)
{
	for (int i = 0; i < numberOfServers; i++)
	{
		this->servers[i] = servers[i];
	}
}

int Floor::getCapacity()
{
	int capacity = 0;

	for (int i = 0; i < numberOfServers; i++)
		capacity += servers[i]->getMaxTables();

	return capacity;

}

void Floor::setTables(list<Party> t)
{
	tables = t;
}



queue<Party> Floor::getWaitList()
{
	return waitList;
}

void Floor::setWait(queue<Party> newWait)
{
	waitList = newWait;
}

void Floor::addToWait(Party p)
{
	waitList.push(p);
}

void Floor::removeFromWait()
{
	waitList.pop();
}

Party Floor::getFront()
{
	return waitList.front();
}

int Floor::getWaitSize()
{
	return waitList.size();
}



list<Party> Floor:: tables;
queue<Party> Floor::waitList;