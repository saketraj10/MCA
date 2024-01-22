<?php
$host = "localhost";
$db_name = "library";
$username = "root";
$password = "";

//connect to mysql server
$mysqli = new mysqli($host, $username, $password, $db_name);

//check if any connection error was encountered
if(mysqli_connect_errno()) {
    echo "Error: Could not connect to database.";
    exit;
}
else
	 echo "Connected to database.";
?>
