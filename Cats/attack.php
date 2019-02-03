<?php

$fh = fopen('/etc/Services/ServiceA/flag.txt','r');
while ($line = fgets($fh)) {

   echo($line);
}
fclose($fh);
?>
