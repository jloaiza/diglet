#include "disk.h"

bool Disk::operator==(std::string& pDisk){
	std::string diskID = _storageClient->getIP() + std::to_string(_id);
	return diskID == pDisk;
}

bool Disk::operator!=(std::string& pDisk){
	std::string diskID = _storageClient->getIP() + std::to_string(_id);
	return diskID != pDisk;
}

bool Disk::operator>(std::string& pDisk){
	std::string diskID = _storageClient->getIP() + std::to_string(_id);
	return diskID > pDisk;
}

bool Disk::operator>=(std::string& pDisk){
	std::string diskID = _storageClient->getIP() + std::to_string(_id);
	return diskID >= pDisk;
}

bool Disk::operator<(std::string& pDisk){
	std::string diskID = _storageClient->getIP() + std::to_string(_id);
	return diskID < pDisk;
}

bool Disk::operator<=(std::string& pDisk){
	std::string diskID = _storageClient->getIP() + std::to_string(_id);
	return diskID <= pDisk;
}

std::string Disk::readBlock(int pBlock){
	return _storageClient->readBlock(_id, pBlock);
}

int Disk::writeBlock(std::string pData){
	return _storageClient->writeBlock(_id, pData);
}

void Disk::writeBytes(int pBlock, int pOffset, int pSize, std::string pData){
	_storageClient->writeBytes(_id, pBlock, pOffset, pSize, pData);
}

std::string Disk::readBytes(int pBlock, int pOffset, int pSize){
	return _storageClient->readBytes(_id, pBlock, pOffset, pSize);
}

bool Disk::isAlive(){
	return _storageClient->isAlive(_id);
}