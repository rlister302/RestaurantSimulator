

#pragma once



class Observer
{
private:
	int totalTables;
	int totalGuests;
	int totalWaitTime;
	int totalWaitTables;
	int totalServiceTime;
	int tablesLeft;
	double totalRevenue;
public:
	Observer();
	void setTotalTables(int);
	int getTotalTables();

	void setTotalGuests(int);
	int getTotalGuests();

	void setTotalWaitTime(int);
	int getTotalWaitTime();

	void setTotalWaitTables(int);
	int getTotalWaitTables();

	void setTotalRevenue(double);
	void addRevenue(double);

	void setTotalServiceTime(int);
	int getTotalServiceTime();

	double calcAverageWait();
	double calcAverageServiceTime();

	void incrementTablesLeft();
	int getTablesLeft();

	void addTable();
	void addGuests(int);
	void addWaitTime(int);
	void addWaitTables();
	void addServiceTime(int);
	

};