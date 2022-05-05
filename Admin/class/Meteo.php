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
        ?>
        <table class="wsh">
            <thead>
                <tr class="tr1">
                    <th>ID</th>
                    <th>Date</th>
                    <th>Vitesse Vent</th>
                    <th>Position Vent</th>
                    <th>Pression</th>
                    <th>Humidite</th>
                    <th>Temperature</th>
                    <th>Solarimetre</th>
                    <th>Pluviometre</th>
                    <th>Pluie</th>
                    <th>JourNuit</th>
                </tr>
            </thead>
        </table>
        <table class="wsh2">
            <tbody>
        <?php 
        while($tab = $Result->fetch()){
            ?>
            <tr class="tr2">
            <td><?php echo $tab['ID'] ?></td>
            <td><?php echo $tab["Date"];?></td>
            <td><?php echo $tab["Vitesse_Vent"];?></td>
            <td><?php echo $tab["Position_Vent"];?></td>
            <td><?php echo $tab["Pression"];?></td>
            <td><?php echo $tab["Humidite"];?></td>
            <td><?php echo $tab["Temperature"];?></td>
            <td><?php echo $tab["Solarimetre"];?></td>
            <td><?php echo $tab["Pluviometre"];?></td>
            <td><?php echo $tab["Pluie"];?></td>
            <td><?php echo $tab["JourNuit"];?></td>
            <?php
        }
    ?>
    </tr>
    </tbody>
</div>
</table>
    <?php
}
}
?>