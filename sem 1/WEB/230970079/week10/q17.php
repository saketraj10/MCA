<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Exercise02-Cookie</title>
</head>
<body>
<?php
    // Check if the cookie is set
    if(isset($_COOKIE["Lastvisit"])) 
    {
        $lastVisit = $_COOKIE["Lastvisit"];
        echo "Last visited on: " . $lastVisit;
    } 
    else 
    {
        echo "Welcome!";
    }
    // Set the cookie with the current date-time
    $now = date("Y-m-d H:i:s");
    setcookie("Lastvisit", $now, time() + (86400 * 30), "/");
?>
</body>
</html>