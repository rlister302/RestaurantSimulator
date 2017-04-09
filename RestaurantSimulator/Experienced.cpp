#include "Experienced.h"
#include <ctime>
#include <cstdlib>
#include "Party.h"
#include <iostream>
#include "FloorManager.h"
using namespace std;



Experienced::Experienced() : Server()
{
	name = " ";
	maxTables = 4;
}

Experienced::Experienced(string n) : Server()
{
	name = n;
	maxTables = 4;
}

int Experienced::calcServiceTime(int numGuests)
{
	unsigned seed = time(0);

	srand(seed);

	int serviceTime = (rand() % (5 - 3 + 1)) + 3;

	

	return serviceTime * numGuests;
}