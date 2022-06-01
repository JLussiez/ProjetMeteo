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

	bdd = new BDD;

	ui.setupUi(this);
	socket.connectToHost(QHostAddress("127.0.0.1"), 4321);
	connect(&socket, SIGNAL(readyRead()), this, SLOT(onClientReadyRead()));
	//server = new QTcpServer(this);
	//QObject::connect(server, SIGNAL(newConnection()), this, SLOT(onServerNewConnection()));
	//server->listen(QHostAddress::AnyIPv4, 4321);
	//
}

void Meteo::TestTension()
{
	qDebug() << "Prevision()";
	Prevision();

	//Calcul Météo actuel + Prevision
	qDebug() << "ValeurActuelEtPrevision()";
	ValeurActuelEtPrevision();

	//GererTension();

	/*
	barometre->addTensionTest();
	barometre->convertionTensionPression(); 

	float Pression = barometre->getPression();
	//Convertion float QString
	QString QPression = QString::number(Pression);

	ui.Pression->setText(QPression +" mBar");

	float Tension = barometre->getTension();
	QString QTension = QString::number(Tension);

	ui.Tension->setText(QTension +" V");

	//
	previsionmeteo->CatherineLaborde( *barometre, *thermometre, *detecteurpluie);
	*/
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
	bool Pluie = detecteurpluie->getPluie();
	bool JourNuit = detecteurjournuit->getJourNuit();

	//Envoie en base + temps
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

	//
	qDebug() << "hygrometre";
	hygrometre->priseTension();
	qDebug() << "thermometre";
	thermometre->priseTension();
	//solarimetre->priseTension();

	//
	qDebug() << "pluviometre";
	pluviometre->priseTension();
	qDebug() << "detecteurpluie";
	detecteurpluie->priseTension();
	qDebug() << "detecteurjournuit";
	detecteurjournuit->priseTension();

	//Convertion des données :
	//anemometre->convertionTensionVitesseVent();
	//girouette->convertionTensionCardinalite();
	barometre->convertionTensionPression();

	//

	hygrometre->convertionTensionHumidite();
	thermometre->convertionTensionTemperature();
	//solarimetre->convertionTensionLuminosite();

	//

	pluviometre->convertionTensionQuantitePluie();
	detecteurpluie->convertionTensionPluie();
	detecteurjournuit->convertionTensionJourNuit();
}

void Meteo::ValeurActuelEtPrevision()
{
	previsionmeteo->CatherineLaborde(*barometre, *thermometre, *detecteurpluie);

	QString temps = previsionmeteo->getTemps();
	qDebug() << "Temps : " << temps;

	//bdd->requeteMeteo(temps);

	//Attente 10 minutes
	j++;
	//Si ca fait 1h
	if (j == 6)
	{
		//Prévision météo
		previsionmeteo->Future();
		//Reset compteur
		j = 0;

		QString prevision = previsionmeteo->getPrevision();
		QString duree = previsionmeteo->getDuree();
		//Envoie en base + temps
		bdd->requetePrevision(prevision, duree);
	}
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