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

	bdd = new BDD;

	ui.setupUi(this);
	socket.connectToHost(QHostAddress("127.0.0.1"), 4321);
	connect(&socket, SIGNAL(readyRead()), this, SLOT(onClientReadyRead()));
	ui.label_25->setNum(PressionHmoins1);
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
	qDebug() << "pluviometre";
	pluviometre->priseTension();
	ui.label_14->setNum(pluviometre->getTension());
	qDebug() << "detecteurpluie";
	detecteurpluie->priseTension();
	ui.label_15->setNum(detecteurpluie->getTension());
	qDebug() << "detecteurjournuit";
	detecteurjournuit->priseTension();
	ui.label_16->setNum(detecteurjournuit->getTension());

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
	ui.label_21->setNum(detecteurpluie->getPluie());
	detecteurjournuit->convertionTensionJourNuit();
	ui.label_22->setNum(detecteurjournuit->getJourNuit());
}

void Meteo::ValeurActuelEtPrevision()
{
	previsionmeteo->CatherineLaborde(*barometre, *thermometre, *detecteurpluie);

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
		previsionmeteo->Future(Pression, PressionHmoins1);
		//Reset compteur
		j = 0;

		QString prevision = previsionmeteo->getPrevision();
		QString duree = previsionmeteo->getDuree();
		ui.label_24->setText(prevision);

		//Envoie en base + temps
		bdd->requetePrevision(prevision, duree);	

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

		JsonMeteo = "{\"pression\":" + QPression + ",\"temperature\":" + QTemp + ",\"hydrometrie\":" + QHumid + ",\"journuit\":" + QJourNuit + ",\"pluie\":" + QPluie + ",\"quantitepluie\":" + QQuantitePluie + ",\"meteo\":" + temps + ",\"prevision\":" + prevision + ",\"duree\":" + duree + "}";
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

		JsonMeteo = "{\"pression\":" + QPression + ",\"temperature\":" + QTemp + ",\"hydrometrie\":" + QHumid + ",\"journuit\":" + QJourNuit + ",\"pluie\":" + QPluie + ",\"quantitepluie\":" + QQuantitePluie + ",\"meteo\":" + temps + "}";

		qDebug() << JsonMeteo;
	}

	QByteArray inUtf8 = JsonMeteo.toUtf8();
	const char *JsonMeteoConvertit = inUtf8.constData();
	//Envoie via Serveur TCP
	socket.write(JsonMeteoConvertit);

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