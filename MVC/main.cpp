#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "UAV.h"
#include "UAVRegistery.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<UAV>("com.xyz.UAV", 1, 0, "UAV");

    QQmlApplicationEngine engine;
    UAVRegistery *uReg = new UAVRegistery;
    engine.rootContext()->setContextProperty("uavRegistery", uReg);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
