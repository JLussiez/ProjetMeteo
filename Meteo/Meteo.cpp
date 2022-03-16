#include "Meteo.h"
#include "Dask.h"

Meteo::Meteo(quint16 port)
{
	card = Register_Card(PCI_9111DG, 0);

	this->webSocketServer = new QWebSocketServer(QStringLiteral("Server WebSocket"), QWebSocketServer::NonSecureMode);

	if (this->webSocketServer->listen(QHostAddress::AnyIPv4, port))
	{
		qDebug() << "Server WebSocket: Nouvelle connexion sur le port " << port << "\n";

		QObject::connect(webSocketServer, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
	}
	else
	{
		qDebug() << "Server WebSocket: Erreur d'ecoute sur le port " << port << "\n";
	}
}
