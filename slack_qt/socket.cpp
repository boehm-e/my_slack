#include "socket.h"

MyTcpSocket::MyTcpSocket(QObject *parent) :
    QObject(parent)
{
    socket = new QTcpSocket(this);
    doConnect();
}

void MyTcpSocket::doConnect()
{
    connect(socket, SIGNAL(connected()),this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()),this, SLOT(disconnected()));
    connect(socket, SIGNAL(bytesWritten(qint64)),this, SLOT(bytesWritten(qint64)));
    connect(socket, SIGNAL(readyRead()),this, SLOT(readyRead()));
    socket->connectToHost("127.0.0.1", 8080 );
    qDebug() << "connecting...";

    if(!socket->waitForConnected(5000))
    {
        qDebug() << "Error: " << socket->errorString();
    }

}

void MyTcpSocket::sendMessage(QString message) {
    const char* msg= message.toStdString().c_str();
    socket->write(msg);
}

void MyTcpSocket::connected()
{
    qDebug() << "connected...";
}

void MyTcpSocket::disconnected()
{
    qDebug() << "disconnected...";
}

void MyTcpSocket::bytesWritten(qint64 bytes)
{
    qDebug() << bytes << " bytes written...";
}

void MyTcpSocket::readyRead()
{
    qDebug() << "reading...";
    emit newMessage(socket->readAll());
}
