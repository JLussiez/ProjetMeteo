#include "Meteo.h"
#include "Dask.h"
//#include "PrevisionMeteo.h"

Meteo::Meteo(QWidget *parent)
	: QMainWindow(parent),
	//ui(new Ui::MainWindow),
	socket(this)
{
	ui.setupUi(this);
	//Class Prévision météo
	previsionmeteo = new PrevisionMeteo;

	//Class pour chaque Capteur
	anemometre = new Anemometre;
	girouette = new Girouette;
	barometre = new Barometre;
	//
	hygrometre = new Hygrometre;
	thermometre = new Thermometre;
	solarimetre = new Solarimetre;
	//
	pluviometre = new Pluviometre;
	detecteurpluie = new DetecteurPluie;
	detecteurjournuit = new DetecteurJourNuit;	

	PressionHmoins1 = barometre->InstanciationPressionHmoins1();
	qDebug() << "PressionHmoins1 : " << PressionHmoins1;

	//PressionHmoins1 = 40;

	bdd = new BDD;

	ui.setupUi(this);
	socket.connectToHost(QHostAddress("127.0.0.1"), 4321);
	connect(&socket, SIGNAL(readyRead()), this, SLOT(onClientReadyRead()));
	ui.label_25->setNum(PressionHmoins1);

	Timer();

	webServer = new QWebSocketServer(QStringLiteral("WebServer"), QWebSocketServer::NonSecureMode, this);
	QObject::connect(webServer, &QWebSocketServer::newConnection, this, &Meteo::onWebServerNewConnection);

	webServer->listen(QHostAddress::AnyIPv4, 16050);
}

void Meteo::Timer()
{
	timer = new QTimer(this);

	//connect(timer, SIGNAL(timeout()), this, SLOT(PriseMeteo()));
	connect(timer, SIGNAL(timeout()), this, SLOT(slotSendJSONvalue()));

	//10 min
	timer->start(600000);

	// 5min
	//timer->start(300000);

	//1 min
	//timer->start(60000);
}

void Meteo::PriseMeteo()
{
	qDebug() << "Prise Météo";
	Prevision();
	ValeurActuelEtPrevision();
}

void Meteo::onWebServerNewConnection()
{
	qDebug() << "Un client WEB s'est connecte";

	this->unnomrandom = webServer->nextPendingConnection();

	ClientWeb.append(unnomrandom);

	QObject::connect(webServer, SIGNAL(disconnected()), this, SLOT(onSocketDeconnected()));
	qDebug() << "onWebServerNewConnection " << unnomrandom;
}

Meteo::~Meteo()
{
	qDebug() << "Destruction Serveur";
}

void Meteo::onWebClientDisconnected()
{
	QWebSocket* Client = qobject_cast<QWebSocket*>(sender());

	ClientWeb.removeOne(Client);
	qDebug() << "Deconexion Client";
}

void Meteo::SendJSONvalue()
{
	qDebug() << "Début SendJSONvalue()";
	Prevision();
	QString JSONvalue = ValeurActuelEtPrevision();

	qDebug() << JSONvalue;

	if (!unnomrandom)
	{
		unnomrandom->error();
	}
	qDebug() << unnomrandom;


	//Crash lorsqu on envoie avec timer
	//Le fait 2 fois d affilé
	unnomrandom->sendTextMessage(JSONvalue);
	qDebug() << "Fin SendJSONvalue()";
	// if (obj) {
		//obj->sendTextMessage(JSONvalue);
		//qDebug() << "Salut mon pote";
	// }
}

void Meteo::slotSendJSONvalue()
{
	qDebug() << "Début slotSendJSONvalue()";
	Prevision();
	QString JSONvalue = ValeurActuelEtPrevision();

	qDebug() << JSONvalue;

	//Crash lorsqu on envoie avec timer
	//Le fait 2 fois d affilé
	int i = 0;

	for (QWebSocket* Client : ClientWeb)
	{
		Client->sendTextMessage(JSONvalue);
	}

	qDebug() << "Fin slotSendJSONvalue()";

	//unnomrandom se supprime apres le premier envoie
}

void Meteo::TestTension()
{
	qDebug() << "Prevision()";
	Prevision();
	//Calcul Météo actuel + Prevision
	qDebug() << "ValeurActuelEtPrevision()";
	ValeurActuelEtPrevision();
}

void Meteo::Prevision()
{
	//Choper chaque valeur de chaque capteur et les convertir
	GererTension();

	float Vitesse_Vent = anemometre->getVitesseVent();
	QString Position_Vent = girouette->getCardinalite();
	float Pression = barometre->getPression();
	float Humidite = hygrometre->getHumidite();
	float Temperature = thermometre->getTemperature();
	float Luminosite = solarimetre->getLuminosite();
	float QuantitePluie = pluviometre->getQuantitePluie();
	float Pluie = detecteurpluie->getPluie();
	float JourNuit = detecteurjournuit->getJourNuit();

	//Envoie en base + temps
	qDebug() << "Envoie en base Capteur";
	qDebug() << Pluie << JourNuit << QuantitePluie;
	bdd->requete(/*Vitesse_Vent, Position_Vent,*/ Pression, Humidite, Temperature, /*Luminosite,*/ QuantitePluie, Pluie, JourNuit);
}

void Meteo::GererTension()
{
	qDebug() << "";
	qDebug() << "------------------------------------------------------------------------------------------";
	qDebug() << "";
	//getTension() de chaque capteur
	//Les methode en commentaire appartiennent aux capteurs non-fonctionel

	//anemometre->priseTension();
	//girouette->priseTension();
	qDebug() << "Barometre";
	barometre->priseTension();
	ui.label_11->setNum(barometre->getTension());
	//
	qDebug() << "hygrometre";
	hygrometre->priseTension();
	ui.label_12->setNum(hygrometre->getTension());
	qDebug() << "thermometre";
	thermometre->priseTension();
	ui.label_13->setNum(thermometre->getTension());
	//solarimetre->priseTension();
	//


	qDebug() << "detecteurjournuit";
	detecteurjournuit->priseDigital();
	ui.label_14->setNum(detecteurjournuit->getDigital());
	qDebug() << "detecteurpluie";
	detecteurpluie->priseDigital();
	ui.label_15->setNum(detecteurpluie->getDigital());
	qDebug() << "pluviometre";
	pluviometre->priseDigital();
	ui.label_16->setNum(pluviometre->getDigital());
	//Convertion des données :
	//anemometre->convertionTensionVitesseVent();
	//girouette->convertionTensionCardinalite();
	barometre->convertionTensionPression();
	ui.label_17->setNum(barometre->getPression());
	//

	hygrometre->convertionTensionHumidite();
	ui.label_18->setNum(hygrometre->getHumidite());

	thermometre->convertionTensionTemperature();
	ui.label_19->setNum(thermometre->getTemperature());
	//solarimetre->convertionTensionLuminosite();

	//

	pluviometre->convertionTensionQuantitePluie();
	ui.label_20->setNum(pluviometre->getQuantitePluie());

	detecteurpluie->convertionTensionPluie();
	ui.label_21->setText(detecteurpluie->getQPleut());

	detecteurjournuit->convertionTensionJourNuit();
	ui.label_22->setText(detecteurjournuit->getQJournuit());
}

QString Meteo::ValeurActuelEtPrevision()
{
	previsionmeteo->CatherineLaborde(*barometre, *thermometre, *detecteurpluie);

	QString Meteo = previsionmeteo->getTemps();
	bdd->requeteMeteo(Meteo);

	QString temps = previsionmeteo->getTemps();
	QString JsonMeteo;

	ui.label_23->setText(temps);

	//bdd->requeteMeteo(temps);

	//Attente 10 minutes
	j++;
	//Si ca fait 1h
	if (j == 6)
	{
		//Prévision météo
		float Pression = barometre->getPression();
		qDebug() << "Pression H -1 " << PressionHmoins1 << " // Pression " << Pression;

		//float
		previsionmeteo->Future(Pression, PressionHmoins1);
		//Reset compteur
		j = 0;

		QString prevision = previsionmeteo->getPrevision();
		QString duree = previsionmeteo->getDuree();
		ui.label_24->setText(prevision);

		float dPression = previsionmeteo->getDiffPression();
		QString diffpression = QString::number(dPression);
		ui.label_27->setText(diffpression);

		QString pQPressionHmoins1 = QString::number(PressionHmoins1);
		QString pQPression = QString::number(Pression);

		//Envoie en base + temps
		bdd->requetePrevision(prevision, duree, diffpression, pQPressionHmoins1, pQPression);	

		//Préparation envoie via TCP
		float Temp = thermometre->getTemperature();
		float Humid = hygrometre->getHumidite();
		float JourNuit = detecteurjournuit->getJourNuit();
		float Pluie = detecteurpluie->getPluie();
		float QuantitePluie = pluviometre->getQuantitePluie();

		QString QPression = QString::number(Pression);
		QString QTemp = QString::number(Temp);
		QString QHumid = QString::number(Humid);
		QString QJourNuit = QString::number(JourNuit);
		QString QPluie = QString::number(Pluie);
		QString QQuantitePluie = QString::number(QuantitePluie);

		//JsonMeteo = "{\"pression\":" + QPression + ",\"temperature\":" + QTemp + ",\"hydrometrie\":" + QHumid + ",\"journuit\":" + QJourNuit + ",\"pluie\":" + QPluie + ",\"quantitepluie\":" + QQuantitePluie + ",\"meteo\":" + temps + ",\"prevision\":" + prevision + ",\"duree\":" + duree + "}";
		JsonMeteo = "{\"pression\":" + QPression + ",\"temperature\":" + QTemp + ",\"hydrometrie\":" + QHumid + ",\"journuit\":" + QJourNuit + ",\"pluie\":" + QPluie + ",\"quantitepluie\":" + QQuantitePluie + "}";
		qDebug() << JsonMeteo;

		//Update de la pression à h-1
		PressionHmoins1 = Pression;
		ui.label_25->setNum(PressionHmoins1);
	}
	else
	{
		float Pression = barometre->getPression();
		float Temp = thermometre->getTemperature();
		float Humid = hygrometre->getHumidite();
		float JourNuit = detecteurjournuit->getJourNuit();
		float Pluie = detecteurpluie->getPluie();
		float QuantitePluie = pluviometre->getQuantitePluie();

		QString QPression = QString::number(Pression);
		QString QTemp = QString::number(Temp);
		QString QHumid = QString::number(Humid);
		QString QJourNuit = QString::number(JourNuit);
		QString QPluie = QString::number(Pluie);
		QString QQuantitePluie = QString::number(QuantitePluie);

		JsonMeteo = "{\"pression\":" + QPression + ",\"temperature\":" + QTemp + ",\"hydrometrie\":" + QHumid + ",\"journuit\":" + QJourNuit + ",\"pluie\":" + QPluie + ",\"quantitepluie\":" + QQuantitePluie + "}";

		qDebug() << "ValeurActuelEtPrevision " << JsonMeteo;
	}

	QByteArray inUtf8 = JsonMeteo.toUtf8();
	const char *JsonMeteoConvertit = inUtf8.constData();
	//Envoie via Serveur TCP
	socket.write(JsonMeteoConvertit);

	return JsonMeteo;
}

void Meteo::onClientReadyRead()
{
	//Besoin de savoir quand envoyer : Web doit envoyer message
	QByteArray str = socket.readAll();
	qDebug() << str;

	qDebug() << "Valeur envoyé : " << str;
	//refaire mesure puisque client le demande : 
	if (str == "NouvMesure")
	{
		//Faire une nouvelle mesure + l'envoyer au client
		//Obtenir les valeurs des capteurs

		//Pour nouvel valeurs / leur envoie en BDD
		Prevision();

		//Calcul Météo actuel + Prevision
		ValeurActuelEtPrevision();
	}
	else if (str == "10min")
	{
		//Faire une nouvelle mesure + l'envoyer au client
		//Obtenir les valeurs des capteurs

		//Pour nouvel valeurs / leur envoie en BDD
		Prevision();

		//Calcul Météo actuel + Prevision
		ValeurActuelEtPrevision();
	}
}


