#ifndef LSS
#define LSS

#include "../util/comparable.h"
#include <string>

class Lss : public Comparable {
	
private:
    const char* _disk;
	bool _busy;
	int _size;
	int _blockSize;
	short _id;
	std::string _secKey;
	
	/**
	 * construye el header del lss (binario)
	 */
	void header();

public:

    Lss(const char*  pDisk, short pID, int pSize, std::string pSecKey);

	/**
	 * escribe en el disco
	 * @param pData informacion que escribiremos en el LSS
	 * @param pBlockPadre bloque del predecesor, en caso de que exista algun bloque relacionado con éste nuevo bloque
	 * @return numero de bloque donde escribimos
	 * @version 2.0 	se implemento para que busque un bloque libre, y retorne el numero de bloque que se utilizo
	 */
	short write (char* pData, short pBlockPadre);
	
	/**
	 * escribe cualquier cantidad de caracteres en cualquier posicion del LSS
	 * @param pData datos que se escriben en el disco
	 * @param pPos posicion especifica en el disco
	 * @param pSize cantidad de caracteres que se van a escribir
	 */
	void write (char* pData, int pPos, int pSize);
	
	/**
	 * @param pBlock bloque que se va a leer
	 * @return datos leidos
	 */
	char* read(int pBlock);	
		
	/**
	 * lee cualquier cantidad de caracteres en cualquier posicion del disco
	 * @param pPos posicion dentro del disco
	 * @param pSize cantidad de caracteres que se van a leer
	 * @return datos que leyó del disco
	 */
	char *read(int pPos, int pSize);
	
	/**
	 * @return numero del bloque libre
	 */
	short getFreeBlock();
	
	int getBlockSize();
	
	std::string getSecKey();
	
	/**
	 * formatea el disco; borrando los datos y estableciendo un nuevo tamaño de bloque
	 * @param pBlockSize nuevo tamaño del bloque 
	 */
	void format(int pBlockSize);

	
	void eraseBlock(int pBlock);


	
	bool eql(Comparable* arg);
	bool gtr(Comparable* arg);
	bool lss(Comparable* arg);
	void print();

	bool operator != (const short& pToCompare);
	bool operator == (const short& pToCompare);
	bool operator < (const short& pToCompare);
	bool operator <= (const short& pToCompare);
	bool operator > (const short& pToCompare);
	bool operator >= (const short& pToCompare);

};

#endif
