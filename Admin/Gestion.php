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
    <link rel="icon" href="img/14.png"/>
    <title>Gestion</title>
</head>
<body>
        <?php
            $meteo->affiche();
        ?>
</body>
<?php
    }
?>
</html>