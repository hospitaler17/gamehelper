#ifndef EFFECT_H
#define EFFECT_H

#include <QObject>

#include "common.h"
#include "objects/baseobject.h"

class Effect : public BaseObject
{
    Q_OBJECT
public:
    explicit Effect(BaseObject *parent = nullptr);

signals:

public slots:
};

#endif // EFFECT_H
