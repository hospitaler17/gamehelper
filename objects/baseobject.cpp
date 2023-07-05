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

quint64 BaseObject::regenerateID()
{
#if QT_VERSION < QT_VERSION_CHECK(5, 8, 0) // 0xMMNNPP (MM = major, NN = minor, PP = patch)
    _ID = QDateTime::currentDateTime().toTime_t();
#else
    _ID = QDateTime::currentDateTime().toSecsSinceEpoch();
#endif
    return _ID;
}

void BaseObject::init()
{
    regenerateID();

    _name = "{name}";
    _objectType = OXT_UNDEFINED;
    _pathToIcon = Common::getStandartProjectDirs(SPD_UNDEFINED);
}
