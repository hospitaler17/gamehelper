#ifndef ITEM_H
#define ITEM_H
#include "baseobject.h"
#include "common.h"

class Item : public BaseObject
{
public:
    Item(ITEM_TYPE);

    ITEM_TYPE getType();
    void setDropChance(double);
    double getDropChance() const;
protected:
    ITEM_TYPE type;
    double dropChance;

};

#endif // ITEM_H
