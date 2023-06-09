#ifndef BOSS_H
#define BOSS_H

#include <QObject>

#include "game/actors/person.h"
#include "common.h"

Q_FORWARD_DECLARE_OBJC_CLASS(BaseObject);
Q_FORWARD_DECLARE_OBJC_CLASS(Person);

class Boss : public Person
{
    Q_OBJECT
public:
    explicit Boss(Person *parent = nullptr);

signals:

};

#endif // BOSS_H
