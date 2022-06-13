<?php
session_start();
include "class/Admin.php";
include "class/Bdd.php";

//$base = null;
$errorMessage="";
$user="admin";
$pass="admin";


    
try{
    //Connexion à la base de données
    $bdd = new PDO("mysql:host=192.168.65.201; dbname=Meteo", $user, $pass);
}catch(Exception $e){
        $errorMessage .= $e->getMessage();
    }

    //Création des objets
    $admin1 = new Admin($bdd);
    $meteo = new Bdd($bdd);

    //Session administrateur pour l'accés aux sites
    if (isset($_SESSION["Connected"]) && $_SESSION["Connected"] == true){
        if(isset($_SESSION["ID"])){
            $admin1->setAdminbyID($_SESSION["ID"]);
        }
    }else{
        $admin1->formUser();
    } 

?>