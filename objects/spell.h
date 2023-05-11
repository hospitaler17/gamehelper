#ifndef SPELL_H
#define SPELL_H

#include <QObject>

class Spell : public QObject
{
    Q_OBJECT
public:
    explicit Spell(QObject *parent = 0);

    QString name() const;
    void setName(const QString &name);

    QString description() const;
    void setDescription(const QString &description);

    quint8 cooldawn() const;
    void setCooldawn(const quint8 &cooldawn);

private:
    quint64 _ID;

    QString _name;
    QString _description;
    quint8  _cooldawn;
signals:

public slots:
};

#endif // SPELL_H
