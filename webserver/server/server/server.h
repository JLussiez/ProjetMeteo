#pragma once
#include <QObject>
#include <QDebug>
#include <QtWebSockets/qwebsocketserver.h>
#include <QtWebSockets/QtWebSockets>

class server : public QObject
{

	Q_OBJECT

public:
	server(QObject *parent = Q_NULLPTR);
	~server();

	QTcpSocket * socket;

private:
	QWebSocketServer *webServer;
	QWebSocket * obj;

public slots:
	void onWebServerNewConnection();
	void onWebClientDisconnected();
};

