#include "baseobject.h"

BaseObject::BaseObject(QObject *parent) : QObject(parent)
{
    init();
}

quint64 BaseObject::ID() const
{
    return _ID;
}

void BaseObject::setID(const quint64 &ID)
{
    _ID = ID;
}

QString BaseObject::name() const
{
    return _name;
}

void BaseObject::setName(const QString &name)
{
    _name = name;
}

OBJECT_XML_TYPE BaseObject::objectType() const
{
    return _objectType;
}

void BaseObject::setObjectType(const OBJECT_XML_TYPE &objectType)
{
    _objectType = objectType;
}

QPixmap BaseObject::icon() const
{
    return _icon;
}

void BaseObject::setIcon(const QPixmap &newIcon)
{
    _icon = newIcon;
}

QString BaseObject::pathToIcon() const
{
    return _pathToIcon;
}

void BaseObject::setPathToIcon(const QString &newPathToIcon)
{
    _pathToIcon = newPathToIcon;
}

void BaseObject::init()
{
    if(QT_VERSION < 0x060000) // 0xMMNNPP (MM = major, NN = minor, PP = patch)
        _ID = QDateTime::currentDateTime().toTime_t();
    _name = "{name}";
    _objectType = OXT_UNDEFINED;
    _pathToIcon = Common::getStandartProjectDirs(SPD_UNDEFINED);
}
