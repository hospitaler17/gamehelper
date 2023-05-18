#include "spell.h"

Spell::Spell(BaseObject *parent) : BaseObject(parent)
{
    setObjectType(OXT_SPELL);
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
