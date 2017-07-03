#include "MainWindow.h"
#include <QWidget>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    QVBoxLayout *vBox = new QVBoxLayout;

    portBox  = new QLineEdit;
    lineEdit = new QLineEdit;

    QPushButton *cBtn  = new QPushButton("Connect");
    QObject::connect(cBtn, SIGNAL(pressed()), SLOT(connectBtnHandler()));

    QPushButton *btn  = new QPushButton("Send");
    QObject::connect(btn, SIGNAL(pressed()), SLOT(sentBtnHandler()));

    QHBoxLayout *h1Box = new QHBoxLayout;
    h1Box->addWidget(portBox);
    h1Box->addWidget(cBtn);

    QHBoxLayout *h2Box = new QHBoxLayout;
    h2Box->addWidget(lineEdit);
    h2Box->addWidget(btn);

    txtEditBox = new QTextEdit;

    vBox->addLayout(h1Box);
    vBox->addLayout(h2Box);
    vBox->addWidget(txtEditBox);

    QWidget *w = new QWidget;
    w->setLayout(vBox);

    this->setCentralWidget(w);
}

MainWindow::~MainWindow()
{

}

void MainWindow::recPacket(QString msg)
{
    txtEditBox->append(msg);
}

void MainWindow::connectBtnHandler()
{
    emit connectWithP(portBox->text().toInt());
}

void MainWindow::sentBtnHandler()
{
    emit sentPacket(lineEdit->text(), portBox->text().toInt());
}
