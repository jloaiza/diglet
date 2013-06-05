#include "../xml/parserxml.h"

class lssxml
{
public:
	static void createXMLFile(std::string pDocumentDirection);
	static void addDisk(std::string pDocumentDirection);
	static void addDiskAttribute(std::string pDocumentDirection, std::string pDiskDirection, std::string pDiskAttribute, std::string pValue);
	static void addSecurityKey(std::string pDocumentDirection, std::string pDiskDirection, std::string pSecurityKey);
	static void eraseDisk(std::string pDocumentDirection, std::string pDiskDirection);
	static std::string getSecurityKey(std::string pDocumentDirection, std::string pDiskKeyDirection);
};
