#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ProjetMeteo.h"

class ProjetMeteo : public QMainWindow
{
    Q_OBJECT

public:
    ProjetMeteo(QWidget *parent = Q_NULLPTR);

private:
    Ui::ProjetMeteoClass ui;
};
