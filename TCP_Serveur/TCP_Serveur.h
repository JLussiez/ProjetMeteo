#pragma once

#include <QtWidgets/QMainWindow>
#include <qtcpsocket>
#include <qtcpserver>
#include "ui_TCP_Serveur.h"
#include <QDebug>
#include <qabstractsocket.h>
#include <QObject>
#include "MyThread.h"

class TCP_Serveur : public QTcpServer
{
	Q_OBJECT

public:
	explicit TCP_Serveur(QObject *parent = 0);
	void StartServeur();

signals:

public slots:
	void incomingConnection(int socketDescriptior);

private:
	QTcpServer *serveur;
};
