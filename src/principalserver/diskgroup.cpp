#include "diskroup.h"
#include "../structures/doublelinkedlist/listnode.h"

bool DiskGroup::operator==(std::string& pID){
	return _id == pID;
}

bool DiskGroup::operator>(std::string& pID){
	return _id > pID;
}

bool DiskGroup::operator>=(std::string& pID){
	return _id >= pID;
}

bool DiskGroup::operator<(std::string& pID){
	return _id < pID;
}

bool DiskGroup::operator<=(std::string& pID){
	return _id <= pID;
}

bool DiskGroup::operator!=(std::string& pID){
	return _id != pID;
}

bool DiskGroup::operator==(DiskGroup& pDiskGroup){
	return _id == pDiskGroup.getID();
}

bool DiskGroup::operator>(DiskGroup& pDiskGroup){
	return _id > pDiskGroup.getID();
}
bool DiskGroup::operator>=(DiskGroup& pDiskGroup){
	return _id >= pDiskGroup.getID();
}

bool DiskGroup::operator<(DiskGroup& pDiskGroup){
	return _id < pDiskGroup.getID();
}

bool DiskGroup::operator<=(DiskGroup& pDiskGroup){
	return _id <= pDiskGroup.getID();
}

bool DiskGroup::operator!=(DiskGroup& pDiskGroup){
	return _id != pDiskGroup.getID();
}

std::string DiskGroup::getDiskList(){
	ListNode<Disk>* aux = _diskList->getHead();
	std::string message;
	message += std::string("List of diskroup ") + _id + std::string(" order of list:\nDISK NAME    &    CONECTION STATUS");
	while (aux != 0){
		message += aux->getData()->getDiskID();
		message += (aux->getData()->isAlive()?"online":"offline") + '\n';
		aux = aux->getNext();
	}
	return message;
}

nTreeNode* DiskGroup::getNode(std::string pRelativePath, nTreeNode* pCurrentNode){
	
}

void DiskGroup::createDir(nTreeNode* pFolderNode, std::string pName, std::string pUser);{
	
}

void DiskGroup::addDisk(Disk* pDisk){
	_diskList->insertEnd(pDisk);
}

void DiskGroup::removeDisk(std::string pIP, short pDiskID){
	_diskList->erase(pIP + ':' + pDiskID);
}
