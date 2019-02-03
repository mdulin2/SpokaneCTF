# Cats!

This will be an attack/defense problem.

The web application simply displays cats! The user can also upload their own images.

The application is written in PHP7.0 (running on an apache server), needs specific permissions to work. All of the code is in the html directory.

## Files
Files in html:
- cats.php: displays the cats to the users. Allows for navigation.
- index.php: the home page.
- styles.css: Styling
- upload.php: The portal for uploading cat pictures.
- pictures: Where the images are stored at.

Other files:
- .replace files are for a reset of the files (will write these functionality when the PHP files are done changing)
- attack.php: A working exploit.

In order to start, put html into the **var/www** folder. Once that is done, start apache2. Make sure that PHP is installed on the system.

# Exploit:
- The file upload does not do proper sanitation on user input. Instead of uploading an image, upload a PHP file to execute arbitrary code on the system.
- An alternative approach would be to override a file on the OS (such as the etc/password). This have not tested this though.
- The attack.php, when uploaded, opens the etc/passwd to get the password hashes.

# Mitigation: 
- Allow only image files
