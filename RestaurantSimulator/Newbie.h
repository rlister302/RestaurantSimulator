

#ifndef Newbie_h
#define Newbie_h

#include "Server.h"
using namespace std;

class Newbie : public Server
{
public:
	Newbie();
	Newbie(string);
	virtual int calcServiceTime(int);
};







#endif