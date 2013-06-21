#include "generalmanager.h"

GeneralManager(){
	/* CUIDADO EL ORDEN DE INICIALIZACIÓN DEBE SER:
		- CLIENTES
		- DISCOS
		- DISKGROUPS
	*/
	_instance = this;

	_clientsTree = 0;
	_diskTree = 0;
	_diskGroups = 0;
	_users = 0;

	_server = new ServerNetworkHandler(this);
	_console = new ServerConsole(this);
	_sessions = new AVLTree<Session, int>();
	_users = new AVLTree<User, std::string>;
	
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
	Session* session = _sessions->erase(pSessionID);
	delete session;
}

void GeneralManager::defineDiskGroup(int pRAID, int pBlockSize, std::string pID){
	if (_diskGroups->search(pID) != 0){
		std::cout<<"Error. Ya existe un DiskGroup con el identificador '" << pID << "'."<<std::endl;
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
			std::cout<<std::endl;
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
		std::cout<<std::endl;
		if (stop == 'y'){
			diskGroup->stopDiskGroup();
		}
	}
}

AVLTree<DiskGroup, std::string>* GeneralManager::loadDiskGroups(){
	std::string raidType = DiskGroupsXML::getDiskGroupRaid("~/diglet/raidb/diskgroups.xml", 1);
	for (int i = 1; raidType != ""; i++){

		//Obtener los atributos del diskgroup
		std::string id = DiskGroupsXML::getDiskGroupId("~/diglet/raidb/diskgroups.xml", i);
		int blockSize = std::stoi( DiskGroupsXML::getDiskGroupBlockSize("~/diglet/raidb/diskgroups.xml", i) );
		int maxSize = std::stoi( DiskGroupsXML::getDiskGroupMaxSize("~/diglet/raidb/diskgroups.xml", i) );
		bool functional = DiskGroupsXML::getDiskGroupFunctional("~/diglet/raidb/diskgroups.xml", i) == "true"?true:false;
		bool working = DiskGroupsXML::getDiskGroupWorking("~/diglet/raidb/diskgroups.xml", i) == "true"?true:false;

		//Inicializar el diskgroup
		DiskGroup* diskGroup = 0;
		if (raidType == std::to_string(DiskGroup::NO_RAID)){
			diskGroup = new NoRAID(id, blockSize, maxSize, functional, working);
		} else if (raidType == std::to_string(DiskGroup::RAID0)){
			diskGroup = new  RAID0(id, blockSize, maxSize, functional, working);
		} else if (raidType == std::to_string(DiskGroup::RAID1)){
			diskGroup = new  RAID1(id, blockSize, maxSize, functional, working);
		} else if (raidType == std::to_string(DiskGroup::RAID5)){
			diskGroup = new  RAID5(id, blockSize, maxSize, functional, working);
		}

		//Cargar discos
		std::string id = DiskGroupsXML::getDiskGroupDiskId("~/diglet/raidb/diskgroups.xml", i, 0);
		for (int j = 1; id != ""; j++){
			StorageClient* client = _clientsTree->search( Tokenizer::getCommandSpace(id, 0, ':') );
			Disk* disk = client->getDisk( std::stoi(Tokenizer::getCommandSpace(id, 1, ':')) );
			diskGroup->addDisk(disk);
			id = DiskGroupsXML::getDiskGroupDiskId("~/diglet/raidb/diskgroups.xml", i, j+1);
		}

		_diskTree->insert(diskGroup);
		std::cout<<"Diskgroup '"<<id<<"' añadido con éxito"<<std::endl;

		raidType = DiskGroupsXML::getDiskGroupRaid("~/diglet/raidb/diskgroups.xml", i+1);

	}
}

AVLTree<StorageClient, std::string>* GeneralManager::loadClients(){
	std::string client = 
}

AVLTree<Disk, std::string> loadDisks();
AVLTree<User, std::string> loadUsers();


void GeneralManager::startSystem(){
	/* CUIDADO EL ORDEN DE INICIALIZACIÓN DEBE SER:
		- CLIENTES
		- DISCOS
		- DISKGROUPS
	*/
	_clientsTree = loadClients();
	_diskTree = loadDisks();
	_diskGroups = loadDiskGroups();
	_userTree = loadUsers();

	_console->start();
	FALTA
}

void GeneralManager::stopSystem(){

}