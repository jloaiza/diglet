#include "parserxml.h"

class diskgroupsxml
{
public:
	static void createXMLFile(std::string pDocumentDirection);
	static void addNode(std::string pDocumentDirection, std::string pNodeName);
	static void addNodeAttribute(std::string pDocumentDirection, std::string pNodeDirection, std::string pNodeAttribute, std::string pValue);
	static void addNodeValue(std::string pDocumentDirection, std::string pNodeDirection, std::string pNodeValue);
	static void eraseNode(std::string pDocumentDirection, std::string pNodeDirection);
	static std::string getAnyNodeValue(std::string pDocumentDirection, std::string pNodeDirection);
};
