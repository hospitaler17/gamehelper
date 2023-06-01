#include "person.h"

Person::Person(BaseObject *parent)
    : BaseObject(parent)
{
    setObjectType(OXT_PERSON);
}

qint16 Person::damage() const
{
    return _damage;
}

void Person::setDamage(const qint16 &damage)
{
    _damage = damage;
}

qint16 Person::health() const
{
    return _health;
}

void Person::setHealth(const qint16 &health)
{
    _health = health;
}

qint16 Person::maxHealth() const
{
    return _maxHealth;
}

void Person::setMaxHealth(const qint16 &maxHealth)
{
    setHealth(_maxHealth);
    _maxHealth = maxHealth;
}

qint16 Person::initiative() const
{
    return _initiative;
}

void Person::setInitiative(const qint16 &initiative)
{
    _initiative = initiative;
}

PERSON_TYPE Person::type() const
{
    return _type;
}

void Person::setType(const PERSON_TYPE &type)
{
    _type = type;
}

QPixmap Person::icon() const
{
    return _icon;
}

void Person::setIcon(const QPixmap &icon)
{
    _icon = icon;
}

QString Person::personClass() const
{
    return _personClass;
}

void Person::setPersonClass(const QString &personClass)
{
    _personClass = personClass;
}

qint16 Person::intelligence() const
{
    return _intelligence;
}

void Person::setIntelligence(const qint16 &intelligence)
{
    _intelligence = intelligence;
}

qint16 Person::charisma() const
{
    return _charisma;
}

void Person::setCharisma(const qint16 &charisma)
{
    _charisma = charisma;
}

PERSON_CHARACTERISTICS Person::mainChars() const
{
    return _mainChars;
}

void Person::setMainChars(const PERSON_CHARACTERISTICS &mainChars)
{
    _mainChars = mainChars;
}

QVector<Spell*> Person::getSpells()
{
    return _spells;
}

void Person::setSpells(QVector<Spell*> value)
{
//    _spells = value;
}

QString Person::getPathToIcon() const
{
    return _pathToIcon;
}

void Person::setPathToIcon(const QString &pathToIcon)
{
    _pathToIcon = pathToIcon;
}

qint16 Person::strength() const
{
    return _strength;
}

void Person::setStrength(const qint16 &strength)
{
    _strength = strength;
}

qint16 Person::agility() const
{
    return _agility;
}

void Person::setAgility(const qint16 &agility)
{
    _agility = agility;
}

void Person::readFromXML(QString path)
{

}
