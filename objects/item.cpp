#include "item.h"

Item::Item(ITEM_TYPE it)
{
    type = it;
}

ITEM_TYPE Item::getType()
{
    return type;
}

void Item::setDropChance(double dc)
{
    dropChance = dc;
}

double Item::getDropChance()
{
    return dropChance;
}

void Item::readFromXML(QString path)
{

}
