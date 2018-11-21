#ifndef UAVREGISTERY_H
#define UAVREGISTERY_H

#include <QObject>
#include <QVariant>
#include <QQmlListProperty>

class UAV;

class UAVRegistery : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<UAV> uavQList READ uavQList NOTIFY uavQListChanged)

public:
    UAVRegistery();

    QQmlListProperty<UAV> uavQList();
    Q_SIGNAL void uavQListChanged(QQmlListProperty<UAV> list);

    Q_INVOKABLE void addUAV(QString name);
    Q_INVOKABLE void removeUAV(QString name);
    Q_INVOKABLE void renameUAV(QString oldName, QString newName);
    Q_INVOKABLE void printUAVList();

private:
    QList<UAV*> uavList;
};

#endif // UAVREGISTERY_H
