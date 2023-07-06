#ifndef MONSTER_H
#define MONSTER_H

#include "QObject"
#include "person.h"
#include "item.h"


class Monster : public Person
{
    Q_OBJECT
public:
    explicit Monster();

protected:

    int difficultLvl;

    QList<Item> loot;

//    virtual void generateLoot() =0;
};

#endif // MONSTER_H
