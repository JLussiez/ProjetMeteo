#pragma once

#include <QtWidgets/QMainWindow>
#include <qtcpsocket>
#include <qtcpserver>
#include "ui_TCP_Serveur.h"
#include <QDebug>
#include <qabstractsocket.h>
#include <QObject>
#include "MyThread.h"
#include <QByteArray.h> 
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

class TCP_Serveur : public QTcpServer
{
	Q_OBJECT

public:
	explicit TCP_Serveur(QObject *parent = 0);
	void StartServeur();
	QTcpSocket * ListClient[1000];
	int TailleTableau = 0;

signals:

public slots:
	void incomingConnection();
	void rreadyRead();

private:
	QTcpServer *serveur;
	MyThread *thread;
	QTcpSocket * socket;
	QTcpSocket * client;
};
