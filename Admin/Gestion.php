<!DOCTYPE html>
<html lang="en">
<?php
    include "session.php";
    if($_SESSION["Connected"] == true){
        
        //Si les deux input(bouton) Datetime sont envoyer par le formulaire,
        // alors on appelle la fonction qui permet de supprimer des données de la table Capteur
        if(isset($_POST['Datetime1']) && ($_POST['Datetime2']))
            {
                $datetime1 = $_POST['Datetime1'];
                $datetime2 = $_POST['Datetime2'];
                $meteo->DateSupp($datetime1,$datetime2);
            }
        //Si le input(bouton) confirm est envoyer par le formulaire,
        // alors on appelle la fonction qui permet de vider la table Capteur     
        if(isset($_POST['confirm-vider-table']))
            {
                $meteo->TruncateCapteur();
            }
?>
      
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="style/table.css">
    <link rel="stylesheet" href="style/menu.css">
    
    <link rel="icon" href="img/14.png" />
    <title>Gestion Admin</title>
</head>
<body>
    <?php
        $admin1->deconnexion();
        //include "menu.php";?>
        <div class="titre">
            <h3>Données Capteur</h3>
        </div>
    <?php
        $meteo->affiche();
    ?>
    <div class="deleteTab">        
        <form class="formcap" method="post">
            <p>Sélectionner deux dates pour supprimer, les donnéees durant cette période</p>
            <div class="content">
                Entre
                <input name="Datetime1" type="datetime-local">
                Et
                <input name="Datetime2" type="datetime-local">
            </div>
            <input class="valid" type="submit" value="Supprimer">   
            <div>         
                <input class="truncate" id="truncate" type="button" value="Vider la table">
                <input name="confirm-vider-table" id="confirm" class="truncate" type="submit" value="Confirmer Supp">
                <input class="truncate" id="Cancel" type="button" value="Annuler">
            </div>
        </form>
    </div>
    <script src="style/style.js"></script>
</body>
<?php
    }
?>                  
</html>