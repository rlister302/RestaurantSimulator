
#ifndef FloorManager_h
#define FloorManager_h

#include "Party.h"
#include "Floor.h"
#include "Observer.h"
#include <string>

class FloorManager
{
private:
	string businessName;
	int rotation;
	int levelOfBusiness;
	int restaurantType;
	int numberOfTables;
	int numberOfServers;

public:
	FloorManager(string, int, int, int, int);
	void setRotation(int);
	int getRotation();
	void updateRotation();
	void setLevelOfBusiness(int);
	int getLevelOfBusiness();
	void setNumberOfServers(int);
	int getNumberOfServers();
	int calcCookTime();
	list<Party> checkTables(int, Observer&);
	void runSimulation();
	Server** createServers();
	

	


};


#endif