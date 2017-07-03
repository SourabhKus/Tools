#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class QTextEdit;
class QLineEdit;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void recPacket(QString msg);
    void connectBtnHandler();
    void sentBtnHandler();

signals:
    void connectWithP(int port);
    void sentPacket(QString msg, int port);

private:
    int portID;
    QLineEdit *lineEdit;
    QLineEdit *portBox;
    QTextEdit *txtEditBox;
};

#endif // MAINWINDOW_H
