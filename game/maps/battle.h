#ifndef BATTLE_H
#define BATTLE_H

#include <QObject>
#include <QDateTime>


#include "baseobject.h"
#include "battlefield.h"
#include "common.h"



class Person;
class Monster;
class MosterFactory;

class Battle : public BaseObject
{
    Q_OBJECT
public:
    explicit Battle(BaseObject *parent = nullptr);


    void endOfTurn();

protected:
    BattleField* _battleField;

    /*brief
    Функция - генератор битвы
    in difficulty - входной параметр сложность
    in heroes - список героев участвующих в битве
    in|out monsters - список монстров получивший в результате генерации битвы
    in isBossBattle - признак говорит нужен ли босс в битве при создании
    in mapPatt - путь с картой для которой генерируется битва
    */
    void create(quint8 difficulty, QList<Person*> heroes, QList<Monster*> monsters, bool isBossBattle, QString mapPath);

    


private:
signals:

public slots:
};

#endif // BATTLE_H
