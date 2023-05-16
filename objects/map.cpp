#include "map.h"

Map::Map(QObject *parent) : QObject(parent)
{
    _ID = QDateTime::currentDateTime().toTime_t();
}

quint64 Map::ID() const
{
    return _ID;
}

void Map::setID(const quint64 &ID)
{
    _ID = ID;
}
