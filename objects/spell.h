#ifndef SPELL_H
#define SPELL_H

#include <QObject>
#include <QDateTime>

#include "objects/baseobject.h"

class Spell : public BaseObject
{
    Q_OBJECT
public:
    explicit Spell(BaseObject *parent = 0);

    QString description() const;
    void setDescription(const QString &description);

    quint8 cooldawn() const;
    void setCooldawn(const quint8 &cooldawn);

private:

    QString _description;
    quint8  _cooldawn;
signals:

public slots:
};

#endif // SPELL_H
