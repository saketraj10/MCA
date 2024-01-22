<html>
<body>
<?php
session_start();
echo session_id();
?>
<?php
if(isset($_SESSION['views']))
$_SESSION['views']=$_SESSION['views']+1;
else
$_SESSION['views']=1;
echo "Views=". $_SESSION['views'];
?>
</body>
</html>