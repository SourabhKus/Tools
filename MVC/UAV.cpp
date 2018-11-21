#include "UAV.h"
#include <QDebug>

UAV::UAV()
{

}

UAV::~UAV()
{
    qDebug()<<uavName<<"::"<<__FUNCTION__;
}

QString UAV::name()
{
    return uavName;
}

void UAV::setName(QString name)
{
    if(uavName != name)
    {
        uavName = name;
        emit nameChanged(uavName);
    }
}
