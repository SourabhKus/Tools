/**
    MessageReceiver

    @author Sourabh Kushwaha
    @version 0.1 20/12/16
*/

#ifndef MESSAGERECEIVER_H
#define MESSAGERECEIVER_H

#include <QObject>

struct MessageReceiverData;

/**
 * @brief The MessageReceiver class : is trying to read data from portID using UdpSocket
 */
class MessageReceiver : public QObject
{
    Q_OBJECT

public:
    MessageReceiver(QObject* parent = 0);
    ~MessageReceiver();



signals:
    void msgReceived(QString msg);

private slots:
    /**
     * @brief processPendingDatagrams : A UdpSocket will call this slot on availability of data on portID, Then it passes data to FileWriter
     */
    void processPendingDatagrams();
    void writeData(QString msg, int port);
    void connectWithPort(int portID);

private:
    MessageReceiverData *d;
};

#endif // MESSAGERECEIVER_H
