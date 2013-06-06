#ifndef LSSMANAGER
#define LSSMANAGER

#include "../structures/simplelist/simplelist.h"
#include "lssconsole.h"
#include "lssnetworkhandler.h"
#include "lss.h"

class LssConsole;
class LSSNetworkHandler;

/**
 * _lss lista de discos (LSS) en éste servidor de almacenamiento
 * _console instancia a la clase LssConsole
 * _networkHandler instancia a la clase LSSNetworkHandler
 * _disponibleID ids disponibles para usar como nombres de LSS (archivos reales) 
 */
class LssManager{
	
private:

	SimpleList* _lss;
	LssConsole* _console;
	LSSNetworkHandler* _networkHandler;
	short _disponibleID;

public:

	LssManager();
	
	Lss* getLSS(short pID);
	
	/**
	 * escribe en un LSS
	 * @param pData datos que se van a escribir en el disco
	 * @param pID id del disco sobre el cual vamos a escribir
	 * @param pBlockPadre bloque del predecesor, en caso de que exista algun bloque relacionado con éste nuevo bloque
	 * @return numero de bloque donde escribio los datos
	 * @version 2.0 	se cambio el valor de retorno y la variable pBlockPadre 
	 */
	short write(std::string pData, short pID, short pBlockPadre);
	
	/**
	 * lee datos de un LSS
	 * @param pID id del disco en el cual vamos a leer
	 * @param pBlock bloque que vamos a leer
	 * @return datos que se encontraban en el bloque
	 * @version 1.0 
	 */
	char* read(short pID, short pBlock);

	/**
	 * sobreescribe una posicion especifica dentro de un bloque en un LSS
	 * @param pData datos que se van a escribir en el bloque
	 * @param pID id del disco sobre el cual vamos a escribir
	 * @param pBlock bloque sobre el cual vamos a escribir
	 * @param pOffset posicion especifica en el bloque sobre la cual vamos a escribir
	 * @param pSize numero de bytes que se escribirán
	 * version 1.0
	 */
	void write_bytes(std::string pData, short pID, int pBlock, int pOffset, int pSize);

	/**
	 * lee una posicion especifica dentro de un bloque en un LSS
	 * @param pID id del disco sobre el cual vamos a leer
	 * @param pBlock bloque sobre el cual vamos a leer
	 * @param pOffset posicion especifica en el bloque sobre la cual vamos a leer
	 * @param pSize numero de bytes que se leerán
	 * @return datos que se leen
	 * version 1.0
	 */
	char* read_bytes(short pID, int pBlock, int pOffset, int pSize);
	
	/**
	 * @param pFileSize tamaño del disco en bytes
	 * @param pSecKey clave del disco
	 * @version 1.0
	 */
	void createDisk(int pFileSize, std::string pSecKey);
	
	/**
	 * @param pID id del disco que se va a borrar
	 * @param pSecKey clave del disco
	 * @version 1.0
	 */
	void eraseDisk(short pID, std::string pSecKey);
	
	void eraseBlock(short pID, short pBlock);
	
	
	/**
	 * @param pDiskID id del disco que se busca
	 * @return tamaño del LSS
	 * @return tamaño del bloque
	 * @version 1.0
	 */
	int getDiskSize(short pDiskID);

	/**
	 * @param pID id del bloque que se busca
	 * @return tamaño del bloque
	 * @version 1.0
	 */
	int getBlockSize(short pID);
	
	/**
	 * formatea un LSS
	 * @param pID disco que se va a formatear
	 * @param pBlockSize nuevo tamaño del disco
	 * @return tamaño del bloque
	 * @version 1.0
	 */
	void format(short pID, int pBlockSize);
	
	//short getFreeBlock(short pDiskID);	NOTA el lss se encarga de administrar los bloques libres

	void startSystem();
	
	
	
	/************************************		PRINTS		************************************/
	
	void showDisks();
	
	/*******************************************************************************************/
};

#endif
