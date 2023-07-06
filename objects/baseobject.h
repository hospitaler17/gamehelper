#ifndef BASEOBJECT_H
#define BASEOBJECT_H

#include <QObject>
#include <QDateTime>
#include <QPixmap>

#include "common.h"

class BaseObject : public QObject
{
    Q_OBJECT
public:
    explicit BaseObject(QObject *parent = nullptr);

    quint64 ID() const;
    void setID(const quint64 &ID);

    QString name() const;
    void setName(const QString &name);

    OBJECT_XML_TYPE objectType() const;
    void setObjectType(const OBJECT_XML_TYPE &objectType);

    virtual bool readFromXML(QString path) = 0;

    QPixmap icon() const;
    void setIcon(const QPixmap &newIcon);

    QString pathToIcon() const;
    void setPathToIcon(const QString &newPathToIcon);

    quint64 regenerateID();

//    virtual void endOfTurn() = 0;
protected:
    quint64 _ID;
    QString _name;
    OBJECT_XML_TYPE _objectType;

    QPixmap _icon;
    QString _pathToIcon;


private:
    void init();
signals:

public slots:
};

#endif // BASEOBJECT_H
