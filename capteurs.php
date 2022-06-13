<!-- capteurs.php réalisé par Lussiez Julien-->

<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Station Météo</title>
    <link rel="stylesheet" type="text/css" href="CSS/style.css">
    <link rel="stylesheet" type="text/css" href="CSS/menu.css">
    <link rel="stylesheet" type="text/css" href="CSS/capteurs.css">
</head>
<body> 
    
    <?php
        include "menu.php";
    ?>
    <!-- Explication des différents capteurs-->
    <article class="forecast">
    <h1>Les différents capteurs de la station</h1>

    <article class="day-forecast">
        <h2>Anémomètre</h2>
        <p>L'anémomètre sert à mesurer la vitesse du vent.</p>
    </article>

    <article class="day-forecast">
        <h2>Baromètre</h2>
        <p>Le baromètre sert à relever la pression dans l'air.</p>
    </article>

    <article class="day-forecast">
        <h2>Capteur de pluie</h2>
        <p>Le capteur de pluie sert à détecter s'il pleut ou non.</p>
    </article>

    <article class="day-forecast">
        <h2>Capteur Jour/Nuit</h2>
        <p>La capteur Jour/Nuit sert à déterminer s'il fait jour ou nuit.</p>
    </article>

    <article class="day-forecast">
        <h2>Girouette</h2>
        <p>La girouette sert à indiquer le sens du vent.</p>
    </article>
    
    <article class="day-forecast">
        <h2>Hygromètre</h2>
        <p>L'hygromètre sert à déterminer le taux d'humidité dans un espace ouvert ou fermé.</p>
    </article>

    <article class="day-forecast">
        <h2>Pluviomètre</h2>
        <p>Le pluviomètre sert à mesurer les précipitations.</p>
    </article>

    <article class="day-forecast">
        <h2>Solarimètre</h2>
        <p>Le Solarimètre sert à mesurer l'intensité lumineuse.</p>
    </article>

    <article class="day-forecast">
        <h2>Thermomètre</h2>
        <p>Le Thermomètre sert à mesurer la température.</p>
    </article>

    <script type="module" src="https://unpkg.com/ionicons@5.5.2/dist/ionicons/ionicons.esm.js"></script>
    <script nomodule src="https://unpkg.com/ionicons@5.5.2/dist/ionicons/ionicons.js"></script>
</body>
</html>