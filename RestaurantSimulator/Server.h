

#ifndef Server_h
#define Server_h

#include <string>
#include <list>
#include "Party.h"
using namespace std;

class Server
{
protected:
	string name;
	int maxTables;
	int numberOfTables;
	int numberOfGuests;
	double revenue;
	int ID;
	static int idGenerator;
	

public:
	Server();
	virtual ~Server();
	string getName();
	void setName(string);
	void setNumberOfTables(int);
	int getNumberOfTables();
	int getMaxTables();
	void setMaxTables(int);
	double calcPPA();
	virtual int calcServiceTime(int) = 0;
	void addRevenue(double);
	int getNumberOfGuests();
	double getRevenue();
	void operator=(const Server*);
	int getID();
	bool isFull();
	

	
};

#endif