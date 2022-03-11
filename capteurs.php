<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Station Météo</title>
    <link rel="stylesheet" type="text/css" href="CSS/style.css">
    <link rel="stylesheet" type="text/css" href="CSS/menu.css">
</head>
<body> 
    
    <?php
        include "menu.php";
    ?>

<div class="text-zone">
        <h2 class="title">
            <a href="#">Capteurs</a>
        </h2>
    </div>

<div id="icons">
    <span>Hygromètre</span>
        <ion-icon name="water-outline"></ion-icon>
    <span>Capteur de pluie</span>
        <ion-icon name="rainy-outline"></ion-icon>
    <span>Capteur Jour/Nuit</span>
        <ion-icon name="cloudy-night-outline"></ion-icon>
    <span>Thermomètre</span>
        <ion-icon name="thermometer-outline"></ion-icon>
    <span>Baromètre</span>
        <ion-icon name="trending-up-outline"></ion-icon>
</div>

    <script type="module" src="https://unpkg.com/ionicons@5.5.2/dist/ionicons/ionicons.esm.js"></script>
    <script nomodule src="https://unpkg.com/ionicons@5.5.2/dist/ionicons/ionicons.js"></script>
</body>
</html>