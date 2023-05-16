#ifndef PERSON_H
#define PERSON_H

#include <QObject>
#include <QPicture>
#include <QPixmap>
#include <QVector>
#include <QDateTime>


#include "objects/spell.h"
#include "common.h"




class Person : public QObject
{
    Q_OBJECT
public:
    explicit Person(QObject *parent = nullptr);

    qint16 damage() const;
    void setDamage(const qint16 &damage);

    qint16 health() const;
    void setHealth(const qint16 &health);

    qint16 maxHealth() const;
    void setMaxHealth(const qint16 &maxHealth);

    qint16 initiative() const;
    void setInitiative(const qint16 &initiative);

    PERSON_TYPE type() const;
    void setType(const PERSON_TYPE &type);

    QPixmap icon() const;
    void setIcon(const QPixmap &icon);

    quint64 ID() const;
    void setID(int ID);

    QString name() const;
    void setName(const QString &name);

    QString personClass() const;
    void setPersonClass(const QString &personClass);

    qint16 intelligence() const;
    void setIntelligence(const qint16 &intelligence);

    qint16 charisma() const;
    void setCharisma(const qint16 &charisma);

    PERSON_CHARACTERISTICS mainChars() const;
    void setMainChars(const PERSON_CHARACTERISTICS &mainChars);

    QVector<Spell *> getSpells() ;
    void setSpells(QVector<Spell *> value);

    QString getPathToIcon() const;
    void setPathToIcon(const QString &pathToIcon);

    qint16 strength() const;
    void setStrength(const qint16 &strength);

    qint16 agility() const;
    void setAgility(const qint16 &agility);

private:
    quint64 _ID = 0;

    // COMMON
    QString _name;
    QString _personClass;
    QPixmap _icon;
    QString _pathToIcon;
    PERSON_TYPE _type = PT_UNDEFINED;
    // ***

    // CURRENT
    qint16  _damage     = 0;
    qint16  _health     = 0;
    qint16  _maxHealth  = 0;
    // ***

    // CHARACTERISTICS
    qint16  _initiative     = 0;
    qint16  _strength       = 0;
    qint16  _agility        = 0;
    qint16  _intelligence   = 0;
    qint16  _charisma       = 0;
    PERSON_CHARACTERISTICS  _mainChars  = PC_UNDEFINED;
    // ***

    QVector <Spell *> _spells;

signals:

public slots:
};

#endif // PERSON_H
