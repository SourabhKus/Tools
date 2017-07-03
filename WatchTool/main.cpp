#include "MainWindow.h"
#include "MessageReceiver.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow *w = new MainWindow();
    MessageReceiver *mRec = new MessageReceiver();

    QObject::connect(w, SIGNAL(connectWithP(int)),
                     mRec, SLOT(connectWithPort(int)));

    QObject::connect(mRec, SIGNAL(msgReceived(QString)),
                     w, SLOT(recPacket(QString)));

    QObject::connect(w, SIGNAL(sentPacket(QString, int)),
                     mRec, SLOT(writeData(QString, int)));

    w->show();

    return a.exec();
}
