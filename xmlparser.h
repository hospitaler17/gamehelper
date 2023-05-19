#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <QtXml>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QXmlStreamAttribute>
#include <QFile>
#include <QMessageBox>

#include "common.h"
#include "objects/person.h"
#include "objects/battle.h"
#include "objects/map.h"
#include "objects/spell.h"

class XMLParser : public QObject
{
    Q_OBJECT
public:
    explicit XMLParser(QObject *parent = nullptr);

    void readXmlFile(Person *person, QString filename);
    void writeXmlFile(Person *person, QString filename);
    void writeXmlFile(Spell *spell, QString filename);

    QDir savePath() const;
    void setSavePath(const QDir &savePath);

private:
    OBJECT_XML_TYPE _type;

    QDir _savePath;

    QString makeFullPathToFile(QString fn);
signals:

public slots:

};

#endif // XMLPARSER_H
