 
#ifndef REGISTERBUFFER
#define REGISTERBUFFER

#include "registerSpace.h"

class RegisterBuffer
{
private:
	registerSpace* _head;
	registerSpace* _tail;
public:
	addSpace(int pSize, char* pName, short pType);
	registerSpace* getBuffer();
	clear();	
};

#endif
