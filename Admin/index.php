<?php
    include "session.php";
    if($_SESSION["Connected"] == true){
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="style/style.css">
    <link rel="icon" href="img/14.png"/>
    <title>Gestion Admin</title>
</head>
<body>
    <div class="background">
        <div class="filtre">
            <?php
                $admin1->formUser();
            ?>
        </div>
    </div>
</body>
</html>            <?php
    }
            ?>