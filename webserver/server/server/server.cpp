#include "server.h"

server::server(QObject *parent) : QObject(parent) {
	webServer = new QWebSocketServer(QStringLiteral("WebServer"), QWebSocketServer::NonSecureMode, this);
	QObject::connect(webServer, &QWebSocketServer::newConnection, this, &server::onWebServerNewConnection);


	webServer->listen(QHostAddress::AnyIPv4, 16050);

	qDebug() << "test"; 

};

void server::onWebServerNewConnection()
{
	qDebug() << "Un client WEB s'est connecte";
}

server::~server()
{
	qDebug() << "Destruction Serveur";
}

void server::onWebClientDisconnected()
{
	qDebug() << "Deconexion Client";
}

