#ifndef BATTLE_H
#define BATTLE_H

#include <QObject>

class Battle : public QObject
{
    Q_OBJECT
public:
    explicit Battle(QObject *parent = nullptr);

signals:

public slots:
};

#endif // BATTLE_H