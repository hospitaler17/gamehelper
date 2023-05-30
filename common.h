#ifndef COMMON_H
#define COMMON_H

#include <QString>
#include <QObject>

enum OBJECT_XML_TYPE
{
    OXT_UNDEFINED = 0,
    OXT_PERSON = 1,
    OXT_BATTLE = 2,
    OXT_MAP = 3,
    OXT_SPELL = 4,
    OXT_MONSTER = 5 //!>  ToDO: Подумать нужно ли тут выделять
};

#define PT_COUNTER 4
enum PERSON_TYPE
{
    PT_UNDEFINED    = -1,
    PT_USUAL_ENEMY  = 0,//!>  ToDO: Подумать нужно ли тут выделять
    PT_BOSS_ENEMY   = 1,//!>  ToDO: Подумать нужно ли тут выделять
    PT_PLAYER       = 2,
    PT_NEUTRAL      = 3
};

#define PC_COUNTER 5
enum PERSON_CHARACTERISTICS
{
    PC_UNDEFINED    = -1,
    PC_STRENGTH     = 0,
    PC_AGILITY      = 1,
    PC_INTELLIGENCE = 2,
    PC_INITIATIVE   = 3,
    PC_CHARISMA     = 4
};
#define IT_COUNTER 6
enum ITEM_TYPE
{
    IT_QUESTITEM =0,
    IT_GOLD = 1,
    IT_ARMOR = 2,
    IT_WEAPON =3,
    IT_SPELLSCROLL =4,
    IT_POTION =5
};
#define ET_COUNTER 2
enum EFFECT_TYPE
{
    ET_NONE = 0,
    ET_COLD,
    ET_FIRE
    //TODO: Дописать классификтор эффектов
};


enum DIRECTIONSIDE
{
    DS_NONE =0,
    DS_NORTH,
    DS_SOUTH,
    DS_WEST,
    DS_EAST
};
enum SPELLPROFILE
{
    SP_TARGET =0,
    SP_SELF,
    SP_RECTANGLE,
    SP_CONE,
    SP_CIRCLE
};

enum STANDART_PROJECT_DIRS
{
    SPD_UNDEFINED = -1,

    SPD_ICON = 0,

    SPD_MAP,
    SPD_PERSON,
    SPD_SPELL,
    SPD_ITEM,
    SPD_EFFECT,

    SPD_BATTLE,
    SPD_GAME,

    SPD_PLAYER,
    SPD_BOSS,
    SPD_MONSTER,
    SPD_NPC
};

class Common : public QObject
{
    Q_OBJECT
public:
    Common() {}
    static QString getPersonTypeDescription(PERSON_TYPE pt)
    {
        if      (pt == PT_USUAL_ENEMY)
            return tr("Обычный противник");
        else if (pt == PT_PLAYER)
            return tr("Игровой персонаж");
        else if (pt == PT_BOSS_ENEMY)
            return tr("Босс");
        else if (pt == PT_NEUTRAL)
            return tr("Нейтральный персонаж");
        return tr("Неизвестно");
    }
    static QString getStandartProjectDirs(STANDART_PROJECT_DIRS spd)
    {
        if      (spd == SPD_ICON)
            return tr("./res/icon/");
        else if (spd == SPD_MAP)
            return tr("./res/map/");
        else if (spd == SPD_ITEM)
            return tr("./res/item/");
        else if (spd == SPD_EFFECT)
            return tr("./res/effects/");
        else if (spd == SPD_PERSON)
            return tr("./res/person/");
        else if (spd == SPD_SPELL)
            return tr("./res/spell/");

        //TODO: Дописать по необходимости стандартные пути

        return tr("./");
    }
    static QString getPersonCharacteristicDescription(PERSON_CHARACTERISTICS pc)
    {
        if      (pc == PC_STRENGTH)
            return tr("Cила");
        else if (pc == PC_AGILITY)
            return tr("Ловкость");
        else if (pc == PC_INTELLIGENCE)
            return tr("Интелект");
        else if (pc == PC_INITIATIVE)
            return tr("Инициатива");
        else if (pc == PC_CHARISMA)
            return tr("Харизма");

        return tr("Неизвестно");
    }
};




#endif // COMMON_H
