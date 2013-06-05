#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "../binaryoperations/byteshandler.h"
#include "lss.h"
#include "../constants.h"


bool Lss::operator != (const short& pToCompare){
	return _id != pToCompare;
}

bool Lss::operator == (const short& pToCompare){
	return _id == pToCompare;
}

bool Lss::operator < (const short& pToCompare){
	return _id < pToCompare;
}

bool Lss::operator <= (const short& pToCompare){
	return _id <= pToCompare;
}

bool Lss::operator > (const short& pToCompare){
	return _id > pToCompare;
}

bool Lss::operator >= (const short& pToCompare){
	return _id >= pToCompare;
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 		PRIVATE		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void Lss::header()
{
	char * data = new char[12];
	for (int x=0; x<8; x++)
	{
		data[x]=0;
	}
	tmp = BytesHandler::bin2str( BytesHandler::unum2bin(_size, 4) );
	data[8] = tmp[0];
	data[9] = tmp[1];
	data[10] = tmp[2];
	data[11] = tmp[3];
	std::ofstream File;
	File.open(_disk);
	File.write (data, _blockSize);
	File.close();
}



/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 		PUBLIC		 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

Lss::Lss(const char * pDisk, short pID, int pSize, std::string pSecKey)
{
	char * temp = new char();
	std::strcpy(temp, pDisk);
	name = std::string(temp);
	_disk = temp;
	_busy = false;
	_id = pID;
	_size = pSize;
	_blockSize = 12;
	_secKey = pSecKey;
	header();
}

short Lss::write(char* pData, short pBlockPadre)
{
	short freeblock = getFreeBlock();
	
	if ( freeblock == 0)	/* no hay bloques libres */
	{
		freeblock = getLastBlock();
		if (freeblock == 0) 	/* error */
		{
			std::cout << "disco lleno";
		}
		else 	/* si hay un espacio */
		{
			new nextDirection = 12+(freeblock+1*_blockSize);
			write(BytesHandler::bin2str(BytesHandler::unum2bin(nextDirection, 2)), 6, 2); 	/* aumenta el apuntador al ultimo bloque sin uso */
			write(pData, (12+(freeblock*_blockSize), _blockSize);
		}
	}
	else 	/* si hay un bloque libre */
	{
		short freeblock2 = read( (12+(freeblock*_blockSize)), 2);		
		if (freeblock2 == 0) 	/* solo hay 1 bloque libre */ 
		{
			write( BytesHandler::bin2str(BytesHandler::unum2bin(0, 2)), 4, 2);
		}
		else 	/* hay mas de un bloque libre */
		{
			write( BytesHandler::bin2str(BytesHandler::unum2bin(freeblock2, 2)), 4, 2);
		}
		write(pData, (12+(freeblock*_blockSize), _blockSize);
	}
	
	if (pBlockPadre == 0) 	/* no tiene bloque predecesor */
	{	}
	else 	/* tiene un bloque predecesor */
	{
		std::string direction = DIRECTION + pDisk + TWOPOINTS + std::to_string().data();
		write(direction, 12+_blockSize*pBlockPadre, 14);
	}
	return freeblock;
}

void Lss::write(char* pData, int pPos, int pSize)
{
	std::fstream File;
	File.open(_disk);
	File.seekp ( pPos, File.beg);
	File.write (pData, pSize);
	File.close();
}

char * Lss::read(int pBlock)
{
	return read( (12+(pBlock*_blockSize)), _blockSize );
}

char * Lss::read(int pPos, int pSize)
{
	char * buffer = new char [pSize];
	std::ifstream file (_disk);
	file.seekg ( pPos, file.beg);
	file.read (buffer, pSize);
	file.close();
	return buffer;
}

short Lss::getFreeBlock()
{
	char * buffer = new char[2];
	buffer = read(4, 2);
	std::string tmp = BytesHandler::string2bin(std::string(buffer,2), 2);
	short tmp2 = BytesHandler::to_ulong(tmp);
	return tmp2;
}

int Lss::getBlockSize()
{
	return _blockSize;
}

std::string Lss::getSecKey(){
	return _secKey;
}

void Lss::format(int pBlockSize)
{
	
}

void Lss::eraseBlock(int pBlock)
{
	short BloqueLibre = temporal->getFreeBlock();
	while (true)
	{
		char * buffer = new char[2];
		buffer = read(BloqueLibre, 2);
		std::string tmp = BytesHandler::string2bin(std::string(buffer,2), 2);
		short tmp2 = BytesHandler::to_ulong(tmp);
		
		if (tmp2 == 0)
		{
			write ( BloqueLibre, 2, BytesHandler::bin2str( BytesHandler::unum2bin(pBlock, 2) ) );
			write ( pBlock, 2, BytesHandler::bin2str( BytesHandler::unum2bin(0, 2) ) );
			break;
		}
		else
		{
			BloqueLibre = tmp2;
		}
	}
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 		COMPARABLE		 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

bool Lss::eql(Comparable* arg)
{
	return _id == ( (Lss*) arg )->_id;
}

bool Lss::gtr(Comparable* arg)
{
	return true;
}

bool Lss::lss(Comparable* arg)
{
	return true;
}

void Lss::print()
{
	std::cout << _id << "(" << _size << ")" << " - ";
}
