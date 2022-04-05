#include "TCP_Serveur.h"
#include <qdebug.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <qregularexpression.h>
#include <QRegExp>
#include <QByteArray.h> 

TCP_Serveur::TCP_Serveur(QWidget *parent)
	: QMainWindow(parent)
{
	//ui.setupUi(this);
	socket = new QTcpSocket(this);
	QObject::connect(socket, SIGNAL(readyRead()), this, SLOT(onSocketReadyRead()));
	server = new QTcpServer(this);
	QObject::connect(server, SIGNAL(newConnection()), this, SLOT(onServerNewConnection()));
	server->listen(QHostAddress::AnyIPv4, 4321);
	//
	meteo = new Meteo;

	socket->connectToHost("192.168.64.107", 4321);
}

void TCP_Serveur::onServerNewConnection()
{
	//ui.connectionStatusLabel->setText("Un client c'est connecté");
	client = server->nextPendingConnection();
	QObject::connect(client, SIGNAL(readyRead()), this, SLOT(onClientReadyRead()));
	QObject::connect(client, SIGNAL(disconnect()), this, SLOT(onClientDisconnected()));

	//Sauvegarde Client dans tableau pour update à tout le monde
	TCP_Serveur::ListClient[TailleTableau] = client;
	TCP_Serveur::TailleTableau++;
}

void TCP_Serveur::onClientDisconnected()
{
	QTcpSocket * obj = qobject_cast<QTcpSocket*>(sender());
	QObject::disconnect(obj, SIGNAL(readyRead()), this, SLOT(onClientReadyRead()));
	QObject::disconnect(obj, SIGNAL(readyRead()), this, SLOT(onClientDisconnected()));
	obj->deleteLater();
}

void TCP_Serveur::onClientReadyRead()
{
	//Besoin de savoir quand envoyer : Web doit envoyer message
	QTcpSocket * obj = qobject_cast<QTcpSocket*>(sender());
	QByteArray data = obj->read(obj->bytesAvailable());
	QString str(data);

	//refaire mesure puisque client le demande : 
	if (str == "NouvMesure")
	{
		//Faire une nouvelle mesure + l'envoyer au client
		//Obtenir les valeurs des capteurs
		meteo->GererTension();

		//Récuperer valeurs
		float VitesseVent = meteo->anemometre->getVitesseVent();
		QString Cardinalite = meteo->girouette->getCardinalite();
		float Pression = meteo->barometre->getPression();
		//
		float Temperature = meteo->thermometre->getTemperature();
		float Humidite = meteo->hygrometre->getHumidite();
		float Luminosite = meteo->solarimetre->getLuminosite();
		//
		float QuantitePluie = meteo->pluviometre->getQuantitePluie();
		float JourNuit = meteo->detecteurjournuit->getJourNuit();
		float Pluie = meteo->detecteurpluie->getPluie();

		//Convertion float en QString
		QString QS_VitesseVent = QString::number(VitesseVent);
		//Cardinalité en QString de base
		QString QS_Pression = QString::number(Pression);
		//
		QString QS_Temperature = QString::number(Temperature);
		QString QS_Humidite = QString::number(Humidite);
		QString QS_Luminosite = QString::number(Luminosite);
		//
		QString QS_QuantitePluie = QString::number(QuantitePluie);
		QString QS_JourNuit = QString::number(JourNuit);
		QString QS_Pluie = QString::number(Pluie);

		//Convertion QString en QByteArray pour envoie via Serveur TCP
		QByteArray MessageEncode_VitesseVent = QS_VitesseVent.toUtf8();
		QByteArray MessageEncode_Cardinalite = Cardinalite.toUtf8();
		QByteArray MessageEncode_Pression = QS_Luminosite.toUtf8();
		//
		QByteArray MessageEncode_Temperature = QS_Temperature.toUtf8();
		QByteArray MessageEncode_Humidite = QS_Humidite.toUtf8();
		QByteArray MessageEncode_Luminosite = QS_Luminosite.toUtf8();
		//
		QByteArray MessageEncode_QuantitePluie = QS_QuantitePluie.toUtf8();
		QByteArray MessageEncode_JourNuit = QS_JourNuit.toUtf8();
		QByteArray MessageEncode_Pluie = QS_Pluie.toUtf8();


		//ENVOYER A 1 Utilisateur
		//Comment on ecrit le message ?
		if (socket->state() == QTcpSocket::ConnectedState)
		{
			socket->write("Demande nouvel valeur actuel");
		}
		

	}
	else
	{
		
	}
}