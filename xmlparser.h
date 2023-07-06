#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <QtXml>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QXmlStreamAttribute>
#include <QFile>
#include <QFileInfoList>
#include <QMessageBox>

#if QT_VERSION >= QT_VERSION_CHECK(5,10,0)
#include <QStringView>
#define XML_VIEW_CLASS QStringView
#else
#include <QStringRef>
#define XML_VIEW_CLASS QString
#endif

#include "common.h"
#include "game/actors/person.h"
#include "game/maps/battle.h"
#include "game/maps/map.h"
#include "objects/spell.h"

#define ROOT_SAVE_XMLS_PATH "xml"
Q_FORWARD_DECLARE_OBJC_CLASS(Spell);
Q_FORWARD_DECLARE_OBJC_CLASS(Map);
Q_FORWARD_DECLARE_OBJC_CLASS(Person);
Q_FORWARD_DECLARE_OBJC_CLASS(Battle);

class XMLParser : public QObject
{
    Q_OBJECT
public:
    explicit XMLParser(QObject *parent = nullptr);

    bool readXmlFile(Person *person, QString filePath);
    bool writeXmlFile(Person *person, QString filename);

    bool readXmlFile(Spell *spell, QString filePath);
    bool writeXmlFile(Spell *spell, QString filename);

    QDir savePath() const;
    void setSavePath(const QDir &savePath);


private:
    OBJECT_XML_TYPE _type;

    QDir _savePath;

    template<typename T>
    bool findXMLByID(T * object);

    QString makeFullPathToFile(QString fn, OBJECT_XML_TYPE oxt = OXT_UNDEFINED);
signals:

public slots:

};

#endif // XMLPARSER_H
