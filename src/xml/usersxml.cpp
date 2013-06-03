#include "usersxml.h"

void usersxml::createXMLFile(std::string pName)
{
	XMLParser->createDocument(pName);
	XMLParser->createRoot("USERS");
}

void usersxml::addUser()
{
	XMLParser->createRootChild("User");
}

void usersxml::addUserAttribute(std::string pAttribute, std::string pValue)
{
	XMLParser->createChildAttribute(pAttribute, pValue);
}

void usersxml::addSecurityKey(std::string pDirection,std::string pSecurityKey)
{
	XMLParser->createOtherChild(pDirection, "Key");
	XMLParser->createChildValue(pSecurityKey);
}

std::string usersxml::getSecurityKey(std::string pId)
{
	return XMLParser->obtainValue(pId);
}