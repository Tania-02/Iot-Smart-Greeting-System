<?php 
header("access-control-allow-origin: *");//allow any kind of  incomming connection
error_reporting(E_ERROR);
$file='data';
$prev=file_get_contents($file);
//echo $prev;

if($_GET["data"])
{
  $input=$_GET["data"];
 //echo '<h2><font color="black" size="5"><b>Light Sensing Data<b> </fonts>::&nbsp;&nbsp;&nbsp;'.$input.'<br></h2>';   
  file_put_contents("data2", $input);
}
else if($_GET["show"])
{
  
     echo file_get_contents('data2');
   
}
if($_GET["clear"])
{
  file_put_contents($file," ");  
  file_put_contents('data2'," ");  
}
 if($_GET["disp"])
{

  $data="pp";
	$input=file_get_contents("data2");
// file_put_contents("data2", $input);
	//$a = explode(",", $next);
	if($input>=200)
	  {
	  	$data=' GOOD MORNING!!!!';
	  	//file_put_contents('data.txt', 'GOOD MORNING!!!!');
	    //echo $data;	  	  	
  }
    else if($input>=100 && $input<200)
	{
      $data=' GOOD EVENING!!!!';
      //file_put_contents('data.txt', 'GOOD EVENING!!!!');
      //echo $data;	
    }
    else if($input<100)
	{
      $data=' GOOD NIGHT!!!!';
      //file_put_contents('data.txt', 'GOOD NIGHT!!!!');
      //echo $data;	
    }

  date_default_timezone_set('Asia/Kolkata');
  $date = date('m/d/Y h:i:s a', time());
   //file_put_contents($file, $prev);
   echo $data." ".$date ;  
	 //file_put_contents('data.txt', /*document.getElementById("show").innerHTML = Date()*/$date);
        
	// $myfile = fopen('data.txt', 'r+') or die('Unable to open file!');
// Output one line until end-of-file
  //while(!feof($myfile)) {
  //echo '<p id="myfile" style="color: white; text-align: center">'.fgets($myfile).'</p><br>';
 //}
 // fclose($myfile);
	}
 ?>
