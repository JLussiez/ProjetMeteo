<?php
/*
Etudiant 3 : Boucher Louis
Class pour gérer la base de données
*/
class Bdd{

    private $_ID;
    private $_BDD;

//Constructeur qui prend en paramètre la connexion à la base de données
    public function __construct($bdd){
        $this->_BDD = $bdd;
    }

    public function delete($ID){
        $req = "DELETE FROM `Capteur` WHERE `ID`='".$ID."'";
        $this->_BDD->query($req);
        unset($_POST);
    }

//Affiche les données de la table des Prévision Météo
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


//Affiche les données de la table des Capteurs 
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
                        <th>Pression (mbar)</th>
                        <th>Humidite (%)</th>
                        <th>Temperature (°C)</th>
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
                            <?= $tab["Pression"];?>
                        </td>
                        <td>
                            <?= $tab["Humidite"];?>
                        </td>
                        <td>
                            <?= $tab["Temperature"];?>
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

//Affiche les données de la base de la météo
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

//Supprime les données de la table Capteur pendant une période, avec comme paramètre deux date/heure 
    public function DateSupp($datetime1,$datetime2){
        $date1 = date('Y-m-d\ H:i ',strtotime($datetime1));
        $date2 = date('Y-m-d\ H:i ', strtotime($datetime2));
        $req2 = "DELETE FROM `Capteur` WHERE Date BETWEEN '".$date1."' AND '".$date2."'";
        $this->_BDD->exec($req2);
        unset($_POST);
        echo '<meta http-equiv="refresh" content="0">';
    }

//Supprime les données de la table Prévision Météo pendant une période, avec comme paramètre deux date/heure 
    public function DeletePrevision($datetime1,$datetime2){
        $date1 = date('Y-m-d\ H:i ',strtotime($datetime1));
        $date2 = date('Y-m-d\ H:i ', strtotime($datetime2));
        $req = "DELETE FROM `Prevision_Meteo` WHERE Date BETWEEN '".$date1."' AND '".$date2."'";
        $this->_BDD->exec($req);
        unset($_POST);
        echo '<meta http-equiv="refresh" content="0">';
    }

//Supprime les données de la table Météo pendant une période, avec comme paramètre deux date/heure     
    public function DeleteMeteo($datetime1,$datetime2){
        $date1 = date('Y-m-d\ H:i ',strtotime($datetime1));
        $date2 = date('Y-m-d\ H:i ', strtotime($datetime2));
        $req = "DELETE FROM `Meteo` WHERE Date BETWEEN '".$date1."' AND '".$date2."'";
        $this->_BDD->exec($req);
        unset($_POST);
        echo '<meta http-equiv="refresh" content="0">';
    }

//Vide la table Capteur 
    public function TruncateCapteur(){
        $req = "TRUNCATE TABLE `Capteur`";
        $this->_BDD->exec($req);
        unset($_POST);
        echo '<meta http-equiv="refresh" content="0">';
    }

//Vide la table Prévison Météo
    public function TruncatePrevision(){
        $req = "TRUNCATE TABLE `Prevision_Meteo`";
        $this->_BDD->exec($req);
        unset($_POST);
        echo '<meta http-equiv="refresh" content="0">';
    }

//Vide la table Météo    
    public function TruncateMeteo(){
        $req = "TRUNCATE TABLE `Meteo`";
        $this->_BDD->exec($req);
        unset($_POST);
        echo '<meta http-equiv="refresh" content="0">';
    }
}
?>