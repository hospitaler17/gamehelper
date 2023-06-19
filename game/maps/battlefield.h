#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

#include "map.h"
#include <QGraphicsView>



class BattleField : public Map
{
Q_OBJECT
public:
    BattleField(QString mapPath);

    void setFieldGeometry( quint8 x, quint8 y);
    void setCharacter(QString path, double x, double y);
    void moveCharacter();


    MAP_ZONE getMapZone();

protected:
//    QGraphicsView* _view;
//    QGraphicsScene* _scene;

//    QList<QGraphicsItem> _actors;

    void LoadPicture(QString path); // Унаследовано от Map

    MAP_ZONE _mapZone;




};

#endif // BATTLEFIELD_H
