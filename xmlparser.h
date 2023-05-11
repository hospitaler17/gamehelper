#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <QtXml>

#include "common.h"
#include "objects/person.h"
#include "objects/battle.h"
#include "objects/map.h"
#include "objects/spell.h"

class XMLParser : public QObject
{
    Q_OBJECT
public:
    explicit XMLParser(OBJECT_XML_TYPE type, QObject *parent = nullptr);

private:
    OBJECT_XML_TYPE _type;
signals:

public slots:
    void openFile(QString filename);

};

#endif // XMLPARSER_H
