#include "usersxml.h"

void usersxml::createXMLFile(std::string pDocumentDirection)
{
	parserxml* XMLParser = new parserxml();
	XMLParser->createDocument(pDocumentDirection);
	XMLParser->createRoot("USERS");
	delete XMLParser;
}

void usersxml::addUser(std::string pDocumentDirection)
{
	parserxml* XMLParser = new parserxml();
	XMLParser->loadDocument(pDocumentDirection);
	XMLParser->createRootChild("User");
	delete XMLParser;
}

void usersxml::addUserAttribute(std::string pDocumentDirection, std::string pUserDirection, std::string pUserAttribute, std::string pValue)
{
	parserxml* XMLParser = new parserxml();
	XMLParser->loadDocument(pDocumentDirection);
	XMLParser->createAttribute(pUserDirection,pUserAttribute, pValue);
	delete XMLParser;
}

void usersxml::addSecurityKey(std::string pDocumentDirection, std::string pUserDirection, std::string pSecurityKey)
{
	parserxml* XMLParser = new parserxml();
	XMLParser->loadDocument(pDocumentDirection);
	XMLParser->createOtherChild(pUserDirection, "Key");
	std::string keydirection = std::string(pUserDirection) + std::string("Key/");
	XMLParser->createValue(keydirection, pSecurityKey);
	delete XMLParser;
}

std::string usersxml::getSecurityKey(std::string pDocumentDirection, std::string pUserKeyDirection)
{
	parserxml* XMLParser = new parserxml();
	XMLParser->loadDocument(pDocumentDirection);
	std::string value = XMLParser->getAnyValue(pUserKeyDirection);
	delete XMLParser;
	return value;
}