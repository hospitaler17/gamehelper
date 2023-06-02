#ifndef BASEOBJECT_H
#define BASEOBJECT_H

#include <QObject>
#include <QDateTime>

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

    virtual void readFromXML(QString path) = 0;
protected:
    quint64 _ID;
    QString _name;
    OBJECT_XML_TYPE _objectType;

private:
    void init();
signals:

public slots:
};

#endif // BASEOBJECT_H
