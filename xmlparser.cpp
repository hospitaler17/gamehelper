#include "xmlparser.h"

XMLParser::XMLParser(QObject *parent) : QObject(parent)
{
}

void XMLParser::readXmlFile(Person* person, QString filename)
{
    QFile file(filename);
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
    while( !reader.atEnd() )
    {
        //TODO: read in Person
        reader.readNext();
    }
    file.close();
}

void XMLParser::writeXmlFile(Person *person, QString filename)
{
    QFile file(filename);
    if( !file.open(QFile::WriteOnly) )
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
    writer.writeAttribute("path_to_icon",   person->getPathToIcon());
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
    }
    writer.writeEndElement(); // spells

    writer.writeEndElement(); // person
    writer.writeEndDocument();
}

