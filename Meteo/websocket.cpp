/*#include "websocket.h"

Meteo::Meteo(QObject *parent) : QObject(parent) {
	webServer = new QWebSocketServer(QStringLiteral("WebServer"), QWebSocketServer::NonSecureMode, this);
	QObject::connect(webServer, &QWebSocketServer::newConnection, this, &server::onWebServerNewConnection);

	webServer->listen(QHostAddress::AnyIPv4, 16050);

	qDebug() << "test";
};

void Meteo::onWebServerNewConnection()
{
	qDebug() << "Un client WEB s'est connecte";

	
	webServer->nextPendingConnection();
}

Meteo::~Meteo()
{
	qDebug() << "Destruction Serveur";
}

void Meteo::onWebClientDisconnected()
{
	qDebug() << "Deconexion Client";
}

void Meteo::SendJSONvalue() 
{
	QString JSONvalue = meteo->ValeurActuelEtPrevision();
	
	
	->sendTextMessage(JSONvalue);
	
	qDebug() << "magie noire en cours";
}*/