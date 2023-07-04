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


};

static MONSTER_TYPE generateMonsterType(quint8 lvl, MAP_ZONE zone)
{

    MONSTER_TYPE res;
    switch (zone) {
    case MZ_PLAINS:
       ((cube4()+lvl)>2)?res = MT_GOBLIN:res = MT_BOAR;

        break;
    case MZ_SWAMP:
     ((cube4()+lvl)>2)?res = MT_SLIME:res = MT_SKELETON;

        break;
    case MZ_FOREST:
       ((cube4()+lvl)>2)?res = MT_GOBLIN:res = MT_WOLF;

        break;
    case MZ_MOUNTAINS:
      ((cube4()+lvl)>2)?res = MT_BOAR:res = MT_GOLEM;

        break;
    case MZ_RUINS:
       ((cube4()+lvl)>2)?res = MT_SKELETON:res = MT_GOLEM;

        break;
    case MZ_CAVES:
       ((cube4()+lvl)>2)?res = MT_BAT:res = MT_CRAWLER;

        break;
    case MZ_CASTLE:
       (cube4()>2)?res = MT_SKELETON:res = MT_BAT;

        break;
    default:
        break;
    }
    return res;
}

static Monster* createRandomMonster(MonsterFactory* msFactory, quint8 lvl, MAP_ZONE zone)
{
    Monster* newMonster = new Monster();
    msFactory->create(generateMonsterType(lvl, zone));
    return newMonster;

}

#endif // MONSTERFACTORY_H
