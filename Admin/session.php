<?php
session_start();
include "class/Admin.php";
include "class/Meteo.php";

$base = null;
$errorMessage="";
$user="admin";
$pass="admin";
    
    
try{
    $base=new PDO("mysql:host=192.168.65.201;dbname=Meteo", $user, $pass);
}catch(Exception $e){
        $errorMessage .= $e->getMessage();
    }

    $user1 = new Admin($base);
    $meteo = new Meteo($base);
?>