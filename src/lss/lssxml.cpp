#include "lssxml.h"

void lssxml::createXMLFile(std::string pDocumentDirection)
{
	parserxml* XMLParser = new parserxml();
	XMLParser->createDocument(pDocumentDirection);
	XMLParser->createRoot("LSS");
	delete XMLParser;
}

void lssxml::addDisk(std::string pDocumentDirection)
{
	parserxml* XMLParser = new parserxml();
	XMLParser->loadDocument(pDocumentDirection);
	XMLParser->createRootChild("Disk");
	delete XMLParser;
}

void lssxml::addDiskAttribute(std::string pDocumentDirection, std::string pDiskDirection, std::string pDiskAttribute, std::string pValue)
{
	parserxml* XMLParser = new parserxml();
	XMLParser->loadDocument(pDocumentDirection);
	XMLParser->createAttribute(pDiskDirection,pDiskAttribute, pValue);
	delete XMLParser;
}

void lssxml::addSecurityKey(std::string pDocumentDirection, std::string pDiskDirection, std::string pSecurityKey)
{
	parserxml* XMLParser = new parserxml();
	XMLParser->loadDocument(pDocumentDirection);
	XMLParser->createOtherChild(pDiskDirection, "Key");
	std::string keydirection = std::string(pDiskDirection) + std::string("Key/");
	XMLParser->createValue(keydirection, pSecurityKey);
	delete XMLParser;
}

void lssxml::eraseDisk(std::string pDocumentDirection, std::string pDiskDirection)
{
	parserxml* XMLParser = new parserxml();
	XMLParser->loadDocument(pDocumentDirection);
	XMLParser->eraseNode(pDiskDirection);
	delete XMLParser;
}

std::string lssxml::getSecurityKey(std::string pDocumentDirection, std::string pDiskKeyDirection)
{
	parserxml* XMLParser = new parserxml();
	XMLParser->loadDocument(pDocumentDirection);
	std::string value = XMLParser->getAnyValue(pDiskKeyDirection);
	delete XMLParser;
	return value;
}