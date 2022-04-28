#include "TCP_Serveur.h"
#include <qdebug.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <qregularexpression.h>
#include <QRegExp>
#include <QByteArray.h> 

TCP_Serveur::TCP_Serveur(QObject *parent): 
	QTcpServer(parent)
{
	socket = new QTcpSocket(this);
	QObject::connect(socket, SIGNAL(readyRead()), this, SLOT(onSocketReadyRead()));
	serveur = new QTcpServer(this);
	QObject::connect(serveur, SIGNAL(newConnection()), this, SLOT(incomingConnection()));

	StartServeur();

	//socket = new QTcpSocket(this);

}

//Detecter quand un nouveau client se connecte
void TCP_Serveur::incomingConnection()
{
	thread = new MyThread(/*socketDescriptor,*/ serveur);

	if (serveur)
	{
		QTcpSocket * client = serveur->nextPendingConnection();
		connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));


		QObject::connect(client, SIGNAL(readyRead()), this, SLOT(rreadyRead()));

		qDebug() << "client : " << client;

		qDebug() << /*socketDescriptor <<*/ "Connection ...";

		if (client)
		{
			//connect(client, SIGNAL(readyRead()), this, SLOT(readyRead()));

			thread->start();
			thread->run();
		}
		else
		{
			qDebug() << "client est pas défini";
		}
	}
	else
	{
		qDebug() << "serveur est pas défini";
	}

	

	
}

//Lancé le serveur
void TCP_Serveur::StartServeur()
{
	if (!serveur->listen(QHostAddress::Any, 4321))
	{
		qDebug() << "Problème : le serv n'as pas démarré";
	}
	else
	{
		qDebug() << "Serveur Lancé";
		//thread->run();

	}
}

void TCP_Serveur::rreadyRead()
{
	qDebug() << "TCP_Serveur::rreadyRead()";

	QTcpSocket * obj = qobject_cast<QTcpSocket*>(sender());
	QByteArray data = obj->read(obj->bytesAvailable());
	QString str(data);

	QByteArray Data = socket->readAll();
	qDebug() << "Data recu : " << str;

	//thread->readyRead();
}