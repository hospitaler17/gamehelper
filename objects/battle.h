#ifndef BATTLE_H
#define BATTLE_H

#include <QObject>
#include <QDateTime>


class Battle : public QObject
{
    Q_OBJECT
public:
    explicit Battle(QObject *parent = nullptr);

    quint64 ID() const;
    void setID(const quint64 &ID);

private:
    quint64 _ID;
signals:

public slots:
};

#endif // BATTLE_H
