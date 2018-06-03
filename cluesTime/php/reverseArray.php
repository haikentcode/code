<?php

function reverse(& $ar,$s=-1,$e=-1){

  $size = count($ar);

  if($s>$e ||  ($size-1) < $e ){

    throw new Exception('Invalid range');
  }


  if($s >=0 and $e >0){
   while($s<$e){
         $tmp = $ar[$s];
         $ar[$s] = $ar[$e];
         $ar[$e] =$tmp;
         $s++;
         $e--;
   }
 }else{

   for($i=0;$i<$size/2;$i++){
         $tmp = $ar[$size-$i-1];
         $ar[$size-$i-1] = $ar[$i];
         $ar[$i] =$tmp;
   }

 }

   return $ar;
}


function rotate(& $arr,$d){
    reverse($arr,0,$d-1);
    reverse($arr,$d,count($arr)-1);
    reverse($arr);
}


$arr = Array(1, 2, 3, 4, 5, 6, 7);


print_r($arr);
rotate($arr,3);
print_r($arr);


?>
