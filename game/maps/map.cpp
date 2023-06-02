#include "map.h"

Map::Map(BaseObject *parent)
    : BaseObject(parent)
{
    setObjectType(OXT_MAP);
}

bool Map::readFromXML(QString path)
{
   Q_UNUSED(path);
    return false;
}

