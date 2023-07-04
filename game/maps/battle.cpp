#include "battle.h"
#include "monsterfactory.h"
Battle::Battle(BaseObject *parent) :
    BaseObject(parent)
{
    setObjectType(OXT_BATTLE);




}

void Battle::create(quint8 difficulty, QList<Person*>, QList<Monster*> monsters, bool isBossBattle, QString mapPath)
{
    _battleField = new BattleField(mapPath);


    if (isBossBattle){}
    else
    {
        int numberOfMonsters;
        int monsterLvl;

        switch (difficulty) {
        case 1:                 //!> первый уровень сложности от 1 до 4 монстров 1 лвла
        {
            numberOfMonsters = cube4();
            monsterLvl = 1;
            break;
        }
        case 2:                  //!> второй уровень сложности от 1 до 6 монстров 1 лвла
        {
            numberOfMonsters = cube6();
            monsterLvl = 1;
            break;
        }
        case 3:                  //!> второй уровень сложности от 1 до 4 монстров 2 лвла
        {

            numberOfMonsters = cube4();
            monsterLvl = 2;

            break;
        }
        case 4:                  //!> второй уровень сложности от 1 до 6 монстров 2 лвла
        {

            numberOfMonsters = cube4();
            monsterLvl = 2;

            break;
        }

        default:
            break;
        }

        MonsterFactory* msFactory = new MonsterFactory();
        for (int i =0; i<numberOfMonsters;i++)
        {
           monsters.append(createRandomMonster(msFactory, monsterLvl, _battleField->getMapZone()));
        }

    }


}


