<!DOCTYPE html>
<html>
<head> 
        <link rel="stylesheet" href="style.css" type="text/css">
  <title>Upload your files</title>
</head>
<body>
  <form enctype="multipart/form-data" action="upload.php" method="POST">
    <p>Upload your file</p>
    <input type="file" name="uploaded_file"></input><br />
    <input type="submit" value="Upload"></input>
  </form>
<p>
	<a href="cats.php">Back to Cats!</a>
</p>
</body>
</html>
<?PHP
// Logic for uploading a file
  if(!empty($_FILES['uploaded_file']))
  {
	// The insert path
    $path = "/var/www/html/pictures/";
    $path = $path . basename( $_FILES['uploaded_file']['name']);
	
	// Should probably put some input validation here. 
	if(move_uploaded_file($_FILES['uploaded_file']['tmp_name'], $path)) {
      echo "The file ".  basename( $_FILES['uploaded_file']['name']). 
      " has been uploaded. Click <a href='pictures/". basename( $_FILES['uploaded_file']['name']) . "'>here <a/> to view the file!";
    } else{	
	echo "Error in upload...";    
    }
  }
?>
