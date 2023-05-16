#include "battle.h"

Battle::Battle(QObject *parent) : QObject(parent)
{
    _ID = QDateTime::currentDateTime().toTime_t();

}

quint64 Battle::ID() const
{
    return _ID;
}

void Battle::setID(const quint64 &ID)
{
    _ID = ID;
}
