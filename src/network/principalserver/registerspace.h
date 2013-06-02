
#ifndef REGISTERSPACE
#define REGISTERSPACE
 
class RegisterSpace
{
private:
	char * _name;
	int _size;
	int _type;
	RegisterSpace * _next;
public:
	RegisterSpace(char* pName, int pSize, int pType);
	char* getName();
	int getSize();
	int getType();
	RegisterSpace * getNext();
	void setNext (RegisterSpace * pRegisterSpace);
};

#endif
