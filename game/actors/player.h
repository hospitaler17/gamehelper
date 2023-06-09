#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>

#include "game/actors/person.h"
#include "common.h"

Q_FORWARD_DECLARE_OBJC_CLASS(BaseObject);
Q_FORWARD_DECLARE_OBJC_CLASS(Person);

class Player : public Person
{
    Q_OBJECT
public:
    explicit Player(Person *parent = nullptr);

signals:

};

#endif // PLAYER_H
