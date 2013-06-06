#include <cstring>
#include <string>

#include "../binaryoperations/byteshandler.h"
#include "../structures/simplelist/node.h"
#include "lss.h"
#include "lssmanager.h"

LssManager::LssManager() 
{ 
	_lss = new SimpleList();
	_disponibleID = 0;
	_console = 0;
	_networkHandler = 0;
}

Lss* LssManager::getLSS(short pID){
	return (Lss*)(_lss->get( std::to_string(pID).data() ));
}

short LssManager::write(std::string pData, short pID, short pBlockPadre)
{
	Lss* temporal = (Lss*)( _lss->get( std::to_string(pID).data() ) );
	return temporal->writeA (pData, pBlockPadre);
}

char * LssManager::read(short pID, short pBlock)
{
	Lss* temporal = (Lss*)( _lss->get( std::to_string(pID).data() ) );
	return temporal->readA (pBlock);	
}

void LssManager::write_bytes(std::string pData, short pID, int pBlock, int pOffset, int pSize)
{
	Lss* temporal = (Lss*)( _lss->get( std::to_string(pID).data() ) );
	short pPos = 12 + (pBlock * getBlockSize(pID)) + pOffset;
	temporal->writeB (pData, pPos, pSize);
}

char* LssManager::read_bytes(short pID, int pBlock, int pOffset, int pSize)
{
	Lss* temporal = (Lss*)( _lss->get( std::to_string(pID).data() ) );
	short pPos = 12 + (pBlock * getBlockSize(pID)) + pOffset;
	temporal->readB (pPos, pSize);	
}

void LssManager::createDisk(int pFileSize, std::string pSecKey)
{
	short * temp = new short();
	*temp = _disponibleID;
	_disponibleID++;
	Lss * temporal = new Lss(std::to_string(*temp).data(), *temp, pFileSize, pSecKey);
	_lss->insert(temporal);
}

void LssManager::eraseDisk(short pID, std::string pSecKey)
{
	Lss * temporal = (Lss*)(_lss->get( std::to_string(pID).data() ));
	if (temporal->getSecKey() == pSecKey)
	{
		_lss->erase(temporal);
	} 
	else 
	{
		std::cout<<"Security key incorrecto"<<std::endl;
	}
	
}

void LssManager::eraseBlock(short pID, short pBlock)
{
	Lss * temporal = (Lss*)(_lss->get( std::to_string(pID).data() ));
	temporal->eraseBlock(pBlock);
}

int LssManager::getDiskSize(short pID)
{
	Lss* temporal = (Lss*)( _lss->get( std::to_string(pID).data() ) );
	return temporal->getDiskSize();
}

int LssManager::getBlockSize(short pID)
{
	Lss* temporal = (Lss*)( _lss->get( std::to_string(pID).data() ) );
	return temporal->getBlockSize();
}

void LssManager::format(short pID, int pBlockSize)
{
	Lss* temporal = (Lss*)( _lss->get( std::to_string(pID).data() ) );
	temporal->format(pBlockSize);
}

void LssManager::startSystem()
{
	_console = new LssConsole(this);
	_networkHandler = new LSSNetworkHandler(this);
	_console->start();
	_networkHandler->start();
	_console->getThread()->join();
	_networkHandler->getThread()->join();
}

void LssManager::showDisks()
{
	_lss->print();
}
