<?php 

echo "<html>
<head>
	<title>Light Detector</title>
<script src='http://code.jquery.com/jquery-1.12.4.js' type='text/javascript'></script>
<link rel='stylesheet' href='style.css'> 
</head>

<header>
<div id='header'>
	<h2>ONLINE LIGHT DETECTING</h2>
	<p>greeting website<p>
</div>
</header>
<body>

<br><br><br><br><br>
<form action='/iot_project/data.php'>
		<div id='f'>
 		<b>USER NAME    :</b><input type='text' required='' name='username' >
  		<br><br>
 		<b>USER ID      :</b><input type='text' required='' name='uid' >
 		<br><br>
  		<input type='submit' value='LOGIN'>
  		</div>
</form> 

<footer >
	<div id='foot'>
		
			<p><h2>Thank You for Using ONLINE LIGHT DETECTOR </h2></p>
			<p><h5>made by SAM*</h5></p>
		
	</div>
</footer>
</body>

</html>"	;

 ?>