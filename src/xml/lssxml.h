#include "parserxml.h"

class lssxml
{
public:
	void createXMLFile(std::string pName);
	void addDisk();
	void addDiskAttribute(std::string pAttribute, std::string pValue);
	void addSecurityKey(std::string pDirection,std::string pSecurityKey);
	std::string getSecurityKey(std::string pId);
	void eraseDisk(std::string pFatherDirection, std::string pDiskName);
private:
	parserxml* XMLParser = new parserxml();
};