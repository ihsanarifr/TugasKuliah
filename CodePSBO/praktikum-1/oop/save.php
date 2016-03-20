<?php
$name = $_POST['name'];
$comment = $_POST['comment'];
$date = date("Y-m-d H:i:s");

if($name == "" || $comment == ""){
  echo "Error!";
  exit;
}else{
  $db =  fopen("data.txt","a");
  fwrite($db,$name."/".$date."/".$comment."***");
  fclose($db);
  echo "comment saved!";
}
?>
