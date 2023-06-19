#ifndef MONSTERFACTORY_H
#define MONSTERFACTORY_H


#include "game/actors/monster.h"
#include "common.h"

class Monster;
class MonsterFactory
{
public:
    MonsterFactory();

    Monster* create(MONSTER_TYPE type);

protected:
  };


static MONSTER_TYPE generateMonsterType(quint8 lvl, MAP_ZONE zone)
{


}

static Monster* createRandomMonster(MonsterFactory* msFactory, quint8 lvl, MAP_ZONE zone)
{
    Monster* newMonster = new Monster();
    msFactory->create(generateMonsterType(lvl, zone));
    return newMonster;

}




#endif // MONSTERFACTORY_H
