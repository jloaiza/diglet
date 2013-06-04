#include "serveroperations.h"
#include "generalmanager.h"
#include "session.h"
#include "registerbuffer.h"
#include "datanode.h"
#include "databuffer.h"
#include "constants.h"
#include "../structures/ntree/ntreenode.h"
#include "../tokenizer/tokenizer.h"

#include <iostream>
#include <exception>

bool ServerOperations::checkUser(std::string pUser, std::string pKey){

}

std::string ServerOperations::toCSV(DataNode* pData, RegisterSpace* pFormat){
	std::string data;
	DataNode* iNode = pData;

	while (iNode != 0){
		if (pData->getType() != STRING_TYPE){
			if (pData->getType() != DOUBLE_TYPE){
				data += std::to_string(*(long*)(pData->getData()));
			} else {
				data += std::to_string(*(double*)(pData->getData()));
			}
		} else {
			data += *(std::string*)(pData->getData());
		}
		iNode = pData->getNext();
	}
	data = data.substr(1, data.length()-1);

	int length;
	RegisterSpace* iSpace = pFormat;
	for (length; iSpace != 0; length++){
		iSpace = iSpace->getNext();
	}

	std::string csv;
	iSpace = pFormat;
	for (int i = 0; i < length; i ++){
		int lastComa = Tokenizer::charIndex(data, ',', length);
		csv += iSpace->getName() + std::string(",") + data.substr(0, lastComa) + std::string("\n");
		data = data.substr(lastComa+1, data.length()-lastComa-1);
	}
	return csv;
}

DataNode* getData(std::string pData, RegisterSpace* pFormat){
	DataBuffer buffer;
	for (int i = 1; pFormat != 0; i++){
		int type = pFormat->getType();
		int size = pFormat->getSize();

		std::string dataSpace = Tokenizer::getCommandSpace(pData, i, '#');
		void* data = 0;

		if (dataSpace != ""){

			try{

				if (type != STRING_TYPE){
					if (type == SHORT_TYPE){
						data = new short(std::stoi(dataSpace));
					} else if(type == INT_TYPE){
						data = new int(std::stoi(dataSpace));
					} else if(type == LONG_TYPE){
						data = new long(std::stol(dataSpace));
					} else if(type == DOUBLE_TYPE){
						data = new double(std::stod(dataSpace));
					}

				} else {
					data = new std::string(dataSpace);
				}

			} catch (std::exception e){
				return 0;
			}

		}
		
		buffer.addToBuffer(data, type, size);
		pFormat = pFormat->getNext();
	}
	return buffer.getBuffer();
}

RegisterSpace* ServerOperations::getFormat(std::string pFormat){
	bool splitting = true;
	RegisterBuffer buffer;
	try{
		for (int i = 1; splitting; i++){

			std::string formatSpace = Tokenizer::getCommandSpace(pFormat, i, ';');
			if (formatSpace != ""){

				std::string name = Tokenizer::getCommandSpace(formatSpace, 1, '#');
				int type = std::stoi(Tokenizer::getCommandSpace(formatSpace, 2, '#'));
				int size = std::stoi(Tokenizer::getCommandSpace(formatSpace, 3, '#'));
				buffer.addSpace(name, size, type);

			} else {
				splitting = false;
			}
				

		
		}
	} catch (std::exception e){
		return 0;
	}
	return buffer.getBuffer();
}
	
std::string ServerOperations::get(int pSessionID, std::string pPath){
	GeneralManager* manager = GeneralManager::getInstance();
	Session* session = manager->getSession(pSessionID);
	if (session == 0){
		return "*Error. Sesión no encontrada\n";
	}
	DiskGroup* diskgroup = session->getDiskGroup();
	nTreeNode* currentNode = session->getCurrentNode();
	nTreeNode* toReadNode = diskgroup->getNode(pPath, currentNode);
	if (toReadNode == 0 || toReadNode->getFile() == 0){
		return "?Error. Archivo invalido\n";
	}
	DataNode* data = diskgroup->getFile(toReadNode->getFile());
	RegisterSpace* format = diskgroup->getRegisterFormat(toReadNode->getFile());
	return toCSV(data, format);
}

std::string ServerOperations::cd(int pSessionID, std::string pPath){
	GeneralManager* manager = GeneralManager::getInstance();
	Session* session = manager->getSession(pSessionID);
	if (session == 0){
		return "*Error. Sesión no encontrada\n";
	}
	DiskGroup* diskgroup = session->getDiskGroup();
	nTreeNode* currentNode = session->getCurrentNode();
	nTreeNode* cdNode = diskgroup->getNode(pPath, currentNode);
	if (cdNode == 0 || cdNode->getFile() != 0){
		return "?Error. Directorio invalido\n";
	}
	session->setCurrentNode(cdNode);
	return "";
}

std::string ServerOperations::rm(int pSessionID, std::string pPath){
	if (pPath == "./" || pPath == "/"){
		return "";
	}
	GeneralManager* manager = GeneralManager::getInstance();
	Session* session = manager->getSession(pSessionID);
	if (session == 0){
		return "*Error. Sesión no encontrada\n";
	}
	DiskGroup* diskgroup = session->getDiskGroup();
	nTreeNode* currentNode = session->getCurrentNode();
	nTreeNode* rmNode = diskgroup->getNode(pPath, currentNode);
	if (rmNode == 0){
		return "?Error. Ruta invalida\n";
	}
	diskgroup->del(rmNode);
	return "";
}

std::string ServerOperations::moveSeek(int pSessionID, int pSeekPos){
	GeneralManager* manager = GeneralManager::getInstance();
	Session* session = manager->getSession(pSessionID);
	if (session == 0){
		return "*Error. Sesión no encontrada\n";
	}
	nTreeNode* currentNode = session->getCurrentNode();
	if (currentNode->getFile() == 0){
		return "?Error. No hay ningún archivo abierto\n";
	}
	if (currentNode->getFile()->getRegCount() < pSeekPos){
		return "?Error. El número de registro es invalido";
	}
	session->setSeek(pSeekPos);
	return "";
}

std::string ServerOperations::touch(int pSessionID, std::string pPath, std::string pFormat){
	GeneralManager* manager = GeneralManager::getInstance();
	Session* session = manager->getSession(pSessionID);
	if (session == 0){
		return "*Error. Sesión no encontrada\n";
	}
	DiskGroup* diskgroup = session->getDiskGroup();
	nTreeNode* currentNode = session->getCurrentNode();

	std::string fileName = Tokenizer::dividePathAndName(pPath, &pPath);

	nTreeNode* cdNode = diskgroup->getNode(pPath, currentNode);
	if (cdNode == 0 || cdNode->getFile() != 0){
		return "?Error. Ruta inválida\n";
	}
	
	RegisterSpace* format = getFormat(pFormat);
	session->setCurrentNode(diskgroup->createFile(fileName, format, session->getUser()));
	session->setCurrentFormat(format);
	session->setSeek(0);
	return "";
}

int ServerOperations::connect(std::string pUser, std::string pSecKey, std::string pDisk){
	SEGURIDAD;

	GeneralManager* manager = GeneralManager::getInstance();
	return manager->newSession(pUser, pDisk);
}

int ServerOperations::adduser(std::string pUser, std::string pSecKey, std::string pDisk){
	AGREGAR;

	GeneralManager* manager = GeneralManager::getInstance();
	return manager->newSession(pUser, pDisk);
}

std::string ServerOperations::openfile(int pSessionID, std::string pPath){
	GeneralManager* manager = GeneralManager::getInstance();
	Session* session = manager->getSession(pSessionID);
	if (session == 0){
		return "*Error. Sesión no encontrada\n";
	}
	DiskGroup* diskgroup = session->getDiskGroup();
	nTreeNode* currentNode = session->getCurrentNode();

	std::string fileName = Tokenizer::dividePathAndName(pPath, &pPath);

	nTreeNode* cdNode = diskgroup->getNode(pPath, currentNode);
	if (cdNode == 0 || cdNode->getFile() == 0){
		return "?Error. Archivo inválido\n";
	}

	session->setCurrentNode(cdNode);
	session->setCurrentFormat( diskgroup->getRegisterFormat( cdNode->getFile() ) );
	session->setSeek(0);
	return "";
}

std::string ServerOperations::appendReg(int pSessionID, std::string pData){
	GeneralManager* manager = GeneralManager::getInstance();
	Session* session = manager->getSession(pSessionID);
	if (session == 0){
		return "*Error. Sesión no encontrada\n";
	}
	DiskGroup* diskgroup = session->getDiskGroup();
	nTreeNode* currentNode = session->getCurrentNode();

	if (currentNode->getFile() == 0){
		return "?Error. No hay ningún archivo abierto\n";
	}

	RegisterSpace* format = diskgroup->getRegisterFormat(currentNode->getFile());
	DataNode* data = getData(pData, format);
	diskgroup->appendReg(data, currentNode->getFile());
	return "";

}

std::string ServerOperations::delReg(int pSessionID, int pRegNum){
	GeneralManager* manager = GeneralManager::getInstance();
	Session* session = manager->getSession(pSessionID);
	if (session == 0){
		return "*Error. Sesión no encontrada\n";
	}
	DiskGroup* diskgroup = session->getDiskGroup();
	nTreeNode* currentNode = session->getCurrentNode();

	if (currentNode->getFile() == 0){
		return "?Error. No hay ningún archivo abierto\n";
	}	

	if (pRegNum == SEEK_POS){
		pRegNum = session->getSeek();
	} else if (pRegNum > session->getCurrentNode()->getFile()->getRegCount()){
		return "?Error. El número de registro es inválido";
	}
	diskgroup->eraseRegister(pRegNum, currentNode->getFile());
	return "";
}

std::string ServerOperations::write(int pSessionID, std::string pData, int pRegNum){
	GeneralManager* manager = GeneralManager::getInstance();
	Session* session = manager->getSession(pSessionID);
	if (session == 0){
		return "*Error. Sesión no encontrada\n";
	}
	DiskGroup* diskgroup = session->getDiskGroup();
	nTreeNode* currentNode = session->getCurrentNode();

	if (currentNode->getFile() == 0){
		return "?Error. No hay ningún archivo abierto\n";
	}	

	if (pRegNum == SEEK_POS){
		pRegNum = session->getSeek();
	} else if (pRegNum > session->getCurrentNode()->getFile()->getRegCount()){
		return "?Error. El número de registro es inválido";
	}

	RegisterSpace* format = diskgroup->getRegisterFormat(currentNode->getFile());
	DataNode* data = getData(pData, format);

	diskgroup->writeRegister(pRegNum, data, currentNode->getFile());
	return "";
}

std::string ServerOperations::readReg(int pSessionID, int pRegNum){
	GeneralManager* manager = GeneralManager::getInstance();
	Session* session = manager->getSession(pSessionID);
	if (session == 0){
		return "*Error. Sesión no encontrada\n";
	}
	DiskGroup* diskgroup = session->getDiskGroup();
	nTreeNode* currentNode = session->getCurrentNode();

	if (currentNode->getFile() == 0){
		return "?Error. No hay ningún archivo abierto\n";
	}	

	if (pRegNum == SEEK_POS){
		pRegNum = session->getSeek();
	} else if (pRegNum > session->getCurrentNode()->getFile()->getRegCount()){
		return "?Error. El número de registro es inválido";
	}

	RegisterSpace* format = diskgroup->getRegisterFormat(currentNode->getFile());
	DataNode* data = diskgroup->readRegister(pRegNum, currentNode->getFile());
	return toCSV(data, format);
}

std::string ServerOperations::close(int* pSessionID){
	GeneralManager* manager = GeneralManager::getInstance();
	Session* session = manager->getSession(*pSessionID);
	if (session == 0){
		return "*Error. Sesión no encontrada\n";
	}
	DiskGroup* diskgroup = session->getDiskGroup();
	nTreeNode* currentNode = session->getCurrentNode();
	if (currentNode->getFile != 0){
		session->setCurrentNode(diskgroup->getNode("../", currentNode));
		session->setSeek(0);
		return "";
	} else {
		manager->closeSession(*pSessionID);
		*pSessionID = -1;
		return "See ya, " + session->getUser();
	}
}

std::string ServerOperations::getInfo(int pSessionID){
	GeneralManager* manager = GeneralManager::getInstance();
	Session* session = manager->getSession(pSessionID);
	if (session == 0){
		return "*Error. Sesión no encontrada\n";
	}
	return session->getCurrentNode()->getPath() + " " + session->getUser();
}
