#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Meteo.h"

class Meteo : public QMainWindow
{
    Q_OBJECT

public:
    Meteo(quint16 port);

private:
    Ui::MeteoClass ui;
};
