<!-- Previsions.php réalisé par Lussiez Julien-->

<?php
    try{
        $errorMessage="";
        $user="admin";
        $pass="admin";
        //PDO pour initialiser la connexion à la BDD
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
    <p>
        <?php
            include "menu.php";
            // requête pour récupèrer la dernière prévision météo
            $req = $bdd->query("SELECT * FROM `Prevision_Meteo` ORDER BY `Prevision_Meteo`.`Date` DESC LIMIT 1");
            $res = $req->fetch();

        ?>
        <div class="tablezone">
            <table class="tableprevision">
                <thead>
                    <tr>
                        <td colSpan="2">Prévision</td>
                        <td>Durée</td>
                        <td>Date</td>
                    </tr>
                </thead>
                <tbody>
                    <tr>
                        <?php
                        // ajout d'une image en fonction du temps affiché par la prévision
                            if ($res['Prevision'] == 'Beau temps'){
                                echo '<td id="logo"> <img src="IMG/sun.png"></td>';
                            }
                            if ($res['Prevision'] == 'Risque de pluie'){
                                echo '<td id="logo"> <img src="IMG/rain.png"></td>';
                            }
                            if ($res['Prevision'] == 'Tempete'){
                                echo '<td id="logo"> <img src="IMG/storm.png"></td>';
                            }
                            if ($res['Prevision'] == 'Orage'){
                                echo '<td id="logo"> <img src="IMG/thunderstorm.png"></td>';
                            }
                            echo '<td id="prevision">' .$res['Prevision'] . '</td>';
                            echo '<td id="duree">' . $res['Duree'] . '</td>';
                            echo '<td id="date">' . $res['Date'] . '</td>';
                        ?>
                    </tr>
                </tbody>
            </table>
        </div>
    </p>
    <script type="module" src="https://unpkg.com/ionicons@5.5.2/dist/ionicons/ionicons.esm.js"></script>
    <script nomodule src="https://unpkg.com/ionicons@5.5.2/dist/ionicons/ionicons.js"></script>
</body>
</html>