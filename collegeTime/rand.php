<?PHP 
//set the random id length 
$random_id_length = 10; 

//generate a random id encrypt it and store it in $rnd_id 
$rnd_id = crypt(uniqid(rand(),1)); 

//to remove any slashes that might have come 
$rnd_id = strip_tags(stripslashes($rnd_id)); 

//Removing any . or / and reversing the string 
$rnd_id = str_replace(".","",$rnd_id); 
$rnd_id = strrev(str_replace("/","",$rnd_id)); 

//finally I take the first 10 characters from the $rnd_id 
$rnd_id = substr($rnd_id,0,$random_id_length); 

echo "Random Id: $rnd_id"; 
?> 
