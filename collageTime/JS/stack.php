<?php

$servername = "localhost";
$username = "root";
$password = "haikent";
$dbname = "haikent105";

// Create connection
$conn = new mysqli($servername, $username, $password,$dbname);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

 if($_POST){
   echo "post";
   $arr=json_decode($_POST['b']);
   $len = sizeof($arr);
   $i=0;
    while ($i < $len) {
    $value = $arr[$i];
    $i+=1;
    $sql="INSERT INTO images(url) VALUES('$value');";
    if ($conn->query($sql) === TRUE) {
      echo "New record created successfully";
    } else {
      echo "Error: " . $sql . "<br>" . $conn->error;
    }
   }



 }

 $conn->close();

?>
