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
        $req3 = "SELECT * FROM `Prevision_Meteo`";
        $Result3 = $this->_BDD->query($req3);
        ?>
        <div class="Prevision">
            <table class="tableau1">
                <thead>
                    <tr class="tr1">
                        <th>ID</th>
                        <th>Date</th>
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
        
        $req = "SELECT * FROM `Capteur`";
        $Result = $this->_BDD->query($req);
        ?>
        <div class="bar">
            <table class="tableau1">
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
                        <!--<th></th>-->
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
                    <!--<form method="post" action="">
                        <td>
                            <input type="submit" name="supp" value="✘">
                        </td>
                    </form>-->
                <?php
                }
                ?>
                    </tr>
                </tbody>
            </table>
        </div>
    <?php
    }

    public function DateSupp($day){
        $req2 = "DELETE FROM `Capteur` WHERE Date < DATE_SUB(NOW(), INTERVAL ".$day." DAY)";
        $this->_BDD->exec($req2);
    }

    public function DatesuppPrevision($day){
        $req3 = "DELETE FROM `Prevision_Meteo` WHERE Date < DATE_SUB(NOW(), INTERVAL ".$day." DAY)";
        $this->_BDD->exec($req3);
    }

    public function SelectCapteur(){
        $req4 = "SELECT * FROM `Capteur`";
        $this->_BDD->exec($req4);
    }
}
?>