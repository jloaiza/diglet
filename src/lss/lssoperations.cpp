#include "lssoperations.h"

#include <cstdlib>
#include <string>
#include <cstring>

#include <iostream>

std::string LssOperations::getFreeBlock(short pID, DoubleLinkedList<Lss, short>* pDiskList){

	Lss* lss = pDiskList->search(&pID);
	
	if (lss != 0){
		return std::to_string(lss->getFreeBlock());
	} else {
		return "?Error: El disco no ha sido encontrado";
	}

}

std::string LssOperations::connect(short pID, std::string pKey, DoubleLinkedList<Lss, short>* pDiskList, LssManager* pManager){

	Lss* lss = pManager->getLSS(pID);

	if (lss->getSecKey() != pKey){
		return "?Error: Security key incorrecta";

	} else if (lss != 0){
		pDiskList->insertStart(lss);
		return "+connected";

	} else {
		return "?Error: El disco no ha sido encontrado";
	}

}

std::string LssOperations::readBlock(short pID, int pBlock, DoubleLinkedList<Lss, short>* pDiskList){
	Lss* toRead = pDiskList->search(&pID);
	if (toRead != 0){
		return toRead->read(pBlock);
	} else {
		return "?Error: El disco no ha sido encontrado";
	}
}

std::string LssOperations::writeBlock(short pID, int pBlock, std::string pData, DoubleLinkedList<Lss, short>* pDiskList){
	Lss* toWrite = pDiskList->search(&pID);
	if (toWrite != 0){
		char* tmp;
		strcpy(tmp, pData.data());
		toWrite->write(tmp, pBlock);
		return "";
	} else {
		return "?Error: El disco no ha sido encontrado";
	}
}

std::string LssOperations::writeBytes(short pID, int pBlock, int pOffset, int pSize, std::string pData, DoubleLinkedList<Lss, short>* pDiskList){
	std::cout<<"H-1"<<std::endl;
	Lss* toWrite = pDiskList->search(&pID);
	std::cout<<"H-2"<<std::endl;
	if (toWrite != 0){
		char* tmp = new char[pData.length()];
		strcpy(tmp, pData.data());
		std::cout<<"H"<<std::endl;
		toWrite->write(tmp, pBlock, pOffset, pSize);
		return "";
	} else {
		return "?Error: El disco no ha sido encontrado";
	}
}

std::string LssOperations::readBytes (short pID, int pBlock, int pOffset, int pSize, DoubleLinkedList<Lss, short>* pDiskList){
	Lss* toRead = pDiskList->search(&pID);
	if (toRead != 0){
		return toRead->read(pBlock, pOffset, pSize);
	} else {
		return "?Error: El disco no ha sido encontrado";
	}
}

std::string LssOperations::getLssList(short pID, LssManager* pManager){
	//return pManager->getLssList();
	return "!Not implemented yet";
}

std::string LssOperations::getSize(short pID, LssManager* pManager){
	Lss* toGet = pManager->getLSS(pID);
	if (toGet != 0){
		//return toGet->getSize();
		return "Not implemented yet";
	} else {
		return "?Error: El disco no ha sido encontrado";
	}
}
