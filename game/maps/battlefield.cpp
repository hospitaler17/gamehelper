#include "battlefield.h"

BattleField::BattleField(QString mapPath)
{
    _mapZone = MZ_PLAINS;

}

MAP_ZONE BattleField::getMapZone()
{
    return _mapZone;
}

void BattleField::LoadPicture(QString path)
{

}
