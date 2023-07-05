#ifndef SPELL_H
#define SPELL_H

#include <QObject>
#include <QDateTime>

#include "xmlparser.h"
#include "objects/baseobject.h"
#include "common.h"
#include "effect.h"


class Spell : public BaseObject
{
    Q_OBJECT
public:

    typedef QPair<quint8, quint8> SkillValue; //!> Любой навык имеет  минимальный (first) и макс урон/лечение (second)



    struct CastResult
    {
        /* для аое механики TODO: QList<TargetId, */ quint8/*>*/ value;

        /* для аое механики TODO: QList<TargetId, */QPair<EFFECT_TYPE, quint8> /*>*/ effectResolve;   //!> quint8 - число ходов

    };

    enum SPELLTYPE

    {
        ST_DAMAGE = 0,
        ST_HEAL,

    };


    explicit Spell(BaseObject *parent = 0);
    explicit Spell(const Spell &spell, BaseObject *parent = 0);



    QString description() const;
    void setDescription(const QString &description);

    quint8 cooldawn() const;
    void setCooldawn(const quint8 &cooldawn);


    bool isAvailiable();
    CastResult cast(/*для аое механики TODO: QList<Target>*/);

    bool readFromXML(QString path);
protected:



    QString _description;   //!> Описание скила
    quint8  _cooldawn;      //!> Базовый откат скила, количество ходов до доступности
    quint8  _currentCooldawn;      //!> Текущий откат скила, количество ходов до доступности
    Effect* _effect = NULL; //!> Эффект, накладываемый заклинание

    SkillValue _value; //!> Значение урона или лечение наносимое скилом
    quint8 _range =1; //!> Дальность использования навыка
    quint8 _castRadius=1;   //!> Дальность распространения навыка, относително точки применения
    quint8 _currentSkillLvl =1; //!> Текущий уровень прокачки навыка

    QHash <quint8, SkillValue> _skillValueDependence; //!>Порядок изменения базового значения урона/лечения(SkillValue) в зависимости от уровня навыка (quint8)


    QHash<QPair<quint8, quint8>,quint8> _area; //!> Область применения скила  QPair это точка
    DIRECTIONSIDE _direction; //!> Направления применения навыка



signals:

public slots:
};

#endif // SPELL_H
