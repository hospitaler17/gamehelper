#include "xmlparser.h"

XMLParser::XMLParser(QObject *parent) : QObject(parent)
{

}

bool XMLParser::readXmlFile(Person* person, QString filePath)
{
    QFile file(filePath);
    if( !file.open(QFile::ReadOnly | QFile::Text) )
    {
        QMessageBox::warning(nullptr,
                             tr("Ошибка файла"),
                             QString(tr("Не удалось открыть файл:\n")+file.fileName()),
                             QMessageBox::Ok);
        return false;
    }

    bool result = false;
    QXmlStreamReader reader;
    reader.setDevice(&file);
    reader.readNext();

    QVector<Spell *> spellsVector;

    while( !reader.atEnd()
           || !reader.hasError() )
    {
        if(reader.isStartElement())
        {
            XML_VIEW_CLASS elementName = reader.name();
            QString name = elementName.toString();

            if      (name == tr("main"))
            {
                QXmlStreamAttributes main = reader.attributes();
                person->setID(main.value("id").toInt());
                person->setName(main.value("name").toString());
                person->setPersonClass(main.value("class").toString());
                person->setPathToIcon(main.value("path_to_icon").toString());
                person->setType((PERSON_TYPE) main.value("type").toInt());
            }
            else if (name == tr("current"))
            {
                QXmlStreamAttributes current = reader.attributes();
                person->setDamage(current.value("damage").toInt());
                person->setHealth(current.value("health").toInt());
            }
            else if (name == tr("characteristics"))
            {
                QXmlStreamAttributes characteristics = reader.attributes();
                person->setInitiative(characteristics.value("initiative").toInt());
                person->setStrength(characteristics.value("strength").toInt());
                person->setAgility(characteristics.value("agility").toInt());
                person->setIntelligence(characteristics.value("intelligence").toInt());
                person->setCharisma(characteristics.value("charisma").toInt());
                person->setMainChars((PERSON_CHARACTERISTICS)characteristics.value("main_chars").toInt());

                result = true; //NOTE: поставил тут, как специальный раздел для Person
            }
            else if (name == tr("spell"))
            {
                QXmlStreamAttributes spells = reader.attributes();
                Spell * spell = new Spell();
                spell->setID(spells.value("id").toLongLong());

                if(findSpellByID(spell))
                    spellsVector.append(spell);
                delete spell;
            }

        }
        reader.readNext();
    }
    file.close();
    person->setSpells(spellsVector);

    return result;
}

bool XMLParser::writeXmlFile(Person *person, QString filename)
{
    QFile file(makeFullPathToFile(filename, person->objectType()));
    if( !file.open(QFile::WriteOnly) )
    {
        QMessageBox::warning(nullptr,
                             tr("Ошибка файла"),
                             QString(tr("Не удалось записать файл:\n")+file.fileName()),
                             QMessageBox::Ok);
        return false;
    }

    QXmlStreamWriter writer(&file);
    writer.setAutoFormatting(true);
    writer.writeStartDocument();
    writer.writeStartElement("person");

    // Основные атрибуты
    writer.writeStartElement("main");
    writer.writeAttribute("id",             QString::number(person->ID()));
    writer.writeAttribute("name",           person->name());
    writer.writeAttribute("class",          person->personClass());
    writer.writeAttribute("path_to_icon",   person->pathToIcon());
    writer.writeAttribute("type",           QString::number(person->type()));
    writer.writeEndElement(); // main

    // Текущие атрибуты
    writer.writeStartElement("current");
    writer.writeAttribute("damage",         QString::number(person->damage()));
    writer.writeAttribute("health",         QString::number(person->maxHealth()));
    writer.writeEndElement(); // current

    // Характеристика
    writer.writeStartElement("characteristics");
    writer.writeAttribute("initiative",     QString::number(person->initiative()));
    writer.writeAttribute("strength",       QString::number(person->strength()));
    writer.writeAttribute("agility",        QString::number(person->agility()));
    writer.writeAttribute("intelligence",   QString::number(person->intelligence()));
    writer.writeAttribute("charisma",       QString::number(person->charisma()));
    writer.writeAttribute("main_chars",     QString::number(person->mainChars()));
    writer.writeEndElement(); // characteristics

    // Способности
    writer.writeStartElement("spells");

    for(int i = 0; i < person->getSpells().count(); ++i)
    {
        writer.writeStartElement("spell");
        writer.writeAttribute("id", QString::number(person->getSpells().at(i)->ID()));
        QString filename = QString::number(person->getSpells().at(i)->ID()) + tr("_") + person->getSpells().at(i)->name();
        writeXmlFile(person->getSpells().at(i), filename);
        writer.writeEndElement(); // spell
    }
    writer.writeEndElement(); // spells

    writer.writeEndElement(); // person


    writer.writeEndDocument();

    file.close();
    return true;
}

bool XMLParser::readXmlFile(Spell *spell, QString filePath)
{
    QFile file(filePath);
    if( !file.exists() || !file.open(QFile::ReadOnly) )
    {
        QMessageBox::warning(nullptr,
                             tr("Ошибка файла"),
                             QString(tr("Не удалось открыть файл:\n")+file.fileName()),
                             QMessageBox::Ok);
        return false;
    }

    bool result = false;
    QXmlStreamReader reader;
    reader.setDevice(&file);
    reader.readNext();
    while( !reader.atEnd() && !reader.hasError() )
    {
        if(reader.isStartElement())
        {
            XML_VIEW_CLASS elementName = reader.name();
            QString name = elementName.toString();

            if      (name == tr("main"))
            {
                QXmlStreamAttributes main = reader.attributes();
                spell->setID(main.value("id").toInt());
                spell->setName(main.value("name").toString());
            }
            else if (name == tr("special"))
            {
                QXmlStreamAttributes special = reader.attributes();
                spell->setDescription(special.value("description").toString());
                spell->setCooldawn(special.value("cooldawn").toInt());
                result = true; //NOTE: поставил тут, как специальный раздел для Spell
            }
        }
        reader.readNext();
    }
    file.close();

    return result;
}

bool XMLParser::writeXmlFile(Spell *spell, QString filename)
{
    QFile file(makeFullPathToFile(filename, spell->objectType()));
    if( !file.open(QFile::WriteOnly) )
    {
        QMessageBox::warning(nullptr,
                             tr("Ошибка файла"),
                             QString(tr("Не удалось записать файл:\n")+file.fileName()),
                             QMessageBox::Ok);
        return false;
    }

    QXmlStreamWriter writer(&file);
    writer.setAutoFormatting(true);
    writer.writeStartDocument();
    writer.writeStartElement("spell");

    // Основные атрибуты
    writer.writeStartElement("main");
    writer.writeAttribute("id", QString::number(spell->ID()));
    writer.writeAttribute("name", spell->name());
    writer.writeEndElement(); // main

    // Особые атрибуты
    writer.writeStartElement("special");
    writer.writeAttribute("description", spell->description());
    writer.writeAttribute("cooldawn", QString::number(spell->cooldawn()));
    writer.writeEndElement(); // special

    writer.writeEndElement(); // spell
    writer.writeEndDocument();

    return true;
}

QDir XMLParser::savePath() const
{
    return _savePath;
}

void XMLParser::setSavePath(const QDir &savePath)
{
    _savePath = savePath;
}

bool XMLParser::findSpellByID(Spell * spell)
{
    quint64 ID = spell->ID();

    QString textID = tr("*") + QString::number(ID) + tr("*");
    QStringList listNameFilters;
    listNameFilters << textID;
    QDir searchDir(_savePath);
    searchDir.cd(Common::getXMLsSubDir(OXT_SPELL));
    QFileInfoList fileInfoList = searchDir.entryInfoList(listNameFilters, QDir::Files, QDir::Name);

    for(int i = 0; i < fileInfoList.count(); ++i)
    {
        if(readXmlFile(spell, fileInfoList.at(i).absoluteFilePath())
                && spell->ID() == ID)
        {
            return true;
        }
    }
    return false;
}

QString XMLParser::makeFullPathToFile(QString fn, OBJECT_XML_TYPE oxt)
{
    QString subdir = Common::getXMLsSubDir(oxt);
    QString path = fn;
    if( _savePath.mkpath(subdir) )
    {
        path.push_front(subdir);
    }
    return path.contains(".xml", Qt::CaseInsensitive)?path:path+tr(".xml");
}


