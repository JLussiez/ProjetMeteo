<!DOCTYPE html>
<html lang="en">
    <?php
    include "session.php";
    if($_SESSION["Connected"] == true){
    ?>
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="style/table.css">
    <link rel="stylesheet" href="style/menu.css">
    <link rel="icon" href="img/14.png"/>
    <title>Gestion</title>
</head>
<body>

        <div class="menu">
        <a class="ok" href="Gestion.php">Capteur</a>
        <h2>Table Prevision</h2>
        <form method="post">
        <input  class="deco" name="logout" type="submit" value="Se Déconnecter">
        <?php
            if(isset($_POST["logout"])){
                                    $admin1->deconnexion();
                                }
                            ?>
    </form>
    </div>
    <?php
        $meteo->AffichePrevision();
    ?>

</body>
<?php
    }
?>
</html>