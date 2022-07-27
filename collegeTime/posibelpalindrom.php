<?php


fscanf(STDIN, "%s\n", $T);
$r = 0.5;
for ($i=0; $i < $T; $i++) { 
   fscanf(STDIN, "%s",$s);
   $a=array();
   $A=str_split($s);  
   for ($j=0; $j < strlen($s);$j++){
    
       if (array_key_exists($A[$j], $a)){
                  
            $a[$A[$j]]=$a[$A[$j]]+1;
        }else{
           
          $a[$A[$j]]=1; 
         }       

    }
    $counter=0;  
    foreach($a as &$val){
     if($val%2!=0) $counter++;
    }  
    
   if(strlen($s)%2!=0 && $counter==1) echo "YES\n";
   else if($counter==0) echo "YES\n";
   else echo "NO\n"; 
}


?>
