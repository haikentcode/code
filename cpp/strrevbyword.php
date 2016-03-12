<?php

  $s="I Love You Aditi";
  print strrev($s)."\n";
   
   $word=explode(' ',$s);
   $word=array_reverse($word);
   $wr=implode(' ',$word);

  print $wr."\n";  
 
?>
