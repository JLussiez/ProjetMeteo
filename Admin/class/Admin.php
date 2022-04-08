<?php

 class Admin{

    private $_IDAdmin;
    private $_Pseudo;
    private $_Mdp;
    private $_BDD;


    public function __construct($BDD){
        $this->_BDD = $BDD;
    }

    
    public function formUser(){
    ?>
    <div class="background">
        <div class="filtre">
        <div class="LeForm">
            <form action="" method="POST">
                <div class="icone">
                    <p>👾</p>
            <!--<img src="img/logo.png"/>-->
                </div>
                <h3>LOG IN</h3>

                <input class="champ" type="text" placeholder="Username" name="username" required>

                <input class="champ" type="password" placeholder="Password" name="password" required>
                <div class="divbtn">
                    <input class="boutton" type="submit" class='submit' name="BtnLogin" value='Login'>
                </div>

            </form>
        </div>
        </div>
    </div>
     
     
     
     <?php


    }


}

?>