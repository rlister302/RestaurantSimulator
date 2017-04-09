
#ifndef Party_h
#define Party_h

#include "Server.h"

using namespace std;

class Party
{
private:
	int numberOfGuests;
	int timeEntered;
	int timeLeft;
	int waitBegin;
	int waitEnd;
	int ID;
	int willWaitFor;
	static int idGenerator;
	string serverName;
	

public:
	Party(int,int);
	Party();
	void setNumberOfGuests(int);
	int getNumberOfGuests();
	int getTimeEntered();
	void setTimeEntered(int);
	void setTimeLeft(int);
	int getTimeLeft();
	void setWaitBegin(int);
	int getWaitBegin();
	void setWaitEnd(int);
	int getWaitEnd();
	void setID(int);
	int getID();
	bool operator==(const Party&);
	void setServerName(string);
	string getServerName();
	int getTotalTime();
	int getWaitTime();
	int getTimeWillingToWait();
	

};


#endif