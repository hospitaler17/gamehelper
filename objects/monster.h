#ifndef MONSTER_H
#define MONSTER_H

#include "person.h"
#include "item.h"
class Monster : public Person
{
public:
    Monster();

protected:

    int difficultLvl;

    QList<Item> loot;

    virtual void generateLoot() =0;
};

#endif // MONSTER_H
