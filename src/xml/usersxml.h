#include "parserxml.h"

class usersxml
{
public:
	void createXMLFile(std::string pName);
	void addUser();
	void addUserAttribute(std::string pAttribute, std::string pValue);
	void addSecurityKey(std::string pDirection,std::string pSecurityKey);
	std::string getSecurityKey(std::string pId);
private:
	parserxml* XMLParser = new parserxml();
};