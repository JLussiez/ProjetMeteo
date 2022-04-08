#include "MyThread.h"

MyThread::MyThread(int ID, QObject *parent) :
	QThread(parent)
{
	this->socketDescriptor = ID;
}

void MyThread::run()
{
	qDebug() << socketDescriptor << "D�but thread";
	socket = new QTcpSocket();

	if (!socket->setSocketDescriptor(this->socketDescriptor))
	{
		emit error(socket->error());
		return;
	}

	connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()), Qt::DirectConnection);
	connect(socket, SIGNAL(disconnect()), this, SLOT(disconnect()), Qt::DirectConnection);

	qDebug() << socketDescriptor << "Un Client est connect�";

	exec();
}

void MyThread::disconnected()
{
	qDebug() << socketDescriptor << "D�connect�";
	socket->deleteLater();
	exit(0);
}

void MyThread::readyRead()
{
	QByteArray Data = socket->readAll();
	qDebug() << socketDescriptor << "Data recu : " << Data;

	socket->write(Data);
}