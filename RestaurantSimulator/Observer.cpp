
#include "Observer.h"


Observer::Observer()
{
	totalTables = 0;
	totalGuests = 0;
	totalWaitTime = 0;
	totalWaitTables = 0;
	totalServiceTime = 0;
	totalRevenue = 0;
	tablesLeft = 0;
}

void Observer::setTotalTables(int tables)
{
	totalTables = tables;
}

int Observer::getTotalTables()
{
	return totalTables;
}

void Observer::setTotalGuests(int guests)
{
	totalGuests = guests;
}

int Observer::getTotalGuests()
{
	return totalGuests;
}

void Observer::setTotalWaitTime(int time)
{
	totalWaitTime = time;
}

int Observer::getTotalWaitTime()
{
	return totalWaitTime;
}

void Observer::setTotalWaitTables(int tables)
{
	totalWaitTables = tables;
}

int Observer::getTotalWaitTables()
{
	return totalWaitTables;
}

void Observer::setTotalServiceTime(int time)
{
	totalServiceTime = time;
}

double Observer::calcAverageWait()
{
	if (totalWaitTables > 0)
		return (totalWaitTime / totalWaitTables);
	else
		return 0.00;
}

double Observer::calcAverageServiceTime()
{
	return (totalServiceTime / totalTables);
}

void Observer::addGuests(int guests)
{
	totalGuests += guests;
}

void Observer::addTable()
{
	totalTables += 1;
}

void Observer::addServiceTime(int time)
{
	totalServiceTime += time;
}

void Observer::addWaitTime(int time)
{
	totalWaitTime += time;
}
void Observer::addWaitTables()
{
	totalWaitTables += 1;
}

void Observer::addRevenue(double revenue)
{
	totalRevenue += revenue;
}

void Observer::incrementTablesLeft()
{
	tablesLeft += 1;
}

int Observer::getTablesLeft()
{
	return tablesLeft;
}