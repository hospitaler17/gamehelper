
#include "battlegenerator.h"

BattleGenerator::BattleGenerator()
{

}

Battle *BattleGenerator::generateBattle(MAP_ZONE zone, QList<Person *> heroList)
{

    Battle* newBattle = new Battle();

    newBattle->init(calcDifficulty(heroList),heroList, false, "");
    return newBattle;

}

quint8 BattleGenerator::calcDifficulty(QList<Person *> hList)
{
    quint8 res=0;
    foreach (Person* person, hList) {
        res += person->getLvl();
   }
    res = (res/hList.count())/6+1;
    return res;

}

