#include "monsterfactory.h"

MonsterFactory::MonsterFactory()
{

}

Monster *MonsterFactory::create(MONSTER_TYPE type)
{

    Monster* resultM = new Monster();

    QString monsPath;
    switch (type) {
    case MT_GOBLIN:
        // monsPath =
        break;
    case MT_BAT:
         // monsPath =
        break;
    case MT_BOAR:
         // monsPath =
        break;
    case MT_CRAWLER:
         // monsPath =
        break;
    case MT_GOLEM:
         // monsPath =
        break;
    case MT_SKELETON:
         // monsPath =
        break;
    case MT_SLIME:
         // monsPath =
        break;
    case MT_WOLF:
         // monsPath =
        break;
    case BT_GOBLIN_KING:
        // monsPath =
        break;
    case BT_STONE_GUARD:
        // monsPath =
        break;
    case BT_GREAT_WYRM:
        // monsPath =
        break;
    case BT_IFRIT:
        // monsPath =
        break;
    case BT_NIGHTMARE_UNICORN:
        // monsPath =
        break;
    default:
        break;
    }

    resultM->readFromXML(monsPath);

    return resultM;
}
