<!DOCTYPE html>
<html lang="en">
<?php
        include "session.php";
        if($_SESSION["Connected"] == true){        
            if(isset($_POST['Date3']) && ($_POST['Datetime']))
            {
                $datetime1 = $_POST['Date3'];
                $datetime2 = $_POST['Datetime'];
                $meteo->DeleteMeteo($datetime1,$datetime2);
            }
            if(isset($_POST['confirm-vidertable']))
            {
                $meteo->TruncateMeteo();
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
        include "menu.php";
        ?>
    <div class="titre">
        <h3>Données Méteo</h3>
    </div>
    <?php
        $meteo->AfficheMeteo();
        ?>
     <div class="deleteTab">        
        <form class="formcap" action="" method="post">
            <p>Sélectionner deux dates pour supprimer, les donnéees durant cette période</p>
            <div class="content">
            Entre
                <input name="Date3" type="datetime-local">
                Et
                <input name="Datetime" type="datetime-local">
            </div>
            <input class="valid" type="submit" value="Supprimer">
            <div>         
                <input class="truncate" id="truncate" type="button" value="Vider la table">
                <input name="confirm-vidertable" id="confirm" class="truncate" type="submit" value="Confirmer Supp">
                <input class="truncate" id="Cancel" type="button" value="Annuler">
            </div>
        </form>
    </div>
    <script src="style/style.js"></script>
    <?php

    ?>
</body>
<?php
        }
?>

</html>