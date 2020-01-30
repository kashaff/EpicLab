<?php

class dht11{
 public $link='';
 function __construct($Ax, $Ay, $Az, $T, $Gx, $Gy, $Gz){
  $this->connect();
  $this->storeInDB($Ax, $Ay, $Az, $T, $Gx, $Gy, $Gz);
 }
 
 function connect(){
  $this->link = mysqli_connect('localhost','root','') or die('Cannot connect to the DB');
  mysqli_select_db($this->link,'temp') or die('Cannot select the DB');
 }
 
 function storeInDB($Ax, $Ay, $Az, $T, $Gx, $Gy, $Gz){
  $query = "insert into dht11 set Ax='".$Ax."', Ay='".$Ay."', Az='".$Az."', T='".$T."', Gx='".$Gx."', Gy='".$Gy."', Gz='".$Gz."'";
  $result = mysqli_query($this->link,$query) or die('Errant query:  '.$query);
 }
 
}
#if($_GET['Ax'] != '' or  $_GET['Ay'] != '' or $_GET['Az'] != '' or  $_GET['T'] != '' $_GET['Gx'] != '' or  $_GET['Gy'] != '' or   $_GET['Gz'] != ''){
 $dht11=new dht11($_GET['Ax'],$_GET['Ay'],$_GET['Az'],$_GET['T'],$_GET['Gx'],$_GET['Gy'], $_GET['Gz']);
#}
?>

