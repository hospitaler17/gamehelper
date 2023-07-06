#ifndef BATTLEFIELDCREATOR_H
#define BATTLEFIELDCREATOR_H
#include "battlefield.h"

class BattleFieldCreator
{
public:
    BattleFieldCreator();

    BattleField* createBattleField(QString mapPath);
};

#endif // BATTLEFIELDCREATOR_H
