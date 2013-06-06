#include "generalmanager.h"

GeneralManager(){
	/* CUIDADO EL ORDEN DE INICIALIZACIÓN DEBE SER:
		- CLIENTES
		- DISCOS
		- DISKGROUPS
	*/
	_instance = this;

	_clientsTree = loadClients();
	_diskTree = loadDisks();
	_diskGroups = loadDiskGroups();
	_users = loadUsers();

	_server = new ServerNetworkHandler();
	_console = new ServerConsole();
	_sessions = new AVLTree<Session, int>();
	
}

std::string GeneralManager::getDiskGroupStatus(std::string pDiskGroupID){
	DiskGroup* disk = _diskGroups->search(pDiskGroupID);
	std::string isWorking = disk->isWorking()?"true":"false";
	std::string isFunctional = disk->isFunctional()?"true":"false";
	return std::string("Disk ID: ") + pDiskGroupID + std::string(" working: ") + isWorking + std::string(" functional:") + isFunctional;
}

Session* GeneralManager::getSession(int pSessionID){
	return _sessions->search(pSessionID);
}

int GeneralManager::newSession(std::string pUser, std::string pDiskGroupID){
	DiskGroup* disk = _diskGroups->search(pDiskGroupID);
	if (disk == 0){
		return NO_SESSION;
	} else {
		if (disk->isWorking()){
			Session* newSession = new Session(pUser, disk);
			_sessions->insert(newSession);
			return _newSession->getSessionID();
		} else {
			return NO_SESSION;
		}
	}
}

void GeneralManager::closeSession(int pSessionID){
	Session* session = _sessions->erase(pSessionID)
	delete session;
}

void GeneralManager::defineDiskGroup(int pRAID, int pBlockSize, std::string pID){
	if (_diskGroups->search(pID) != 0){
		std::cout<<"Error. Ya existe un DiskGroup con el identificador '" << pID << "'."<<std::endl
	} else {
		switch (pRAID){
			case DiskGroup::NO_RAID:
				_diskGroups->insert(new NoRAID(pID, pBlockSize));
				break;

			case DiskGroup::RAID0:
				_diskGroups->insert(new RAID0(pID, pBlockSize));
				break;

			case DiskGroup::RAID1:
				_diskGroups->insert(new RAID1(pID, pBlockSize));
				break;

			case DiskGroup::RAID5:
				_diskGroups->insert(new RAID5(pID, pBlockSize));
				break;

			case default:
				std::cout<<"Error. El tipo RAID " << pRAID << " no existe."<<std::endl;
				break;
		}
	}
		
}
void GeneralManager::addLSS(std::string pDiskGroupID, std::string pIPToConnect, int pPort, short pDiskID, std::string pSecurityKey, int pPort){
	std::string diskID = pIPToConnect + ":" + std::to_string(pDiskID);
	if (_diskTree->search(diskID) != 0){
		std::cout<<"Error. El disco ya existe."<<std::endl;
		return;
	} 

	DiskGroup* diskGroup = _diskGroups->search(pDiskGroupID);
	if (diskGroup == 0){
		std::cout<<"Error. El DiskGroup especificado no existe."<<std::endl;
		return;
	}

	StorageClient* client = _clientsTree->search(pIPToConnect);
	if (client == 0){
		client = new StorageClient(pIPToConnect, pPort);
		if (client->isConnected()){
			_clientsTree->insert(client);
		} else {
			std::cout<<"Error. No se pudo conectar con el LSS."<<std::endl;
			delete client;
			return;
		}	
	}

	Disk* disk = new Disk(client, pDiskID);
	if (disk->isAlive()){
		_diskTree->insert(disk);
		diskGroup->addDisk(disk);
	} else {
		std::cout<<"Error. El disco no está disponible."<<std::endl;
		delete disk;
	}
}

void GeneralManager::startDiskGroup(std::string pDiskGroupID){
	DiskGroup* diskGroup = _diskGroups->search(pDiskGroupID);
	if (diskGroup == 0){
		std::cout<<"Error. El DiskGroup especificado no existe."<<std::endl;
	} else if (!diskGroup->isWorking()){
		if (diskGroup->isFunctional()){
			diskGroup->startDiskGroup();
		} else {
			char format = 'n';
			std::cout<<"El DiskGroup ha sufrido cambios importantes y se debe formatear, ¿desea continuar? (y/n): ";
			std::cin>>format;
			if (format == 'y'){
				diskGroup->format();
				diskGroup->startDiskGroup();
			}
		}
	}
}

void GeneralManager::stopDiskGroup(std::string pDiskGroupID){
	DiskGroup* diskGroup = _diskGroups->search(pDiskGroupID);
	if (diskGroup == 0){
		std::cout<<"Error. El DiskGroup especificado no existe."<<std::endl;
	} else if (diskGroup->isWorking()){
		char stop = 'n';
		std::cout<<"Esta operación deshablitará el DiskGroup y no podrá ser utilizado hasta que se inicie de nuevo, ¿Desea continuar? (y/n): ";
		std::cin>>stop;
		if (stop == 'y'){
			diskGroup->stopDiskGroup();
		}
	}
}

void GeneralManager::startSystem(){

}

void GeneralManager::stopSystem(){

}