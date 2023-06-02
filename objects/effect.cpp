#include "effect.h"

Effect::Effect(BaseObject *parent) : BaseObject(parent)
{

}

QPair<EFFECT_TYPE, quint8> Effect::resolve()
{

   quint8 resolveDuration = generate(_baseDuration);

   return qMakePair(_type, resolveDuration);

}

EFFECT_TYPE Effect::getType()
{
    return _type;
}
bool Effect::readFromXML(QString path)
{
   Q_UNUSED(path);

   return false;
}
