<!DOCTYPE html>
<html lang="en">
<?php
    include "session.php";
    /*if(isset($_POST['supp'])){
        $meteo->delete($id);
        header('location: Gestion.php');
    }*/
    if($_SESSION["Connected"] == true){

        if(isset($_POST['del']))
        {
            $meteo->DateSupp($_POST['del']);
        }

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
    
    <?php
        include "menu.php";
            $meteo->affiche();
        ?>
        <div class="deleteTab">
            <h3>Supprimer de la base sur une période données</h3>
            <form class="formcap" action="Gestion.php" method="post">
                <p>Supprimer la données au bout de X jour</p>
                <select name="del">
                    <option value="" disabled selected>Sélectionner le nombre de jour</option>
                    <option value="1">1</option>
                    <option value="2">2</option>
                    <option value="3">3</option>
                    <option value="4">4</option>
                    <option value="5">5</option>
                </select>
                <input class="valid" type="submit" value="Supprimer">
            </form>
        </div>
</body>
<?php
    }
?>
</html>