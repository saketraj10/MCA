<?php
$accno=$_GET['accno'];
//require('conn.php');
$host = "localhost";
$db_name = "library";
$username = "root";
$password = "";

//connect to mysql server
$mysqli = new mysqli($host, $username, $password, $db_name);



$qry="delete from data where acc_no=$accno";
$check=$mysqli->query($qry);

    

if($check){
    echo'<script>alert("Deleted succesfully ");</script>';
    //<script>   
   //var x=document.getElementById('demo').innerHTML="Record INserted successfully";
    
    
    
    //</script>
}
else{
    echo'<script>alert("Ooops..soemthing went wrong..");</script>';
}
?>