#ifndef BATTLE_H
#define BATTLE_H

#include <QObject>
#include <QDateTime>

#include "baseobject.h"
#include "battlefield.h"


class Battle : public BaseObject
{
    Q_OBJECT
public:
    explicit Battle(BaseObject *parent = nullptr);


protected:
    BattleField* _battleField;

private:
signals:

public slots:
};

#endif // BATTLE_H
