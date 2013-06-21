
#ifndef NORAID
#define NORAID

class RegisterSpace;

class NoRaid : public DiskGroup
{
private:
	short _ID;
	int _BlockSize, _NumDisks;
	DataBuffer* _outBuffer;
	bool _Functional;
	bool _Working
		
	SimpleListLss * _diskList;			// *** CUIDADO ***
		
public:
	NoRaid(short pID, int pBlockSize, SimpleList pList);
	bool getFile(char* pPath, char* pUser);
	bool deleteFile(char* pPath, char* pUser);
	
	/* cambie RegisterSpace* por una lista simple para conocer el tamaño mas facilmente */
    bool createFile(char* pPath, SimpleList* pRegisterList, char* pUser);
	
	void appendRegister(char* pPath, char* pUser, DataNode* pData);
	bool eraseRegister(char* pPath, char* pUser, int pRegisterNumber);
	void writeRegister(char* pPath, char* pUser, int pRegisterNumber, DataNode* pData);
	DataNode* readRegister(char* pPath, char* pUser, int pRegisterNumber);
};

#endif
