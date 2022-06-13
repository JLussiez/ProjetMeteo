<?php
/*
Etudiant 3 : Boucher Louis
Class pour s'identifier sur la gestion Admin
*/

 class Admin{

    private $_ID;
    private $_Pseudo;
    private $_BDD;

//Constructeur qui prend en paramètre la connexion à la base de données
    public function __construct($bdd){
        $this->_BDD = $bdd;
    }

    public function setAdmin($ID,$Pseudo,$Mdp){
        $this->_ID = $ID;
        $this->_Pseudo = $Pseudo;
        $this->_Mdp = $Mdp;
    }
    
    public function setAdminbyID($ID){
        $req = "SELECT * FROM `Admin` WHERE `ID`='".$ID."'";
        $Result = $this->_BDD->query($req);
        while($tab = $Result->fetch()){
            $this->setAdmin($tab["ID"], $tab["Pseudo"], $tab["Password"]);
        }
    }

//Affiche le formulaire de connexion et envoi une requete SQL quand les données du formulaire sont envoyeés 
//pour comparer l'utilisateur stocker en base de données
//La session utilisateur est créer si l'utilisateur se connecte
    public function formUser(){

        $afficheForm = true;
        $error = false;
        $_SESSION["Connected"] = false;
        if(isset($_POST["pseudo"]) && isset($_POST["password"])){
            $req = "SELECT * FROM `Admin` WHERE `Pseudo`='".$_POST['pseudo']."' AND `Password` = '".$_POST['password']."'";
            $Result = $this->_BDD->query($req);
            if($tab = $Result->fetch()){
                $this->setAdminByID($tab["ID"]);
                $_SESSION["ID"] = $tab["ID"];
                $_SESSION["Connected"] = true;
                $afficheForm = false;
            }else{
                $afficheForm = true;
                $error = true;
            }
        }else{
            $afficheForm = true;
        }

        if($afficheForm == true){
            ?>
            <head>
                <link rel="stylesheet" href="style/style.css">
                <link rel="icon" href="img/14.png"/>
                <title>Gestion Admin</title>
            </head>
            <div class="background">
        <div class="filtre">
    
    <div class="LeForm">
        <form action="Gestion.php" method="post">
        <div class="icone">
            <p>☀️</p>
        </div>
        <h3>LOG IN</h3>

        <input class="champ" type="text" placeholder="Username" autocomplete="off" name="pseudo" required>

        <input class="champ" type="password" placeholder="Password" autocomplete="off" name="password" required>
        <div class="divbtn">
            <input class="boutton" type="submit" class='submit' name="BtnLogin" value='Login'>
        </div>    
        <?php
            if($error == true){
        ?><div class="erreur">Pseudo ou Mot de passe incorrect</div><?php
        }
        ?>
    </form>

</div>
        </div>
    </div>

<?php
        } 

    }

//Afficher le menu ainsi que le bouton de déconnexion
//Le bouton déconnexion vas déconnecter la session
    public function deconnexion(){
        ?>
        <div class="Menu">
            <div class="divLien">
                <a class="lien" href="Gestion.php">Capteur</a>
                <a class="lien" href="Prevision.php">Prevision</a>
                <a class="lien" href="Meteo.php">Meteo</a>
            </div>
            <form method="post">
                <input  class="deco" name="logout" type="submit" value="Se Déconnecter">
            <?php
                if(isset($_POST["logout"]))
                    {
                        session_unset();
                        session_destroy();
                        unset($_POST);
                        header("location: index.php");
                    }
            ?>
            </form>
        </div>
        <?php
    }
        
}

?>
