<?php
class Person{
          protected $__data=array();
           
          public function __get($property){
               if(isset($this->__data[$property])){
                    return $this->__data[$property];
                 }
               else{
                   return false;
                }
          }
         
          public function __set($property,$value){
                      $this->__data[$property]=$value;
                    }

           }


          $hk=new Person;
          $hk->name="hitesh";
          $hk->gf="aditi";
          print $hk->name ." love ".$hk->gf;

?>
