#ifndef DISKGROUP
#define DISKGROUP

//#include "resgisterspacer.h"
//#include "../basicstructures/datanode.h"

class RegisterSpace;
class DataBuffer;
class DataNode;


class DiskGroup 
{
	
public:
	
	
	/* operaciones sobre el arbol n-ario */
	
	
	/**
	 * busca y retorna un archivo del disco
	 * @param pPath nombre o direccion del archivo ficticio
	 * @param pUser nombre del usuario que realiza la operacion
	 * @return true si la operacion se realizo con exito, false de lo contrario
	 */
	virtual bool getFile(char* pPath, char* pUser) = 0;
	
	/**
	 * borra un archivo o una carpeta
	 * @param pPath nombre o direccion del archivo ficticio
	 * @param pUser nombre del usuario que realiza la operacion
	 * @return true si la operacion se realizo con exito, false de lo contrario
	 */
	virtual bool deleteFile(char* pPath, char* pUser) = 0;
	
	//virtual void eraseFolder(char* pPath);
	//virtual void eraseFile(char* pPath);
	
	/**
	 * crea un nuevo archivo
	 * @param pName nombre o direccion del nuevo archivo ficticio
	 * @param pRegister formato de cada registro del nuevo archivo
	 * @param pUser nombre del usuario que realiza la operacion
	 */
	virtual bool createFile(char* pPath, RegisterSpace pRegister, char* pUser) = 0;
	
	
	/* operaciones sobre el registros */
	
	
	/**
	 * agrega un registro al final (despues del ultimo registro almacenado)
	 * @param pPath nombre o direccion del nuevo archivo ficticio
	 * @param pUser nombre del usuario que realiza la operacion
	 * @param pData datos que contiene el registro
	 */
	virtual void appendRegister(char* pPath, char* pUser, DataNode* pData) = 0;
	
	/**
	 * borrar un registro
	 * @param pPath nombre o direccion del nuevo archivo ficticio
	 * @param pUser nombre del usuario que realiza la operacion
	 * @param pRegisterNumber numero de registro
	 */
	virtual bool eraseRegister(char* pPath, char* pUser, int pRegisterNumber) = 0;
	
	/**
	 * sobreescribe un registro
	 * @param pPath nombre o direccion del nuevo archivo ficticio
	 * @param pUser nombre del usuario que realiza la operacion
	 * @param pRegisterNumber numero de registro 
	 * @param pData datos que contiene el registro
	 */
	virtual void writeRegister(char* pPath, char* pUser, int pRegisterNumber, DataNode* pData) = 0;
	
	/**
	 * leer un registro
	 * @param pPath nombre o direccion del nuevo archivo ficticio
	 * @param pUser nombre del usuario que realiza la operacion
	 * @param pRegisterNumber numero de registro
	 */
	virtual DataNode* readRegister(char* pPath, char* pUser, int pRegisterNumber) = 0;
		
	
	/* 	virtual bool getFilesTree(char* pPath, char* pUser);  */
};

#endif
