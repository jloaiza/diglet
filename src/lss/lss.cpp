#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "../binaryoperations/byteshandler.h"
#include "lss.h"


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


/**
 * constructor de la clase LSS
 * @param pDisk nombre o directorio del lss (archivo real)
 * @param pID nombre del lss, para comparaciones
 * @param pSize tamaño maximo del disco;
 */
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

/**
 * construye el header del lss (binario)
 */
void Lss::header()
{
	char * data = new char[12];
	for (int x=0; x<4; x++)
	{
		data[x]=0;
	}
	std::string tmp = BytesHandler::bin2str( BytesHandler::unum2bin(1, 2) );
	data[4] = tmp[0];
	data[5] = tmp[1];
	data[6] = 0;
	data[7] = 0;
	tmp = BytesHandler::bin2str( BytesHandler::unum2bin(_size, 4) );
	data[8] = tmp[0];
	data[9] = tmp[1];
	data[10] = tmp[2];
	data[11] = tmp[3];
	std::ofstream File;
	File.open(_disk);
	File.write (data, _blockSize);
	File.close();
	//delete[] data;
}

/**
 * escribe en el disco
 * @param pText informacion que escribiremos en el disco
 * @param pBlock bloque sobre el cual escribiremos
 */
void Lss::write(char* pText, int pBlock)
{
	write(pText, pBlock, 0, _blockSize);
}

/**
 * metodo para leer un bloque del disco
 * @param pBlock bloque que se va a leer
 */
char * Lss::read(int pBlock)
{
	read(pBlock, 0, _blockSize);
}

/**
 * retorna un bloque libre para escribir
 * @return numero del bloque
 */
int Lss::getFreeBlock()
{
	char * buffer = new char[2];
	buffer = read(4, 2);
	std::string tmp = BytesHandler::string2bin(std::string(buffer,2), 2);
	short tmp2 = BytesHandler::to_ulong(tmp);
	return tmp2;
}

std::string Lss::getSecKey(){
	return _secKey;
}


void Lss::eraseBlock(int pBlock)
{
	
}

/**
 * retorna el tamaño de cada bloque en el disco
 * @return tamaño de cada bloque
 */
int Lss::getBlockSize()
{
	return _blockSize;
}

/**
 * formatea el disco; borrando los datos y estableciendo un nuevo tamaño de bloque
 * @param pBlockSize nuevo tamaño del bloque 
 */
void Lss::format(int pBlockSize)
{
	
}

/**
 * escribe en un sector determinado de un bloque
 * @param pText datos que escribir en el bloque
 * @param pBlock numero de bloque
 * @param pOffset posicion dentro del bloque donde hay que escribir
 * @param pSize cantidad de bytes que se escribirán
 */
void Lss::write(char* pText, int pBlock, int pOffset, int pSize)
{
	std::cout<<"H1"<<std::endl;
	/* abre el archivo */
	std::fstream File;
	File.open(_disk);
	/* mueve el puntero al final para verificar el tamaño del archivo */
	std::cout<<"H2"<<std::endl;
	File.seekp ( 12*(pBlock)+pOffset, File.beg);
	std::cout<<"H3"<<std::endl;
	File.write (pText, pSize);
	File.close();
}

/**
 * lee en un sector determinado de un bloque
 * @param pBlock numero de bloque
 * @param pOffset posicion dentro del bloque donde hay que leer
 * @param pSize cantidad de bytes que se escribirán
 * @return caractareres leídos del disco
 */
char* Lss::read (int pBlock, int pOffset, int pSize)
{
	/* arreglo para contener los datos leídos */
	char * buffer = new char [pSize];
	/* abre el archivo */
	std::ifstream file (_disk);
	/* mueve el puntero desde la posicion inicial hasta la posicion pBlock */
	file.seekg ( 12*(pBlock)+pOffset, file.beg);
	/* lee directamente el archivo desde pBlock hasta (pBlock + pBlockSize) */
	file.read (buffer, pSize);
	file.close();
	return buffer;
}

/**
 * lee cualquier cantidad de caracteres en cualquier posicion del disco
 * @param pPos posicion dentro del disco
 * @param pSize cantidad de caracteres que se van a leer
 * @return datos que leyó del disco
 */
char * Lss::read(int pPos, int pSize)
{
	/* arreglo para contener los datos leídos */
	char * buffer = new char [pSize];
	/* abre el archivo */
	std::ifstream file (_disk);
	/* mueve el puntero desde la posicion inicial hasta la posicion pBlock */
	file.seekg ( pPos, file.beg);
	/* lee directamente el archivo desde pBlock hasta (pBlock + pBlockSize) */
	file.read (buffer, pSize);
	file.close();
	return buffer;
}

/**
 * escribe cualquier cantidad de caracteres en cualquier posicion del disco
 * @param pPos posicion dentro del disco
 * @param pSize cantidad de caracteres que se van a escribir
 * @param pData datos que se escriben en el disco
 */
void Lss::write(int pPos, int pSize, char* pData)
{
	/* abre el archivo */
	std::fstream File;
	File.open(_disk);
	/* mueve el puntero al final para verificar el tamaño del archivo */
	File.seekp ( pPos, File.beg);
	File.write (pData, pSize);
	File.close();
}


/* metodos heredados de Comparable */


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