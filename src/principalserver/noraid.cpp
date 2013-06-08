#include "diskgroup.h"
#include "noraid.h"

NoRaid::NoRaid(short pID, int pBlockSize, SimpleList * pList)
{
	_ID = pID;
    _BlockSize = pBlockSize;
    _NumDisks = pList->_size;
	DataBuffer* _outBuffer;
	bool _Functional;
	bool _Working;
	_diskList = pList;
}

bool NoRaid::getFile(char* pPath, char* pUser)
{
	
}
	
bool NoRaid::deleteFile(char* pPath, char* pUser)
{
	//iFile temp = get(pPath);
	//temp.~iFile();
	//erase(pPath);
}
	
bool NoRaid::createFile(char* pPath, SimpleList* pRegisterList, char* pUser)
{
	short _AdmiHeader = 18;
	_AdmiHeader +=  (SimpleList->_size) * 20;
	if ( _AdmiHeader > _BLockSize )
	{
		
	}
	else
	{
		
	}
		
}

void NoRaid::appendRegister(char* pPath, char* pUser, DataNode* pData)
{
	
}
	
bool NoRaid::eraseRegister(char* pPath, char* pUser, int pRegisterNumber)
{

}
	
void NoRaid::writeRegister(char* pPath, char* pUser, int pRegisterNumber, DataNode* pData)
{
	
}
	
DataNode* NoRaid::readRegister(char* pPath, char* pUser, int pRegisterNumber)
{
	
}
