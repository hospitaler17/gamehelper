#include "xmlparser.h"

XMLParser::XMLParser(OBJECT_XML_TYPE type, QObject *parent) : QObject(parent)
{
    _type = type;
}

void XMLParser::openFile(QString filename)
{

}
