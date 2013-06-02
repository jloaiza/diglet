#ifndef LSSMANAGER
#define LSSMANAGER

#include "../structures/simplelist/simplelist.h"
#include "lssconsole.h"
#include "lssnetworkhandler.h"
#include "lss.h"

class LssConsole;
class LSSNetworkHandler;

class LssManager{
	
private:
	SimpleList* _lss;
	LssConsole* _console;
	LSSNetworkHandler* _networkHandler;
	short _disponibleID;

public:
	LssManager();
	Lss* getLSS(short pID);
	void write(char* pData, short pID, int pBlock);
	char* read(short pID, int pBlock);
	void createDisk(int pFileSize, std::string pSecKey);
	void showDisks();
	void eraseDisk(short pID, std::string pSecKey);
	int getDiskSize(short pDiskID);
	int getBlockSize(short pID);
	void format(short pID, int pBlockSize);
	short getFreeBlock(short pDiskID);
	void write(char* pData, short pID, int pBlock, int pOffset, int pSize);
	char* read(short pID, int pBlock, int pOffset, int pSize);
	void startSystem();
};

#endif
