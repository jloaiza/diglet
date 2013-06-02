#include "serveroperations.h"

#include <iostream>

std::string ServerOperations::get(Session* pSession, std::string pPath){
	std::cout<<"get-call "<<pPath<<std::endl;
	return "get-call";
}

std::string ServerOperations::cd(Session* pSession, std::string pPath){
	std::cout<<"cd-call "<<pPath<<std::endl;
	return "cd-call";
}

std::string ServerOperations::rm(Session* pSession, std::string pPath){
	std::cout<<"rm-call "<<pPath<<std::endl;
	return "rm-call";
}

std::string ServerOperations::touch(Session* pSession, std::string pPath, std::string pFormat){
	std::cout<<"touch-call "<<pPath<<" "<<pFormat<<std::endl;
	return "touch-call";
}

Session* ServerOperations::connect(std::string pUser, std::string pSecKey, std::string pDisk){
	std::cout<<"connect-call "<<pUser<<" "<<pSecKey<<" "<<pDisk<<std::endl;
	return (new Session(pUser));
}

Session* ServerOperations::adduser(std::string pUser, std::string pSecKey, std::string pDisk){
	std::cout<<"adduser-call "<<pUser<<" "<<pSecKey<<" "<<pDisk<<std::endl;
	return 0;
}

std::string ServerOperations::openfile(Session* pSession, std::string pPath){
	std::cout<<"openfile-call "<<pPath<<std::endl;
	return "openfile-call";
}

std::string ServerOperations::appendReg(Session* pSession, std::string pData){
	std::cout<<"appendReg-call "<<pData<<std::endl;
	return "appendReg-call";
}

std::string ServerOperations::delReg(Session* pSession, int pRegNum){
	std::cout<<"delReg-call "<<pRegNum<<std::endl;
	return "delReg-call";
}

std::string ServerOperations::write(Session* pSession, std::string pData, int pRegNum){
	std::cout<<"write-call "<<pData<<" "<<pRegNum<<std::endl;
	return "write-call";
}

std::string ServerOperations::readReg(Session* pSession, int pRegNum){
	std::cout<<"readReg-call "<<pRegNum<<std::endl;
	return "readReg-call";
}

std::string ServerOperations::close(Session* pSession){
	std::cout<<"close-call "<<std::endl;
	return "close-call";
}