#include "effect.h"

Effect::Effect(BaseObject *parent) : BaseObject(parent)
{

}

QPair<EFFECT_TYPE, quint8> Effect::resolve()
{

   quint8 resolveDuration = generate(_baseDuration.first, _baseDuration.second);

   return qMakePair(_type, resolveDuration);

}
