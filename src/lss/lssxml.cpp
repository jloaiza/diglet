#include "lssxml.h"

void lssxml::createXMLFile(std::string pName)
{
	XMLParser.createDocument(pName);
	XMLParser.createRoot("LSS");
}

void lssxml::addDisk()
{
	XMLParser.createRootChild("Disk");
}

void lssxml::addDiskAttribute(std::string pAttribute, std::string pValue)
{
	XMLParser.createChildAttribute(pAttribute, pValue);
}

void lssxml::addSecurityKey(std::string pDirection,std::string pSecurityKey);
{
	XMLParser.createOtherChild(pDirection, "Key");
	XMLParser.createChildValue(pSecurityKey);
}

std::string lssxml::getSecurityKey(std::string pId)
{
	return XMLParser.obtainValue(pId);
}

void lssxml::eraseDisk(std::string pFatherDirection, std::string pDiskName);
{
	XMLParser.eraseChild(pFatherDirection, pDiskName);
}