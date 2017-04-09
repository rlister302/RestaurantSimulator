

#ifndef Floor_h
#define Floor_h

#include <list>
#include <queue>
#include "Party.h"
#include "Server.h"
class Floor
{
private:
	static list<Party> tables;
	static queue<Party> waitList;
	int maxTables;
	int numberOfServers;
	Server** servers;

public:
	Floor(int, int);
	~Floor();
	void setMaxTables(int);
	int getMaxTables();
	static int getNumberOfTables();
	static void setTables(list<Party>);
	void setNumberOfServers(int);
	int getNumberOfServers();
	void setServers(Server**);
	Server** getServers();
	static list<Party> getTables();
	static void addTable(Party);
	static void removeTable(Party);
	int getCapacity();
	static queue<Party> getWaitList();
	static void setWait(queue<Party>);
	static void addToWait(Party);
	static void removeFromWait();
	static Party getFront();
	static int getWaitSize();


	
	

};




#endif