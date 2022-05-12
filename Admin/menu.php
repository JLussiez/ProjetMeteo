<div class="menu">
        <a class="ok" href="Prevision.php">Prevision</a>
        <h2>Table Capteur</h2>
        <form method="post">
        <input  class="deco" name="logout" type="submit" value="Se Déconnecter">
        <?php
            if(isset($_POST["logout"])){
                                    $admin1->deconnexion();
                                }
                            ?>
    </form>
    </div>