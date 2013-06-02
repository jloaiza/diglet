#include <QtGui/QApplication>
#include <QtXml>
#include <QtCore>
#include <QtDebug>
#include <QXmlQuery>
#include <iostream>
#include <string>

class parserxml
{
public:
	void createDocument(std::string pName);
	void createRoot(std::string pName);
	void createRootChild(std::string pName);
	void createOtherChild(std::string pDirection, std::string pName);
	void createChildAttribute(std::string pIndicator, std::string pValue);
	void createChildValue(std::string pValue);
	void eraseChild(std::string pFatherDirection, std::string pChildName);
	void eraseAttribute(std::string pChildDirection, std::string pAttribute);
	void changeValue(std::string pChildDirection, std::string pValue);
	QDomElement tourXML(std::string pDirection);
	int getPositionChild(std::string pWord);
	std::string wordTokenExtract(std::string pWord);
	int caracterPosition(const char *pS , char pC);
	std::string obtainValue(std::string pXpath);
	void updateDocument();
	QDomElement getRoot(){return _root;}
	void setAuxChild(QDomElement pAuxChild){_auxChild = pAuxChild;}
	QDomElement getAuxChild(){return _auxChild;}
private:
	QDomDocument _document;
	QDomElement _root;
	QDomElement _auxChild;
	QFile _file;
};