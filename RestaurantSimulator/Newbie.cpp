#include "Newbie.h"
#include "Party.h"
#include "Server.h"
#include <cstdlib>
#include <ctime>
using namespace std;

Newbie::Newbie() : Server()
{
	name = " ";
	maxTables = 3;
	
}

Newbie::Newbie(string n) : Server()
{
	name = n;
	maxTables = 3;
}

int Newbie::calcServiceTime(int numGuests)
{
	unsigned seed = time(0);

	srand(seed);

	int serviceTime = (rand() % (8 - 5 + 1)) + 5;

	return serviceTime * numGuests;
}