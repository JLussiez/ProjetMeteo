<?php

 class Admin{

    private $_ID;
    private $_Pseudo;
    private $_Mdp;
    private $_BDD;


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
    public function getID(){
        return $this->_ID;
    }

    public function getPseudo(){
        return $this->_Pseudo;
    }

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

        
}

?>