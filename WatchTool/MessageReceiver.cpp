#include "MessageReceiver.h"

#include <QtNetwork>

struct MessageReceiverData
{
    MessageReceiverData() :
        udpSocket(0),
        applicationPID(QCoreApplication::applicationPid())
    {}

    ~MessageReceiverData()
    {
        if(udpSocket)
        {
            delete udpSocket;
            udpSocket = 0;
        }
    }

    QUdpSocket *udpSocket;
    int applicationPID;
};

MessageReceiver::MessageReceiver(QObject *parent)
    : QObject(parent)
{
}

MessageReceiver::~MessageReceiver()
{
    if(d)
    {
        delete d;
        d = 0;
    }
}

void MessageReceiver::connectWithPort(int portID)
{
    d = new MessageReceiverData;

    if(d)
    {
        d->udpSocket = new QUdpSocket;
        bool val = d->udpSocket->bind(QHostAddress::LocalHost, portID, QUdpSocket::ShareAddress);

        if(!val){
            msgReceived(QString("Can't Bind with %1").arg(portID));
            return;
        }
        else
            msgReceived(QString("Successfully Bind with %1").arg(portID));

        connect(d->udpSocket,
            SIGNAL(readyRead()),
            this,
            SLOT(processPendingDatagrams()));
    }
}

void MessageReceiver::processPendingDatagrams()
{
    if(!d->udpSocket)
        return;

    while (d->udpSocket->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(d->udpSocket->pendingDatagramSize());
        d->udpSocket->readDatagram(datagram.data(), datagram.size());
        QString entry = QString("%1\n").arg(datagram.data());
        emit msgReceived(entry);
    }
}

void MessageReceiver::writeData(QString msg, int port)
{
    if(!d->udpSocket)
        return;

    QString log = QString("%1#%2:DEBUG:%3").arg(d->applicationPID)
            .arg(QDateTime::currentDateTime().toUTC().toString())
            .arg(msg);
    d->udpSocket->writeDatagram(log.toUtf8().data(),
                                log.toUtf8().size(),
                                QHostAddress::LocalHost,
                                port);
}


