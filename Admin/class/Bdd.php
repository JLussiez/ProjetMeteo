<?php

class Bdd{
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

    public function getID(){
        return $this->_ID;
    }

    public function delete($ID){
        $req = "DELETE FROM `Capteur` WHERE `ID`='".$ID."'";
        $this->_BDD->query($req);
        unset($_POST);
    }

    public function AffichePrevision(){
        $req3 = "SELECT * FROM `Prevision_Meteo` ORDER BY ID DESC";
        $Result3 = $this->_BDD->query($req3);
        ?>
        <div class="Prevision">
            <table class="tableau1">
                <thead>
                    <tr class="tr1">
                        <th>ID</th>
                        <th>Date / Heure</th>
                        <th>Prevision</th>
                        <th>Durée</th>
                    </tr>
                </thead>
                <tbody>  
                    <?php 
                        While($tab = $Result3->fetch()){
                    ?>
                            <tr class="tr2">
                                <td>
                                    <?= $tab['ID'] ?>
                                </td>
                                <td>
                                    <?= $tab["Date"];?>
                                </td>
                                <td>
                                    <?= $tab["Prevision"];?>
                                </td> 
                                <td>
                                    <?= $tab["Duree"];?>
                                </td>
                            </tr>          
                    <?php
                        }
                    ?>        
                </tbody>
            </table>
        </div>
    <?php
    }



    public function affiche(){
        
        $req = "SELECT * FROM `Capteur` ORDER BY ID DESC";
        $Result = $this->_BDD->query($req);
        ?>
        <div class="bar">
            <table class="tableau1">
                <thead>
                    <tr class="tr1">
                        <th>ID</th>
                        <th>Date / Heure</th>
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
                <tbody>     
            <?php 
                While($tab = $Result->fetch()){
            ?>
                    <tr class="tr2">
                        <td>
                            <?=$tab['ID'] ?>
                        </td>
                        <td>
                            <?= $tab["Date"];?>
                        </td>
                        <td>
                            <?= $tab["Vitesse_Vent"];?>
                        </td>
                        <td>
                            <?= $tab["Position_Vent"];?>
                        </td>
                        <td>
                            <?= $tab["Pression"];?>
                        </td>
                        <td>
                            <?= $tab["Humidite"];?>
                        </td>
                        <td>
                            <?= $tab["Temperature"];?>
                        </td>
                        <td>
                            <?= $tab["Solarimetre"];?>
                        </td>
                        <td>
                            <?= $tab["Pluviometre"];?>
                        </td>
                        <td>
                            <?= $tab["Pluie"];?>
                        </td>
                        <td>
                            <?= $tab["JourNuit"];?>
                        </td>
                <?php
                }
                ?>
                    </tr>
                </tbody>
            </table>
        </div>
    <?php
    }

    public function AfficheMeteo(){
        $req5 = "SELECT * FROM `Meteo` ORDER BY ID DESC";
        $Result = $this->_BDD->query($req5);
        ?>
        <div class="Prevision">
            <table class="tableau1">
                <thead>
                    <tr class="tr1">
                        <th>ID</th>
                        <th>Date / Heure</th>
                        <th>Temps</th>
                    </tr>
                </thead>
                <tbody>     
            <?php
             While($tab = $Result->fetch()){
                ?>
                        <tr class="tr2">
                            <td>
                                <?=$tab['ID'] ?>
                            </td>
                            <td>
                                <?= $tab["Date"];?>
                            </td>
                            <td>
                                <?= $tab["Temps"];?>
                            </td>
                    <?php
                    }
                    ?>
                        </tr>
                    </tbody>
                </table>
            </div>
        <?php 
    }

    public function DateSupp($datetime1,$datetime2){
        $date1 = date('Y-m-d\ H:i ',strtotime($datetime1));
        $date2 = date('Y-m-d\ H:i ', strtotime($datetime2));
        $req2 = "DELETE FROM `Capteur` WHERE Date BETWEEN '".$date1."' AND '".$date2."'";
        $this->_BDD->exec($req2);
        unset($_POST);
        echo '<meta http-equiv="refresh" content="0">';
    }

    public function DeletePrevision($datetime1,$datetime2){
        $date1 = date('Y-m-d\ H:i ',strtotime($datetime1));
        $date2 = date('Y-m-d\ H:i ', strtotime($datetime2));
        $req = "DELETE FROM `Prevision_Meteo` WHERE Date BETWEEN '".$date1."' AND '".$date2."'";
        $this->_BDD->exec($req);
        unset($_POST);
        echo '<meta http-equiv="refresh" content="0">';
    }

    public function DeleteMeteo($datetime1,$datetime2){
        $date1 = date('Y-m-d\ H:i ',strtotime($datetime1));
        $date2 = date('Y-m-d\ H:i ', strtotime($datetime2));
        $req = "DELETE FROM `Meteo` WHERE Date BETWEEN '".$date1."' AND '".$date2."'";
        $this->_BDD->exec($req);
        unset($_POST);
        echo '<meta http-equiv="refresh" content="0">';
    }

    public function TruncateCapteur(){
        $req = "TRUNCATE TABLE `Capteur`";
        $this->_BDD->exec($req);
        unset($_POST);
        echo '<meta http-equiv="refresh" content="0">';
    }
    
    public function TruncatePrevision(){
        $req = "TRUNCATE TABLE `Prevision_Meteo`";
        $this->_BDD->exec($req);
        unset($_POST);
        echo '<meta http-equiv="refresh" content="0">';
    }

    public function TruncateMeteo(){
        $req = "TRUNCATE TABLE `Meteo`";
        $this->_BDD->exec($req);
        unset($_POST);
        echo '<meta http-equiv="refresh" content="0">';
    }
}
?>