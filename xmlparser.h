#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <QtXml>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QXmlStreamAttribute>
#include <QFile>
#include <QFileInfoList>
#include <QMessageBox>
#if QT_VERSION > 0x060000
#include <QStringView>
#define XML_NAME(x) QStringView(x)
#else
#include <QStringRef>
#define XML_NAME(str) (str)
#endif

#include "common.h"
#include "game/actors/person.h"
#include "game/maps/battle.h"
#include "game/maps/map.h"
#include "objects/spell.h"

#define ROOT_SAVE_PATH "xml"
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

    bool findSpellByID(Spell *spell);
    QString makeFullPathToFile(QString fn, OBJECT_XML_TYPE oxt = OXT_UNDEFINED);
signals:

public slots:

};

#endif // XMLPARSER_H
