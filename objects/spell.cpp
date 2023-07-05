#include "spell.h"

Spell::Spell(BaseObject *parent) : BaseObject(parent)
{
    setObjectType(OXT_SPELL);
}

Spell::Spell(const Spell &spell, BaseObject *parent) : BaseObject(parent)
{
    setObjectType(OXT_SPELL);

    this->setID(spell.ID());
    this->setName(spell.name());
    this->setIcon(spell.icon());
    this->setPathToIcon(spell.pathToIcon());
    this->setCooldawn(spell.cooldawn());
    this->setDescription(spell.description());
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

bool Spell::isAvailiable()
{
    return _currentCooldawn>0?false:true;
}

Spell::CastResult Spell::cast()
{
    CastResult cr;
    cr.value = generate(_skillValueDependence.value(_currentSkillLvl));
    cr.effectResolve = _effect->resolve();
    return cr;
}

bool Spell::readFromXML(QString path)
{
    XMLParser * parser = new XMLParser();
    bool res = parser->readXmlFile(this, path);
    return res;
}
