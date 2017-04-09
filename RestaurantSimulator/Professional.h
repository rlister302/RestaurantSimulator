


#ifndef Professional_h
#define Professional_h

#include "Server.h"
using namespace std;

class Professional : public Server
{
public:
	Professional();
	Professional(string);
	virtual int calcServiceTime(int);
};


#endif