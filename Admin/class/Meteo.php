<?php

class Meteo{
    private $_ID;
    private $_date;
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

    public function __construct($bdd){
        $this->_BDD = $bdd;
    }
    public function setParametre($id,$date,$VitesseVent,$PositionVent,$Pression,$Humidite,$Temperature,$Luminosite,$Pluviometre,$Pluie,$JourNuit){
        $this->_ID = $id;
        $this->_date = $date;
        $this->_VitesseVent = $VitesseVent;
        $this->_PositionVent = $PositionVent;
        $this->_Pression = $Pression;
        $this->_Humidite = $Humidite;
        $this->_Temperature = $Temperature;
        $this->_Luminosite = $Luminosite;
        $this->_Pluviometre = $Pluviometre;
        $this->_Pluie = $Pluie;
        $this->_Jour_Nuit = $JourNuit;

    }

    public function setParametrebyID($ID){
        $req = "SELECT * FROM `Capteur` WHERE `ID`='".$ID."'";
        $Result = $this->_BDD->query($req);
        while($tab = $Result->fetch()){
            $this->setParametre($tab["ID"], $tab["Date"], $tab["Vitesse_Vent"],$tab["Position_Vent"],
            $tab["Pression"],$tab["Humidite"],$tab["Temperature"],$tab["Solarimetre"],$tab["Pluviometre"],$tab["Pluie"],$tab["JourNuit"]);
        }
    }

    public function affiche(){
        
        $req = "SELECT * FROM `Capteur`";
        $Result = $this->_BDD->query($req);
        while($tab = $Result->fetch()){
            echo $tab["ID"];?>
            <p><?php echo $tab["Date"];?></p>
            <?php
            echo $tab["Vitesse_Vent"];
            echo $tab["Position_Vent"];
            echo $tab["Pression"];
            echo $tab["Humidite"];
            echo $tab["Temperature"];
            echo $tab["Solarimetre"];
            echo $tab["Pluviometre"];
            echo $tab["Pluie"];
            echo $tab["JourNuit"];
        }
    
}
}
?>