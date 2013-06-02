#ifndef SERVEROPERATIONS
#define SERVEROPERATIONS

#include <string>
#include "session.h"

class ServerOperations{
private:

	//static std::string toCSV(DataNode* pData);
	static bool checkUser(std::string pUser, std::string pKey);
	//static nTree* loadUserTree(std::string pUser);


public:
	
	static std::string get(Session* pSession, std::string pPath);
	static std::string cd(Session* pSession, std::string pPath);
	static std::string rm(Session* pSession, std::string pPath);
	static std::string touch(Session* pSession, std::string pPath, std::string pFormat);
	static Session* connect(std::string pUser, std::string pSecKey, std::string pDisk);
	static Session* adduser(std::string pUser, std::string pSecKey, std::string pDisk);
	static std::string openfile(Session* pSession, std::string pPath);
	static std::string appendReg(Session* pSession, std::string pData);
	static std::string delReg(Session* pSession, int pRegNum);
	static std::string write(Session* pSession, std::string pData, int pRegNum);
	static std::string readReg(Session* pSession, int pRegNum);
	static std::string close(Session* pSession);

};


#endif /* SERVEROPERATIONS */