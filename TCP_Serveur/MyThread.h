#pragma once

#include <qthread>
#include <qtcpsocket.h>
#include <qdebug.h>
//#include <qthread.h>

class MyThread : public QThread
{
	Q_OBJECT

public:
	explicit MyThread(/*int iID, */QObject *parent = 0);
	void run();

signals:
	void error(QTcpSocket::SocketError socketerror);

public slots:
	void readyRead();
	void disconnected();

public slots:
private:
	QTcpSocket *socket;
	int socketDescriptor;
};

