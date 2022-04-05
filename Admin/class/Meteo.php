<?php

class Meteo{

    private $_VitesseVent;
    private $_PositionVent;
    private $_Pression;
    private $_Humidite;
    private $_Temperature;
    private $_Luminosite;
    private $_Plviometre;
    private $_Pluie;
    private $_Jour_Nuit;
    private $_Prevision;
    private $_BDD;

    public function __construct($BDD){
        $this->_BDD = $BDD;
    }


    
}

?>