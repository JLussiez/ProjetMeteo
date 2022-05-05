<?php
session_start();
include "class/Admin.php";
include "class/Meteo.php";

//$base = null;
$errorMessage="";
$user="admin";
$pass="admin";


    
try{
    $bdd = new PDO("mysql:host=192.168.65.201; dbname=Meteo", $user, $pass);
}catch(Exception $e){
        $errorMessage .= $e->getMessage();
    }
    $admin1 = new Admin($bdd);
    $meteo = new Meteo($bdd);

    if (isset($_SESSION["Connected"]) && $_SESSION["Connected"] == true){
        if(isset($_SESSION["ID"])){
            $admin1->setAdminbyID($_SESSION["ID"]);
        }
    }else{
        $admin1->formUser();
    } 

?>