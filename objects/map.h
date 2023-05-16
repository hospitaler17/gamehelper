#ifndef MAP_H
#define MAP_H

#include <QObject>
#include <QDateTime>

class Map : public QObject
{
    Q_OBJECT
public:
    explicit Map(QObject *parent = 0);

    quint64 ID() const;
    void setID(const quint64 &ID);

private:
    quint64 _ID;
//    QRect mapSquere;

signals:

public slots:
};

#endif // MAP_H
