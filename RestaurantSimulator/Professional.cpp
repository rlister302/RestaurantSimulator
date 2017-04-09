
#include "Professional.h"
#include "Party.h"
#include <ctime>
#include <cstdlib>
using namespace std;



Professional::Professional() : Server()
{
	name = " ";
	maxTables = 4;
}

Professional::Professional(string n) : Server()
{
	name = n;
	maxTables = 4;
}

int Professional::calcServiceTime(int numGuests)
{
	unsigned seed = time(0);

	srand(seed);

	int serviceTime = (rand() % (2 - 1 + 1)) + 1;

	return serviceTime * numGuests;
}