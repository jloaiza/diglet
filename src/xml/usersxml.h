#include "parserxml.h"

class usersxml
{
public:
	static void createXMLFile(std::string pDocumentDirection);
	static void addUser(std::string pDocumentDirection);
	static void addUserAttribute(std::string pDocumentDirection, std::string pUserDirection, std::string pUserAttribute, std::string pValue);
	static void addSecurityKey(std::string pDocumentDirection, std::string pUserDirection, std::string pSecurityKey);
	static std::string getSecurityKey(std::string pDocumentDirection, std::string pUserKeyDirection);
};
