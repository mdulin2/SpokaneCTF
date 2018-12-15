<html>
<head> 
	<link rel="stylesheet" href="style.css" type="text/css">
</head>
<body>
        <center>
        <h1>
        Cats!
        </h1>
        </center>
<?php

// Get all of the pictures of wonderful cats from the pictures directory.
$dir    = '/var/www/html/pictures';
$allFiles = scandir($dir);
$files = array_diff($allFiles, array('.','..'));
// The ID of the picture, from the URL 
$picID = htmlspecialchars($_GET["id"]);

// Iterate through the directory,to display correct information
$index = 0;
echo "<center>";
foreach ($files as $key => $pic){
	// Display the image!
	if($picID == $index){	
		echo '<img src="pictures/'.$pic.'" height="400px"/>';
	}
	// Display the previous click link
	elseif($picID == $index + 1 ){
		echo '<a href ="cats.php?id='.($picID -1).'">See Previous   </a>';
	}
	// Display the next click link
	elseif($picID == $index - 1){
		echo '<a href ="cats.php?id='.($picID +1).'"> See Next   </a>';
	}
	$index = $index +1;
}
echo "</center>"
?> 
<p>
	<center>
		<a href= "upload.php">Click here to upload cats!</a>
	</center>
</p>
</body>
</html>
