#include "xmlparser.h"

XMLParser::XMLParser(QObject *parent) : QObject(parent)
{
}

void XMLParser::readXmlFile(Person* person, QString filePath)
{
    QFile file(filePath);
    if( !file.open(QFile::ReadOnly | QFile::Text) )
    {
        QMessageBox::warning(nullptr,
                             tr("Ошибка файла"),
                             QString(tr("Не удалось открыть файл:\n")+file.fileName()),
                             QMessageBox::Ok);
        return;
    }

    QXmlStreamReader reader;
    reader.setDevice(&file);
    reader.readNext();
    while( !reader.atEnd() && !reader.hasError() )
    {
        if(reader.isStartElement())
        {
            if      (reader.name() == "main")
            {
                QXmlStreamAttributes main = reader.attributes();
                person->setID(main.value("id").toInt());
                person->setName(main.value("name").toString());
                person->setPersonClass(main.value("class").toString());
                person->setPathToIcon(main.value("path_to_icon").toString());
                person->setType((PERSON_TYPE) main.value("type").toInt());

            }
            else if (reader.name() == "current")
            {
                QXmlStreamAttributes current = reader.attributes();
                person->setDamage(current.value("damage").toInt());
                person->setHealth(current.value("health").toInt());
            }
            else if (reader.name() == "characteristics")
            {
                QXmlStreamAttributes characteristics = reader.attributes();
                person->setInitiative(characteristics.value("initiative").toInt());
                person->setStrength(characteristics.value("strength").toInt());
                person->setAgility(characteristics.value("agility").toInt());
                person->setIntelligence(characteristics.value("intelligence").toInt());
                person->setCharisma(characteristics.value("charisma").toInt());
                person->setMainChars((PERSON_CHARACTERISTICS)characteristics.value("main_chars").toInt());
            }
            else if (reader.name() == "spells")
            {
                QXmlStreamAttributes spells = reader.attributes();
                QVector<Spell *> spellsVector;
                for(int i = 0; i < spells.count(); ++i)
                {
                    Spell * spell = new Spell();
                    spell->setID(spells.at(i).value().toInt());

                    if(findSpellByID(spell))
                        spellsVector.append(spell);

                }
                person->setSpells(spellsVector);
            }

        }
        reader.readNext();
    }
    file.close();
}

void XMLParser::writeXmlFile(Person *person, QString filename)
{
    QFile file(makeFullPathToFile(filename, person->objectType()));
    if( !file.open(QFile::ReadOnly | QFile::Text) )
    {
        QMessageBox::warning(nullptr,
                             tr("Ошибка файла"),
                             QString(tr("Не удалось открыть файл:\n")+file.fileName()),
                             QMessageBox::Ok);
        return;
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
        writer.writeAttribute("id", QString::number(person->getSpells().at(i)->ID()));
        QString filename = QString::number(person->getSpells().at(i)->ID()) + tr("_") + person->getSpells().at(i)->name();
        writeXmlFile(person->getSpells().at(i), filename);
    }
    writer.writeEndElement(); // spells

    writer.writeEndElement(); // person
    writer.writeEndDocument();
}

void XMLParser::readXmlFile(Spell *spell, QString filePath)
{
    QFile file(filePath);
    if( !file.exists() || !file.open(QFile::WriteOnly) )
    {
        QMessageBox::warning(nullptr,
                             tr("Ошибка файла"),
                             QString(tr("Не удалось открыть файл:\n")+file.fileName()),
                             QMessageBox::Ok);
        return;
    }

    QXmlStreamReader reader;
    reader.setDevice(&file);
    reader.readNext();
    while( !reader.atEnd() && !reader.hasError() )
    {
        if(reader.isStartElement())
        {
            if      (reader.name() == "main")
            {
                QXmlStreamAttributes main = reader.attributes();
                spell->setID(main.value("id").toInt());
                spell->setName(main.value("name").toString());
            }
            else if (reader.name() == "special")
            {
                QXmlStreamAttributes special = reader.attributes();
                spell->setDescription(special.value("description").toString());
                spell->setCooldawn(special.value("cooldawn").toInt());
            }
        }
        reader.readNext();
    }
    file.close();

}

void XMLParser::writeXmlFile(Spell *spell, QString filename)
{
    QFile file(makeFullPathToFile(filename, spell->objectType()));
    if( !file.exists() ||  !file.open(QFile::WriteOnly) )
    {
        QMessageBox::warning(nullptr,
                             tr("Ошибка файла"),
                             QString(tr("Не удалось открыть файл:\n")+file.fileName()),
                             QMessageBox::Ok);
        return;
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
    QString textID = tr("*") + QString::number(spell->ID()) + tr("*");
    QStringList listNameFilters;
    listNameFilters << textID;
    QFileInfoList fileInfoList = _savePath.entryInfoList(listNameFilters, QDir::Files, QDir::Name);
    if( fileInfoList.isEmpty() )
        return false;

    for(int i = 0; i < fileInfoList.count(); ++i)
    {
        Spell *newSpell = new Spell();
        readXmlFile(newSpell, fileInfoList.at(i).absoluteFilePath());
        if(newSpell->ID() == spell->ID())
        {
            spell = newSpell;
            return true;
        }
    }
    return false;
}

QString XMLParser::makeFullPathToFile(QString fn, OBJECT_XML_TYPE oxt)
{
    QString subdir;
    switch (oxt) {
    case OXT_PERSON:
        subdir = tr("person/");
        break;
    case OXT_SPELL:
        subdir = tr("spell/");
        break;
    case OXT_MAP:
        subdir = tr("map/");
        break;
    case OXT_BATTLE:
        subdir = tr("battle/");
        break;
    default:
        break;
    }
    QString path = _savePath.path() + subdir + fn;
    return path.contains(".xml", Qt::CaseInsensitive)?path:path+tr(".xml");
}

