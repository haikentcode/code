<?php

function lookandsay($s){

 $pre=$s[0];
 $ret="";
 $count=1;
 for($i=1 ; $i<strlen($s); $i++){

        if($s[$i]==$pre){
           $count++;
       }
       else
      {
        $ret.=$count.$pre;
        $pre=$s[$i];
        $count=1;
      }
   
   }


 $ret.=$count.$pre;

  return $ret;
}

 $s=1;
for($i=1;$i<20;$i++){
 
  $s=lookandsay($s);
  print $s."\n";

}



?>
