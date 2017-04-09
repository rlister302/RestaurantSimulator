

#ifndef Experienced_h
#define Experienced_h

#include "Server.h"
using namespace std;

class Experienced : public Server
{
public:
	Experienced();
	Experienced(string);
	virtual int calcServiceTime(int);
};






#endif