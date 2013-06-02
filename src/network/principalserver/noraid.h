
#ifndef NORAID
#define NORAID

class NoRaid : public DiskGroup
{
private:
	short _ID;
	int _BlockSize;
	DataBuffer* _outBuffer;
	bool _Functional;
	bool _Working;
public:
	NoRaid(short pID, int pBlockSize);
	bool getFile(char* pPath, char* pUser);
	bool deleteFile(char* pPath, char* pUser);
	bool createFile(char* pPath, RegisterSpace pRegister, char* pUser);
	void appendRegister(char* pPath, char* pUser, DataNode* pData);
	bool eraseRegister(char* pPath, char* pUser, int pRegisterNumber);
	void writeRegister(char* pPath, char* pUser, int pRegisterNumber, DataNode* pData);
	DataNode* readRegister(char* pPath, char* pUser, int pRegisterNumber);
};

#endif
