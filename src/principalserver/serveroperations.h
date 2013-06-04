#ifndef SERVEROPERATIONS
#define SERVEROPERATIONS

#include <string>
#include "datanode.h"
#include "registerspace.h"

class ServerOperations{
private:

	static std::string toCSV(DataNode* pData, RegisterSpace* pFormat);
	static bool checkUser(std::string pUser, std::string pKey);
	static RegisterSpace* getFormat(std::string pFormat);
	static DataNode* getData(std::string pData, RegisterSpace* pFormat);

public:
	
	static std::string get(int pSessionID, std::string pPath);
	static std::string cd(int pSessionID, std::string pPath);
	static std::string rm(int pSessionID, std::string pPath);
	static std::string moveSeek(int pSessionID, int pSeekPos);
	static std::string touch(int pSessionID, std::string pPath, std::string pFormat);
	static int connect(std::string pUser, std::string pSecKey, std::string pDisk);
	static int adduser(std::string pUser, std::string pSecKey, std::string pDisk);
	static std::string openfile(int pSessionID, std::string pPath);
	static std::string appendReg(int pSessionID, std::string pData);
	static std::string delReg(int pSessionID, int pRegNum);
	static std::string write(int pSessionID, std::string pData, int pRegNum);
	static std::string readReg(int pSessionID, int pRegNum);
	static std::string close(int* pSessionID);
	static std::string getInfo(int pSessionID);

};


#endif /* SERVEROPERATIONS */