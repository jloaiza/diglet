#ifndef LSSNETWORKHANDLER
#define LSSNETWORKHANDLER

#include "networkhandler.h"
#include "doublelinkedlist/doublelinkedlist.h"

#include "lssmanager.h"
#include "lss.h"

class LssManager;

class LSSNetworkHandler : public NetworkHandler
{
public:

	LSSNetworkHandler(LssManager* pManager){
		_lssList = new DoubleLinkedList<Lss, short>();
		_manager = pManager;
	}

	void inMessage(std::string pMessage, int pSocket);

private:
	DoubleLinkedList<Lss, short>* _lssList;
	LssManager* _manager;

	void connect(int pSocket, std::string pParam);
	void getFreeBlock(int pSocket, std::string pParam);
	void readBlock(int pSocket, std::string pParam);
	void writeBlock(int pSocket, std::string pParam);
	void getLssList(int pSocket);
	void getSize(int pSocket, std::string pParam);
	void writeBytes(int pSocket, std::string pParam);
	void readBytes(int pSocket, std::string pParam);
	void defaultCase(int pSocket, std::string pCommand);
};


#endif /* LSSNETWORKHANDLER */
