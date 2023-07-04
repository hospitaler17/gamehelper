#ifndef BATTLEGENERATOR_H
#define BATTLEGENERATOR_H
#include "battle.h"
#include "person.h"


class BattleGenerator
{
public:
    BattleGenerator();

    Battle* generateBattle(MAP_ZONE zone, QList<Person*> /* лист героев*/ heroList);

    protected:

    quint8 calcDifficulty(QList<Person*>);
};

#endif // BATTLEGENERATOR_H
