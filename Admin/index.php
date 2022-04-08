<?php
include "class/Admin.php";

$user = new Admin($BDD);

?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="style/style.css">
    <title>Gestion Admin</title>
</head>
<body>
    <?php
        $user->formUser();
    ?>
</body>
</html>