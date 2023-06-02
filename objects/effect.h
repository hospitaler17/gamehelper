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

    QPair<EFFECT_TYPE,quint8> resolve();

    EFFECT_TYPE getType();
    bool readFromXML(QString path);

    protected:
        EFFECT_TYPE _type;
        QPair<quint8, quint8> _baseDuration;


signals:

public slots:
};

#endif // EFFECT_H
