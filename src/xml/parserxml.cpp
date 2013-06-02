#include "parserxml.h"

void parserxml::createDocument(std::string pName)
{
	_file.setFileName(QString::fromStdString(pName));
    updateDocument();
}

void parserxml::updateDocument()
{
    if( !_file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Lo sentimos, no se pudo crear el documento XML";
    }
    else
    {
        QTextStream  ts( &_file );
        ts << _document.toString();
        _file.close();
        qDebug() << "Archivo XML actualizado con exito.";
    }  
}

void parserxml::createRoot(std::string pName)
{
	_root = _document.createElement(QString::fromStdString(pName));
    _document.appendChild(_root);
    setAuxChild(_root);
    qDebug() << "Root creada con exito.";
}

void parserxml::createRootChild(std::string pName)
{
    QDomElement child = _document.createElement(QString::fromStdString(pName));
    getRoot().appendChild(child);
    setAuxChild(child);
    qDebug() << "Hijo creado con exito.";

}

void parserxml::createOtherChild(std::string pDirection, std::string pName)
{
	QDomElement child = _document.createElement(QString::fromStdString(pName));
    QDomElement childadd = tourXML(pDirection);
	childadd.appendChild(child);
    setAuxChild(child);
    qDebug() << "Hijo creado con exito.";

}

void parserxml::createChildAttribute(std::string pIndicator, std::string pValue)
{
    getAuxChild().setAttribute(QString::fromStdString(pIndicator),QString::fromStdString(pValue));
    qDebug() << "Atributo creado con exito.";
}

void parserxml::createChildValue(std::string pValue)
{
    QDomText value = _document.createTextNode(QString::fromStdString(pValue));
    getAuxChild().appendChild(value);
    qDebug() << "Hijo valor creado con exito.";
}

std::string parserxml::obtainValue(std::string pXpath)
{
    if( !_file.open(QIODevice::ReadOnly))
    {
        qDebug() << "No se pudo abrir el XML para lectura.";
    }
    else
    {
        QXmlQuery query;
        query.bindVariable("document", &_file);
        std::string stringdocument = "doc($document)";
        std::string finalstring = std::string(stringdocument) + std::string(pXpath);
        query.setQuery(QString::fromStdString(finalstring));
        if(!query.isValid()) 
        {
           qDebug()<< "Xpath invalido.";
        }
        QString queryresult;
        query.evaluateTo(&queryresult); 
        _file.close();
        return queryresult.toStdString();
    }  
}

int parserxml::getPositionChild(std::string pWord)
{
    int finalnumber;
    std::string auxstring = "";
    int index = (pWord.size()-2);
    char letra = pWord.c_str()[index];
    while(!isalpha(letra) && letra != '[')
    {
        auxstring = std::string(1,letra) + std::string(auxstring);
        index--;
        letra = pWord.c_str()[index];
    }
    if(auxstring == "")
    {
        finalnumber = 0;
    }
    else
    {
        finalnumber = atoi(auxstring.c_str());
    }
    return finalnumber;
}

int parserxml::caracterPosition(const char *pS, char pC)
{
    const char *p = pS;
    int counter = 1;
    while (*p != pC && *p)
    {
        counter++;
        p++;
    }
    return counter-1;
}

std::string parserxml::wordTokenExtract(std::string pWord)
{
    std::string auxstring;
    char letra = pWord.c_str()[pWord.size()-1];
    if(letra == ']')
    {
        int position = caracterPosition(pWord.c_str(),'[');
        auxstring = pWord.substr(0,position);
    }
    else
    {
        auxstring = pWord;
    }
    return auxstring;
}

QDomElement parserxml::tourXML(std::string pDirection)
{
    QDomElement actualelement = getRoot();
    std::string completedirection = pDirection;
    std::string delimiter = "/";
    size_t pos = 0;
    std::string token;
    while ((pos = completedirection.find(delimiter)) != std::string::npos) 
    {
        token = completedirection.substr(0, pos);
        int numberchild = getPositionChild(token);
        std::string wordextract = wordTokenExtract(token);
        actualelement = actualelement.elementsByTagName(QString::fromStdString(wordextract)).at(numberchild).toElement();
        completedirection.erase(0, pos + delimiter.length());
    }
    return actualelement;
}

void parserxml::eraseAttribute(std::string pChildDirection, std::string pAttribute)
{
    QDomElement childaux = tourXML(pChildDirection);
    childaux.removeAttribute(QString::fromStdString(pAttribute));
}

void parserxml::changeValue(std::string pChildDirection, std::string pValue)
{
    QDomElement childaux= tourXML(pChildDirection);
    childaux.setNodeValue(QString::fromStdString(pValue));
}

void parserxml::eraseChild(std::string pFatherDirection, std::string pChildName)
{
    int index = getPositionChild(pChildName);
    QDomElement childaux = tourXML(pFatherDirection);
    childaux.removeChild(childaux.elementsByTagName(QString::fromStdString(pChildName)).at(index));
}