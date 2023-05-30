#ifndef SPELL_H
#define SPELL_H

#include <QObject>
#include <QDateTime>

#include "objects/baseobject.h"
#include "common.h"

class Spell : public BaseObject
{
    Q_OBJECT
public:

    enum SPELL_TYPE
    {
        ST_DAMAGE = 0,
        ST_HEAL,
        ST_BUFF,
        ST_DEBUFF,
     };

    explicit Spell(BaseObject *parent = 0);



    QString description() const;
    void setDescription(const QString &description);

    quint8 cooldawn() const;
    void setCooldawn(const quint8 &cooldawn);

protected:

    QString _description;   //!> Описание скила
    quint8  _cooldawn;      //!> Откат скила, количество ходов до доступности
    EFFECT_TYPE _effectType = ET_NONE; //!> Эффект, накладываемый заклинанием, определяется для ST_BUFF & ST_DEBUFF
    quint8 _value =0; //!> Значение урона или лечение наносимое скилом
    quint8 _range =1; //!> Дальность использования навыка
    quint8 _castRadius=1;   //!> Дальность распространения навыка, относително точки применения

    QHash<QPair<quint8, quint8>,quint8> _area; //!> Область применения скила
    DIRECTIONSIDE _direction; //!> Направления применения навыка






signals:

public slots:
};

#endif // SPELL_H
