#include "spell.h"

Spell::Spell(QObject *parent) : QObject(parent)
{
    _ID = QDateTime::currentDateTime().toTime_t();
}

QString Spell::name() const
{
    return _name;
}

void Spell::setName(const QString &name)
{
    _name = name;
}

QString Spell::description() const
{
    return _description;
}

void Spell::setDescription(const QString &description)
{
    _description = description;
}

quint8 Spell::cooldawn() const
{
    return _cooldawn;
}

void Spell::setCooldawn(const quint8 &cooldawn)
{
    _cooldawn = cooldawn;
}

quint64 Spell::ID() const
{
    return _ID;
}

void Spell::setID(const quint64 &ID)
{
    _ID = ID;
}
