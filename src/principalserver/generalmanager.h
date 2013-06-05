#ifndef GENERALMANAGER
#define GENERALMANAGER

#include "diskgroup.h"
#include "../structures/avltree/avltree.h"
#include "servernetworkhandler.h"
#include "session.h"

#include <string>

class ServerConsole;
class StorageClient;

class GeneralManager{
	
public:
	GeneralManager();
	std::string getDiskGroupStatus(std::string pDiskGroupID);
	Session* getSession(int pSessionID);
	int newSession(std::string pUser, std::string pDiskGroupID);
	void closeSession(int pSessionID);
	void defineDiskGroup(int pRAID, int pBlockSize, std::string pID);
	void addLSS(std::string pDiskGroupID, std::string pIPToConnect, short pDiskID, std::string pSecurityKey, int pPort);
	void startDiskGroup(std::string pDiskGroupID);
	void stopDiskGroup(std::string pDiskGroupID);
	void startSystem();
	void stopSystem();

	static GeneralManager* getInstance(){
		return _instance;
	}

private:
	static GeneralManager* _instance;

	AVLTree<DiskGroup>* _diskGroups;
	ServerNetworkHandler* _serverHandler;
	ServerConsole* _console;
	AVLTree<StorageClient>* _clientsTree;
	AVLTree<Session>* _sessions;

};

#endif /* GENERALMANAGER */
