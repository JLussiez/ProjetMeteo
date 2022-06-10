/*#pragma once
#include <QObject>
#include <QDebug>
#include <QtWebSockets/qwebsocketserver.h>
#include <QtWebSockets/QtWebSockets>
#include "Meteo.h"

class Meteo : public QObject
{

	Q_OBJECT

public:
	
	server(QObject *parent = Q_NULLPTR);
	~server();

	QTcpSocket * socket;
	Meteo * meteo;

private:
	QWebSocketServer *webServer;
	QWebSocket * obj;

public slots:
	void onWebServerNewConnection();
	void onWebClientDisconnected();
	void SendJSONvalue();
};*/
