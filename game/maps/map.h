#ifndef MAP_H
#define MAP_H

#include <QObject>
#include <QDateTime>

#include "objects/baseobject.h"

class Map : public BaseObject
{
    Q_OBJECT
public:
    explicit Map(BaseObject *parent = 0);

    bool readFromXML(QString path);

private:

//    QRect mapSquere;

signals:

public slots:
};

#endif // MAP_H
