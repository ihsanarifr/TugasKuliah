<?php
class Comment{
 private $name;
 private $comment;
 private $date;
 
 public function setName($name){
  $this->name = $name;
 }
 public function setComment($comment){
  $this->comment = $name;
 }
 public function setDate($date){
  $this->date = $date;
 }

 public function validation(){
  if($this->name == "" || $this->comment == "")
    return false;
  else
   return true;
 }
 
 public function save(){
  $db = fopen("data.txt","a");
  fwrite($db,$this->name."/".$this->date."/".$this->comment."***");
  fclose($db);
 }
}
