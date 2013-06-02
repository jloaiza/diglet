#include "registerspace.h"

RegisterSpace::RegisterSpace(char* pName, int pSize, int pType)
{
	_name = pName;
	_size = pSize;
	_type = pType;
	_next = NULL;
}

char* RegisterSpace::getName()
{
	return _name;
}

int RegisterSpace::getSize()
{
	return _size;
}

int RegisterSpace::getType()
{
	return _type;
}

RegisterSpace * RegisterSpace::getNext()
{
	return _next;
}

void RegisterSpace::setNext (RegisterSpace * pNext)
{
	_next = pNext;
}
