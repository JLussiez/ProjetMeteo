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
	barometre->addTensionTest();
	barometre->convertionTensionPression(); 

	float Pression = barometre->getPression();
	//Convertion float QString
	QString QPression = QString::number(Pression);

	ui.Pression->setText(QPression +" mBar");

	//float Tension = (*barometre).getTension();
	float Tension = barometre->getTension();
	QString QTension = QString::number(Tension);

	ui.Tension->setText(QTension +" V");

	previsionmeteo->CatherineLaborde( *barometre, *thermometre, *detecteurpluie);
}

void Meteo::Prevision()
{
	//Choper chaque valeur de chaque capteur
	GererTension();

	//Envoie en base + temps
	previsionmeteo->EnvoieDonnee(*anemometre, *girouette, *barometre, *hygrometre, *thermometre, *solarimetre, *pluviometre, *detecteurpluie, *detecteurjournuit);

}

void Meteo::GererTension()
{
	//getTension() de chaque capteur
	anemometre->getTension();
	girouette->getTension();
	barometre->getTension();
	//
	hygrometre->getTension();
	thermometre->getTension();
	solarimetre->getTension();
	//
	pluviometre->getTension();
	detecteurpluie->getTension();
	detecteurjournuit->getTension();

	//Convertion des données :
	anemometre->convertionTensionVitesseVent();
	girouette->convertionTensionCardinalite();
	barometre->convertionTensionPression();
	//
	hygrometre->convertionTensionHumidite();
	thermometre->convertionTensionTemperature();
	solarimetre->convertionTensionLuminosite();
	//
	pluviometre->convertionTensionQuantitePluie();
	detecteurpluie->convertionTensionPluie();
	detecteurjournuit->convertionTensionJourNuit();
}

void Meteo::ValeurActuelEtPrevision()
{
	Prevision();
	//Attente 10 minutes
	j++;
	//Si ca fait 1h
	if (j == 6)
	{
		//Prévision météo
		previsionmeteo->Future();
		//Reset compteur
		j = 0;
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
		GererTension();

		//Récuperer valeurs
		float VitesseVent = anemometre->getVitesseVent();
		QString Cardinalite = girouette->getCardinalite();
		float Pression = barometre->getPression();
		//
		float Temperature = thermometre->getTemperature();
		float Humidite = hygrometre->getHumidite();
		float Luminosite = solarimetre->getLuminosite();
		//
		float QuantitePluie = pluviometre->getQuantitePluie();
		float JourNuit = detecteurjournuit->getJourNuit();
		float Pluie = detecteurpluie->getPluie();

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
		if (socket.state() == QTcpSocket::ConnectedState)
		{
			socket.write("Demande nouvel valeur actuel");
		}
	}
	else if (str == "10min")
	{
		qDebug() << "Meteo 10 Minutes";

		ValeurActuelEtPrevision();

		//Récuperer valeurs
		float VitesseVent = anemometre->getVitesseVent();
		QString Cardinalite = girouette->getCardinalite();
		float Pression = barometre->getPression();
		//
		float Temperature = thermometre->getTemperature();
		float Humidite = hygrometre->getHumidite();
		float Luminosite = solarimetre->getLuminosite();
		//
		float QuantitePluie = pluviometre->getQuantitePluie();
		float JourNuit = detecteurjournuit->getJourNuit();
		float Pluie = detecteurpluie->getPluie();

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

		socket.write("Routine");
	}
}