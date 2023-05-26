#ifndef BATTLE_H
#define BATTLE_H

#include <QObject>
#include <QDateTime>

#include "baseobject.h"


class Battle : public BaseObject
{
    Q_OBJECT
public:
    explicit Battle(BaseObject *parent = nullptr);

private:
signals:

public slots:
};

#endif // BATTLE_H
