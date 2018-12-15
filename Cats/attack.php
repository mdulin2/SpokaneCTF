<?php

$fh = fopen('/etc/passwd','r');
while ($line = fgets($fh)) {

   echo($line);
}
fclose($fh);
?>
