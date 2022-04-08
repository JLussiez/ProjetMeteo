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
	
}

void TCP_Serveur::incomingConnection(int socketDescriptor)
{
	qDebug() << socketDescriptor << "Connection ...";
	MyThread *thread = new MyThread(socketDescriptor, this);
	connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
	thread->start();
}

void TCP_Serveur::StartServeur()
{
	if (!this->listen(QHostAddress::Any, 4321))
	{
		qDebug() << "Problème : le serv n'as pas démarré";
	}
	else
	{
		qDebug() << "Serveur Lancé";
	}
}
