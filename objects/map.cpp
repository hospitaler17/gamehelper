#include "map.h"

Map::Map(BaseObject *parent)
    : BaseObject(parent)
{
    setObjectType(OXT_MAP);
}

bool Map::readFromXML(QString path)
{
    return false;
}

