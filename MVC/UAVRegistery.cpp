#include "UAVRegistery.h"
#include "UAV.h"

#include <QVariant>
#include <QDebug>

UAVRegistery::UAVRegistery()
{
    UAV *u1 = new UAV;
    u1->setName("UAV-1");

    uavList.append(u1);
}

QQmlListProperty<UAV> UAVRegistery::uavQList()
{
    return QQmlListProperty<UAV>(this, uavList);
}

void UAVRegistery::addUAV(QString name)
{
    UAV *u = new UAV;
    u->setName(name);
    uavList.append(u);

    emit uavQListChanged(QQmlListProperty<UAV>(this, uavList));
}

void UAVRegistery::removeUAV(QString name)
{
    for(int i=0; i < uavList.length(); i++)
    {
        if(uavList.at(i)->name() == name)
        {
            uavList.removeAt(i);
            emit uavQListChanged(QQmlListProperty<UAV>(this, uavList));
        }
    }
}

void UAVRegistery::renameUAV(QString oldName, QString newName)
{
    for(int i=0; i < uavList.length(); i++)
    {
        if(uavList.at(i)->name() == oldName)
        {
            uavList.at(i)->setName(newName);
        }
    }
}

void UAVRegistery::printUAVList()
{
    for(int i=0; i < uavList.length(); i++)
        qDebug()<<i<<" = "<<uavList.at(i)->name();
}
