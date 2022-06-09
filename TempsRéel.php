<?php
    try{
        $errorMessage="";
        $user="admin";
        $pass="admin";
        //pdo bal bla
        $bdd = new PDO("mysql:host=192.168.65.201; dbname=Meteo", $user, $pass);
    }catch(Exception $e){
        $errorMessage .= $e->getMessage();
    }
?>
<!DOCTYPE html>
<html lang="fr">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Station Météo</title>
    <link rel="stylesheet" type="text/css" href="CSS/style.css">
    <link rel="stylesheet" type="text/css" href="CSS/menu.css">
    <link rel="stylesheet" type="text/css" href="CSS/prevision.css">
</head>

<body>
<?php
        include "menu.php";

            $req = $bdd->query("SELECT * FROM `Capteur` ORDER BY `Capteur` .`Date` DESC LIMIT 1;");
            $res = $req->fetch();
    ?>
            <div class="tablezone">
                <table class="tableprevision">
                    <thead>
                        <tr>
                            <td>Pression</td>
                            <td>Température</td>
                            <td>Humidité</td>
                            <td>Jour/Nuit</td>
                            <td>Pluie</td>
                            <td>Quantité de pluie</td>
                        </tr>
                    </thead>
                    <tbody>
                        <tr>
                            <?php   
                            echo '<td id="Pression">' .$res['Pression'] . '</td>';
                            echo '<td id="Temperature">' . $res['Temperature'] . '</td>';
                            echo '<td id="Humidite">' . $res['Humidite'] . '</td>';
                            echo '<td id="DayTime">' . $res['JourNuit'] . '</td>';
                            echo '<td id="Pluie">' . $res['Pluviometre'] . '</td>';
                            echo '<td id="RainAmmount">' . $res['Pluie'] . '</td>';
                            ?>
                        </tr>
                    </tbody>
                </table>
            </div>

    <script src="./JS/websocket.js"></script>
    <script type="module" src="https://unpkg.com/ionicons@5.5.2/dist/ionicons/ionicons.esm.js"></script>
    <script nomodule src="https://unpkg.com/ionicons@5.5.2/dist/ionicons/ionicons.js"></script>
</body>

</html>