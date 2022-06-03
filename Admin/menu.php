<div class="Menu">
    <div class="divLien">
        <a class="lien" href="Gestion.php">Capteur</a>
        <a class="lien" href="Prevision.php">Prevision</a>
        <a class="lien" href="Meteo.php">Meteo</a>
    </div>
        <form method="post">
        <input  class="deco" name="logout" type="submit" value="Se Déconnecter">
        <?php
            if(isset($_POST["logout"])){
                                    $admin1->deconnexion();
                                }
                            ?>
    </form>
    </div>