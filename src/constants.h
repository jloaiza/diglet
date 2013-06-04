
#ifndef CONSTANTS
#define CONSTANTS

class Constants
{
	static const short BOOL = 1;
	static const short CHAR = 2;
	static const short SHORT = 3;
	static const short INT = 4;
	static const short DOUBLE = 5;
	static const short STRING = 6;


	std::string lssmenuL = "** * * * * * * * * * * * * * * * * *";
	std::string lssmenuS = "*                                  *";
	std::string lssmenu3 = "*     seleccione la operacion:     *";
	std::string lssmenu4 = "*       1. Crear disco nuevo       *";
	std::string lssmenu5 = "*       2. Borrar disco            *";
	std::string lssmenu6 = "*       3. Mostrar discos          *";
	std::string lssmenu7 = "*       4. SAVE                    *";
	std::string lssmenu8 = "*       5. LOAD                    *";
	std::string lssmenu9 = "*       6. Salir                   *";

	std::string NAME = "nombre del disco (archivo real): ";
	std::string NAME2 = "nombre del xml: ";
	std::string SIZE1 = "tamaño del disco (bytes): ";
	std::string PASS = "security key: ";
}



#endif
