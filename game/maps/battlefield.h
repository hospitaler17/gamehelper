#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

#include "map.h"
#include <QGraphicsView>



class BattleField : public Map
{
Q_OBJECT
public:
    BattleField();

    void setFieldGeometry( quint8 x, quint8 y);
    void setCharacter(QString path, double x, double y);
    void moveCharacter();



protected:
//    QGraphicsView* _view;
//    QGraphicsScene* _scene;

//    QList<QGraphicsItem> _actors;

    void LoadPicture(QString path); // Унаследовано от Map



};

#endif // BATTLEFIELD_H
