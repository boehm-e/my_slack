#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "socket.h"
int main(int argc, char *argv[])
{

    qmlRegisterType<MyTcpSocket>("Socket", 1, 0, "Socket");
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
