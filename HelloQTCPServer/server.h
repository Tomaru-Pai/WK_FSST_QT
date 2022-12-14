#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QtDebug>

const int PORT = 5000;

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);
    void start();

signals:

public slots:
    void myNewConnection();
    void myClientDisconnect();
    void myServerRead();

private:
    QTcpServer *m_server;
    QTcpSocket *m_socket;
};

#endif // SERVER_H
