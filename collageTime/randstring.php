<?php

function rands($length=32,$chars="0123456789abcdefghijklmnopqstruvwxyzABCDEFGHIJKLMNOPQSTRUVWXYZ"){

  if($length<=0) return false;
  $ret="";
  $charslen=strlen($chars)-1;
  for($i=0; $i<$length;$i++)
    {
      $ret.=$chars[mt_rand(0,$charslen)];
    }

  return $ret;
}

 
$argvlist=$argv;

if($argc>=3){
print rands($argvlist[1],$argvlist[2]);
}
else if($argc>=2){
    print rands($argvlist[1]); 
}
else{
  print rands();
}
print "\n";
?>
