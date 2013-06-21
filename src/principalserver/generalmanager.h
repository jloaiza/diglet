#ifndef GENERALMANAGER
#define GENERALMANAGER

#include "diskgroup.h"
#include "../structures/avltree/avltree.h"
#include "servernetworkhandler.h"
#include "serverconsole.h"
#include "session.h"
#include "disk.h"

#include <string>

class StorageClient;

class GeneralManager{
	
public:
	GeneralManager();
	std::string getDiskGroupStatus(std::string pDiskGroupID);
	Session* getSession(int pSessionID);
	int newSession(std::string pUser, std::string pDiskGroupID);
	void closeSession(int pSessionID);
	void defineDiskGroup(int pRAID, int pBlockSize, std::string pID);
	void addLSS(std::string pDiskGroupID, std::string pIPToConnect, int pPort, short pDiskID, std::string pSecurityKey, int pPort);
	void startDiskGroup(std::string pDiskGroupID);
	void stopDiskGroup(std::string pDiskGroupID);
	void startSystem();
	void stopSystem();

	static GeneralManager* getInstance(){
		return _instance;
	}

private:
	static GeneralManager* _instance;
	AVLTree<DiskGroup, std::string>* loadDiskGroups();
	AVLTree<StorageClient, std::string>* loadClients();
	AVLTree<Disk, std::string> loadDisks();
	AVLTree<User, std::string> loadUsers();

	void saveDiskGroups();
	void saveClients();
	void saveDisk();
	void saveUsers();

	AVLTree<DiskGroup, std::string>* _diskGroups;
	ServerNetworkHandler* _server;
	ServerConsole* _console;
	AVLTree<StorageClient, std::string>* _clientsTree;
	AVLTree<Session, int>* _sessions;
	AVLTree<Disk, std::string> _diskTree;
	AVLTree<User, std::string> _userTree;
};

#endif /* GENERALMANAGER */
