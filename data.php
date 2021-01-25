<?php 
header("access-control-allow-origin: *");//allow any kind of  incomming connection
error_reporting(E_ERROR);
$file='data.txt';
$curr=file_get_contents($file); 


if($_GET["data"])
{
	$data=$_GET["data"];
	file_put_contents('data2', $data);
	 
}
else if($_GET["show"])
{
	
		 echo file_get_contents('data2');
	 
}
else if($_GET["clear"])
{
	file_put_contents($file,"");	
}
else if($_GET["disp"])
{
	$data=file_get_contents('data2');
	$a = explode(",", $data);
	if($a[0]>100 && $a[1]>100)
	{
		$data="GOOD MORNING-------[TIME: ";
	}
	else if($a[0]<100 && $a[1]>100)
	{
		$data="GOOD NIGHT------------[TIME: ";
	}
	else
	{
		$data="SWITCHED OFF---------[TIME: ";
	}
	date_default_timezone_set('Asia/Kolkata');
	$date = date('m/d/Y h:i:s a', time());
	$curr=$curr.$data.$date."] \n";
	 file_put_contents($file, $curr);
	echo file_get_contents($file);	
}
if($_GET["username"])
{
	$data1=$_GET["username"];
	$data2=$_GET["uid"];
	file_put_contents('login', $data1.",".$data2);
	header('Location: detector.html');
	 
}
if($_GET["log"])
{
	echo file_get_contents('login');
	 
}
else
{

}

 ?>