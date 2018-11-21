#ifndef UAV_H
#define UAV_H

#include <QObject>

class UAV : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)

public:
    UAV();
    ~UAV();
    QString name();
    Q_SLOT void setName(QString name);
    Q_SIGNAL void nameChanged(QString name);

private:
    QString uavName;
};

#endif // UAV_H
