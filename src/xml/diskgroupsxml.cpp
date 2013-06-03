#include "diskgroupsxml.h"

void diskgroupsxml::createXMLFile(std::string pDocumentDirection)
{
	parserxml* XMLParser = new parserxml();
	XMLParser->createDocument(pDocumentDirection);
	XMLParser->createRoot("Diskgroups");
	delete XMLParser;
}

void diskgroupsxml::addNode(std::string pDocumentDirection, std::string pNodeName)
{
	parserxml* XMLParser = new parserxml();
	XMLParser->loadDocument(pDocumentDirection);
	XMLParser->createRootChild(pNodeName);
	delete XMLParser;
}

void diskgroupsxml::addNodeAttribute(std::string pDocumentDirection, std::string pNodeDirection, std::string pNodeAttribute, std::string pValue)
{
	parserxml* XMLParser = new parserxml();
	XMLParser->loadDocument(pDocumentDirection);
	XMLParser->createAttribute(pNodeDirection,pNodeAttribute, pValue);
	delete XMLParser;
}

void diskgroupsxml::addNodeValue(std::string pDocumentDirection, std::string pNodeDirection, std::string pNodeValue)
{
	parserxml* XMLParser = new parserxml();
	XMLParser->loadDocument(pDocumentDirection);
	XMLParser->createValue(pNodeDirection, pNodeValue);
	delete XMLParser;
}

void diskgroupsxml::eraseNode(std::string pDocumentDirection, std::string pNodeDirection)
{
	parserxml* XMLParser = new parserxml();
	XMLParser->loadDocument(pDocumentDirection);
	XMLParser->eraseNode(pNodeDirection);
	delete XMLParser;
}

std::string diskgroupsxml::getAnyNodeValue(std::string pDocumentDirection, std::string pNodeDirection)
{
	parserxml* XMLParser = new parserxml();
	XMLParser->loadDocument(pDocumentDirection);
	std::string value = XMLParser->getAnyValue(pNodeDirection);
	delete XMLParser;
	return value;
}