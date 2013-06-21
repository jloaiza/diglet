#ifndef DISKGROUP
#define DISKGROUP

#include "registerspace.h"
#include "datanode.h"
#include "disk.h"
#include "doublelinkedlist/doublelinkedlist.h"

#include <string>

class iFile;
class nTreeNode;

class DiskGroup 
{
	
public:

	static const int NO_RAID = -1;
	static const int RAID0 = 0;
	static const int RAID1 = 1;
	static const int RAID5 = 5;

	bool operator==(std::string& pID);
	bool operator>(std::string& pID);
	bool operator>=(std::string& pID);
	bool operator<(std::string& pID);
	bool operator<=(std::string& pID);
	bool operator!=(std::string& pID);

	bool operator==(DiskGroup& pDiskGroup);
	bool operator>(DiskGroup& pDiskGroup);
	bool operator>=(DiskGroup& pDiskGroup);
	bool operator<(DiskGroup& pDiskGroup);
	bool operator<=(DiskGroup& pDiskGroup);
	bool operator!=(DiskGroup& pDiskGroup);

	virtual nTreeNode* createFile(nTreeNode* pFolderNode, std::string pName, RegisterSpace* pRegister, std::string pUser) = 0;
	virtual void del(nTreeNode* pNode) = 0;
	virtual DataNode* getFile(iFile* pFile) = 0;
	virtual int appendReg(DataNode* pData, iFile* pFile) = 0;
	virtual DataNode* readRegister(int pRegisterNumber, iFile* pFile) = 0;
	virtual void eraseRegister(int pRegisterNumber, iFile* pFile) = 0;
	virtual RegisterSpace* getRegisterFormat(iFile* pFile) = 0;
	virtual void format() = 0;

	std::string getDiskList();
	nTreeNode* getNode(std::string pRelativePath, nTreeNode* pCurrentNode);
	void createDir(nTreeNode* pFolderNode, std::string pName, std::string pUser);
	void addDisk(Disk* pDisk);
	void removeDisk(std::string pIP, short pDiskID);

	std::string getID() const {
		return _id;
	}

	int getBlockSize() const {
		return _blockSize;
	}

	void setBlockSize(int pSize){
		_blockSize = pSize;
		_functional = false;
		_working = false;
	}

	bool isWorking() const {
		return _working;
	}

	bool isFunctional(){
		return _functional;
	}

protected:
	
	std::string _id;
	int _raid;
	int _blockSize;
	bool _functional;
	bool _working;
	DoubleLinkedList<Disk, std::string> _diskList;

	virtual void eraseFile(iFile* pFile) = 0;



};

#endif
