# Steganography

This is a file for Github Spokane CTF Steganography challenges

## Challenges

1. Blank Canvas
2. Rubik's Cube
3. Missing Piece
4. Squares
5. Checkmate

## Steg1: Blank Canvas

Message:
Recently, threats have been sent to people in our community. Our detectives have recovered shredded pieces of paper they believe are connected to these threats. Please help find out where these pieces of paper are being printed from.

Solution:
-	Tilt screen up and the flag will be revealed.
-	Also, using a photo editor will work as well. By enhancing or adjusting the brightness of the photo it will reveal the flag.

*The flag is Mt. Spokane*

How it was created:
The challenge gives the idea of a Machine Identification Code. Modern printers use this digital watermark to ID the device used to print a document.
In this challenge, the watermark is the flag. Using an online photoshop tool, yellow text is added, and the opacity is lowered to 5%.



## Steg2: Rubik's Cube

Message:
We have intercepted communications between a group of criminals in our city. They are planning on robbing a bank downtown. They will be meeting next week and have sent out this image which contains the secret phrase to get into the meeting. Please help us figure out what the secret phrase is.

Solution:
For this challenge, running Digital Invisible Ink Toolkit will
find the flag.

-	Download the .jar file from Digital invisible ink toolkit website.

-	Using the terminal in Kali Linux, run java -jar diit-1.5.jar

-	Digital invisible ink toolkit will pop up, click on decode, get image, select the steg2.bmp image.

-	no password is needed, select the HideSeek algorithm

-	set message to write to a file on desktop ex. steg2Solution

-	Flag will be in a text file that you set message to write to

*The flag is James Nettle Glover*

How it was created:
To make this challenge, I needed an image (Rubik’s cube jpg), a text
file that will have the flag, and Digital Invisible Ink Tool.

-	Running the Digital invisible ink toolkit, click on encode.

-	Pick a message to embed, in this case it’s the .txt file with the flag.

-	Pick a cover image which would be the Rubik’s cube .jpg.

-	No password was added, and the algorithm was set to HideSeek.

-	Set the stego image to write to a location on the desktop. a bmp image named steg2.bmp was the output image with the flag hidden inside


## Steg3: Missing Piece

Message:
The hospital has been hit with ransomware. Hacker requires that we pay or solve this puzzle to unlock our data. Paying is NOT an option. Please help us find the password to unlock our data.

Solution:
In this challenge, the two most important tools are Digital Invisible Ink Toolkit and Audacity.

-	Download the .jar file from Digital invisible ink toolkit website.

-	Using the terminal in Kali Linux, run java -jar diit-1.5.jar

-	Digital invisible ink toolkit will pop up, click on decode, get image, select the steg3.bmp image.

-	no password is needed, select the BlindHide algorithm

-	set message to write to a file on desktop ex. steg3Solution

-	An Audio file will be revealed and contains the flag. When the audio File is played it will play random noise.

-	Download Audacity and analyze the audio file by switching from waveform to spectrogram

*The flag is Knitting Factory Spokane*

How it was created:
To make this challenge, I needed an image (puzzle jpg), an app on my phone using APT-Pro to create
the audio file, paint tool to create the flag, and audacity and digital invisible ink toolkit.

-	First create the flag by using the paint tool to make an image with a black background
and white letters.

-	Download the app APT-Pro for the app store and hide the image in the audio file that is
created using the app. The app will play random noise, you could record your voice as well.

-	Download audacity and test to see if audio file plays and to test if the image was placed
inside the audio file. switch from waveform to spectrogram and the words/flag should be revealed.

-	Download the .jar file from Digital invisible ink toolkit website.

-	Using the terminal in Kali Linux, run java -jar diit-1.5.jar

-	Digital invisible ink toolkit will pop up, click on encode, get message, select the audio file.

-	pick a cover image, in this case it was the puzzle .jpg

-	no password is needed, select the BlindHide algorithm

-	set message to write to a file on desktop ex. steg3.bmp



## Steg4: Squares

Message:
.. -- .--. --- .-. - / .-. . / .-.-.. .--. .- ... ... .-- --- .-. -.. / -...- / .-..-. -.-. .-. --- ... ... .-- --- .-. -.. .-..-. .-.-.. ..-. .-.. .- --. / -...- / ----- .-.-.. .-- .... .. .-.. . / - .-. ..- . ---... / .-.-.. / .. ..-. / -.--. .-.. . -. -.--. .--. .- ... ... .-- --- .-. -.. -.--.- / ---.. -.--.- ---... / .-.-.. / ..-. .-.. .- --. / -...- / -....- .---- .-.-.. / -... .-. . .- -.- .-.-.. / . .-.. .. ..-. / -. --- - / .-. . .-.-.- ... . .- .-. -.-. .... -.--. .-..-. / .- -....- --.. / .-..-. --..-- / .--. .- ... ... .-- --- .-. -.. -.--.- ---... / .-.-.. / ..-. .-.. .- --. / -...- / -....- .---- .-.-.. / -... .-. . .- -.- .-.-.. / . .-.. .. ..-. / -. --- - / .-. . .-.-.- ... . .- .-. -.-. .... -.--. .-..-. / .- -....- --.. / .-..-. --..-- / .--. .- ... ... .-- --- .-. -.. -.--.- ---... / .-.-.. / ..-. .-.. .- --. / -...- / -....- .---- .-.-.. / -... .-. . .- -.- .-.-.. / . .-.. .. ..-. / -. --- - / .-. . .-.-.- ... . .- .-. -.-. .... -.--. .-..-. / ----- -....- ----. / .-..-. --..-- / .--. .- ... ... .-- --- .-. -.. -.--.- ---... / .-.-.. / ..-. .-.. .- --. / -...- / -....- .---- .-.-.. / -... .-. . .- -.- .-.-.. / . .-.. .. ..-. / -. --- - / .-. . .-.-.- ... . .- .-. -.-. .... -.--. .-..-. / ...-..- ...-.- .--.-. / .-..-. --..-- / .--. .- ... ... .-- --- .-. -.. -.--.- ---... / .-.-.. / ..-. .-.. .- --. / -...- / -....- .---- .-.-.. / -... .-. . .- -.- .-.-.. / . .-.. .. ..-. / .-. . .-.-.- ... . .- .-. -.-. .... -.--. .-..-. / ... .-..-. --..-- / .--. .- ... ... .-- --- .-. -.. -.--.- ---... / .-.-.. / ..-. .-.. .- --. / -...- / -....- .---- .-.-.. / -... .-. . .- -.- .-.-.. / . .-.. ... . ---... / .-.-.. / ..-. .-.. .- --. / -...- / ----- .-.-.. / .--. .-. .. -. - -.--. .-..-. ...- .- .-.. .. -.. / .--. .- ... ... .-- --- .-. -.. .-..-. -.--.- / .-.-.. / -... .-. . .- -.- .-.-.. / .-.-.. .. ..-. / ..-. .-.. .- --. / -...- -...- -....- .---- ---... / .-.-.. / .--. .-. .. -. - -.--. .-..-. -. --- - / .- / ...- .- .-.. .. -.. / .--. .- ... ... .-- --- .-. -.. .-..-. -.--.-

Solution:
Tools needed for this challenge are imageHide, Rumkin and some knowledge of python.

-	Morse code is presented to the user at first. Using rumkin to decode the Morse code will
output a python script.

-
	import re
	password = "Crossword"
	flag = 0
	while True:   
	    if (len(password)<8):
	        flag = -1
	        break
	    elif not re.search("[a-z]", password):
	        flag = -1
	        break
	    elif not re.search("[A-Z]", password):
	        flag = -1
	        break
	    elif not re.search("[0-9]", password):
	        flag = -1
	        break
	    elif not re.search("[$#@]", password):
	        flag = -1
	        break
	    elif re.search("\s", password):
	        flag = -1
	        break
	    else:
	        flag = 0
	        print("Valid Password")
	        break

	if flag ==-1:
	    print("Not a Valid Password")

-	The password needed is Crossword

-	Download ImageHide and load the steg4 image.

-	Click on Read Data and an encrypted message will show. To decrypt the message
Enter the password Crossword. The flag will then be revealed.

*The Flag is Centennial Trail*

How it was created:
-	The morse code was created using rumkin

-	The python script was a generic script for a password. Password was left intentially
in the script.

-	Taking the image of the crossword puzzle and loading it into imageHide I am able to
encrypt a message which in this case is the flag.

-	Using the password from the first part of the challenge will be needed to decrypt the secret
message.

## Steg5: Checkmate

Message:
uryyb
vz
fgrtuvqr...
gur cnffjbeq vf uvqqra va guvf zrffntr
bayl lbh unir gb ybbx uneq gb svaq vg
ernq guvf zrffntr pnershyyl gb svaq vg
lbh jvyy svaq gur synt uvqqra va gur vzntr.


Solution:
-	Message is in rot13 substitution cipher. When decoded the message output is
hello
im
steghide...
the passphrase is hidden in this message
only you have to look hard to find it
read this message carefully to find it
you will find the flag hidden in the image.

Take the first letter of the first word from each line, you get the passphrase which is history
-	The secret message in the image can be revealed by using
steghide.

-	Using the terminal in Kali Linux, run steghide.
steghide --extract -sf chess.jpeg -xf Steg5.txt
Note: -sf <filename> (extract data from <filename>), -xf <filename> (write the extracted data
to <filename>)

-	Enter passphrase: history
Note: all lowercase the passphrase is case sensitive

-	The text file will have flag but will be in JSfuck. Using a JSfuck decoder (http://codertab.com/JsUnFuck) you will get a message in hex. Converting the hex to text, the flag will be revealed.

*The flag is 502 E Boone Ave*

How it was created:
-	The message was encoded using Rot13 substitution cipher using rumkin website.
http://rumkin.com/tools/cipher/rot13.php

-	Convert the flag message from text to hex using a hex converter.
http://www.unit-conversion.info/texttools/hexadecimal/
54 68 65 20 66 6c 61 67 20 69 73 20 35 30 32 20 45 20 42 6f 6f 6e 65 20 41 76 65
take the hex and input it in a jsfuck encoder. www.jsfuck.com
[][(![]+[])[+[]]+([![]]+[][[]])[+!+[]+[+[]]]+(![]+[])[!+[]+!+[]]+(!![]+[])[+[]]+(!![]+[])[!+[]+!+[]+!+[]]+(!![]+[])[+!+[]]][([][(![]+[])[+[]]+([![]]+[][[]])[+!+[]+[+[]]]+(![]+[])[!+[]+!+[]]+(!![]+[])[+[]]+(!![]+[])[!+[]+!+[]+!+[]]+(!![]+[])[+!+[]]]+[])[!+[]+!+[]+!+[]]+(!![]+[][(![]+[])[+[]]+([![]]+[][[]])[+!+[]+[+[]]]+(![]+[])[!+[]+!+[]]+(!![]+[])[+[]]+(!![]+[])[!+[]+!+[]+!+[]]+(!![]+[])[+!+[]]])[+!+[]+[+[]]]+([][[]]+[])[+!+[]]+(![]+[])[!+[]+!+[]+!+[]]+(!![]+[])[+[]]+(!![]+[])[+!+[]]+([][[]]+[])[+[]]+([][(![]+[])[+[]]+([![]]+[][[]])[+!+[]+[+[]]]+(![]+[])[!+[]+!+[]]+(!![]+[])[+[]]+(!![]+[])[!+[]+!+[]+!+[]]+(!![]+[])[+!+[]]]+[])[!+[]+!+[]+!+[]]+(!![]+[])[+[]]+(!![]+[][(![]+[])[+[]]+([![]]+[][[]])[+!+[]+[+[]]]+(![]+[])[!+[]+!+[]]+(!![]+[])[+[]]+(!![]+[])[!+[]+!+[]+!+[]]+(!![]+[])[+!+[]]])[+!+[]+[+[]]]+(!![]+[])[+!+[]]]([!+[]+!+[]+!+[]+!+[]+!+[]]+[!+[]+!+[]+!+[]+!+[]]+(+[![]]+[][(![]+[])[+[]]+([![]]+[][[]])[+!+[]+[+[]]]+(![]+[])[!+[]+!+[]]+(!![]+[])[+[]]+(!![]+[])[!+[]+!+[]+!+[]]+(!![]+[])[+!+[]]])[+!+[]+[+!+[]]]+[!+[]+!+[]+!+[]+!+[]+!+[]+!+[]]+[!+[]+!+[]+!+[]+!+[]+!+[]+!+[]+!+[]+!+[]]+(+[![]]+[][(![]+[])[+[]]+([![]]+[][[]])[+!+[]+[+[]]]+(![]+[])[!+[]+!+[]]+(!![]+[])[+[]]+(!![]+[])[!+[]+!+[]+!+[]]+(!![]+[])[+!+[]]])[+!+[]+[+!+[]]]+[!+[]+!+[]+!+[]+!+[]+!+[]+!+[]]+[!+[]+!+[]+!+[]+!+[]+!+[]]+(+[![]]+[][(![]+[])[+[]]+([![]]+[][[]])[+!+[]+[+[]]]+(![]+[])[!+[]+!+[]]+(!![]+[])[+[]]+(!![]+[])[!+[]+!+[]+!+[]]+(!![]+[])[+!+[]]])[+!+[]+[+!+[]]]+[!+[]+!+[]]+[+[]]+(+[![]]+[][(![]+[])[+[]]+([![]]+[][[]])[+!+[]+[+[]]]+(![]+[])[!+[]+!+[]]+(!![]+[])[+[]]+(!![]+[])[!+[]+!+[]+!+[]]+(!![]+[])[+!+[]]])[+!+[]+[+!+[]]]+[!+[]+!+[]+!+[]+!+[]+!+[]+!+[]]+[!+[]+!+[]+!+[]+!+[]+!+[]+!+[]]+(+[![]]+[][(![]+[])[+[]]+([![]]+[][[]])[+!+[]+[+[]]]+(![]+[])[!+[]+!+[]]+(!![]+[])[+[]]+(!![]+[])[!+[]+!+[]+!+[]]+(!![]+[])[+!+[]]])[+!+[]+[+!+[]]]+[!+[]+!+[]+!+[]+!+[]+!+[]+!+[]]+([][(![]+[])[+[]]+([![]]+[][[]])[+!+[]+[+[]]]+(![]+[])[!+[]+!+[]]+(!![]+[])[+[]]+(!![]+[])[!+[]+!+[]+!+[]]+(!![]+[])[+!+[]]]+[])[!+[]+!+[]+!+[]]+(+[![]]+[][(![]+[])[+[]]+([![]]+[][[]])[+!+[]+[+[]]]+(![]+[])[!+[]+!+[]]+(!![]+[])[+[]]+(!![]+[])[!+[]+!+[]+!+[]]+(!![]+[])[+!+[]]])[+!+[]+[+!+[]]]+[!+[]+!+[]+!+[]+!+[]+!+[]+!+[]]+[+!+[]]+(+[![]]+[][(![]+[])[+[]]+([![]]+[][[]])[+!+[]+[+[]]]+(![]+[])[!+[]+!+[]]+(!![]+[])[+[]]+(!![]+[])[!+[]+!+[]+!+[]]+(!![]+[])[+!+[]]])[+!+[]+[+!+[]]]+[!+[]+!+[]+!+[]+!+[]+!+[]+!+[]]+[!+[]+!+[]+!+[]+!+[]+!+[]+!+[]+!+[]]+(+[![]]+[][(![]+[])[+[]]+([![]]+[][[]])[+!+[]+[+[]]]+(![]+[])[!+[]+!+[]]+(!![]+[])[+[]]+(!![]+[])[!+[]+!+[]+!+[]]+(!![]+[])[+!+[]]])[+!+[]+[+!+[]]]+[!+[]+!+[]]+[+[]]+(+[![]]+[][(![]+[])[+[]]+([![]]+[][[]])[+!+[]+[+[]]]+(![]+[])[!+[]+!+[]]+(!![]+[])[+[]]+(!![]+[])[!+[]+!+[]+!+[]]+(!![]+[])[+!+[]]])[+!+[]+[+!+[]]]+[!+[]+!+[]+!+[]+!+[]+!+[]+!+[]]+[!+[]+!+[]+!+[]+!+[]+!+[]+!+[]+!+[]+!+[]+!+[]]+(+[![]]+[][(![]+[])[+[]]+([![]]+[][[]])[+!+[]+[+[]]]+(![]+[])[!+[]+!+[]]+(!![]+[])[+[]]+(!![]+[])[!+[]+!+[]+!+[]]+(!![]+[])[+!+[]]])[+!+[]+[+!+[]]]+[!+[]+!+[]+!+[]+!+[]+!+[]+!+[]+!+[]]+[!+[]+!+[]+!+[]]+(+[![]]+[][(![]+[])[+[]]+([![]]+[][[]])[+!+[]+[+[]]]+(![]+[])[!+[]+!+[]]+(!![]+[])[+[]]+(!![]+[])[!+[]+!+[]+!+[]]+(!![]+[])[+!+[]]])[+!+[]+[+!+[]]]+[!+[]+!+[]]+[+[]]+(+[![]]+[][(![]+[])[+[]]+([![]]+[][[]])[+!+[]+[+[]]]+(![]+[])[!+[]+!+[]]+(!![]+[])[+[]]+(!![]+[])[!+[]+!+[]+!+[]]+(!![]+[])[+!+[]]])[+!+[]+[+!+[]]]+[!+[]+!+[]+!+[]]+[!+[]+!+[]+!+[]+!+[]+!+[]]+(+[![]]+[][(![]+[])[+[]]+([![]]+[][[]])[+!+[]+[+[]]]+(![]+[])[!+[]+!+[]]+(!![]+[])[+[]]+(!![]+[])[!+[]+!+[]+!+[]]+(!![]+[])[+!+[]]])[+!+[]+[+!+[]]]+[!+[]+!+[]+!+[]]+[+[]]+(+[![]]+[][(![]+[])[+[]]+([![]]+[][[]])[+!+[]+[+[]]]+(![]+[])[!+[]+!+[]]+(!![]+[])[+[]]+(!![]+[])[!+[]+!+[]+!+[]]+(!![]+[])[+!+[]]])[+!+[]+[+!+[]]]+[!+[]+!+[]+!+[]]+[!+[]+!+[]]+(+[![]]+[][(![]+[])[+[]]+([![]]+[][[]])[+!+[]+[+[]]]+(![]+[])[!+[]+!+[]]+(!![]+[])[+[]]+(!![]+[])[!+[]+!+[]+!+[]]+(!![]+[])[+!+[]]])[+!+[]+[+!+[]]]+[!+[]+!+[]]+[+[]]+(+[![]]+[][(![]+[])[+[]]+([![]]+[][[]])[+!+[]+[+[]]]+(![]+[])[!+[]+!+[]]+(!![]+[])[+[]]+(!![]+[])[!+[]+!+[]+!+[]]+(!![]+[])[+!+[]]])[+!+[]+[+!+[]]]+[!+[]+!+[]+!+[]+!+[]]+[!+[]+!+[]+!+[]+!+[]+!+[]]+(+[![]]+[][(![]+[])[+[]]+([![]]+[][[]])[+!+[]+[+[]]]+(![]+[])[!+[]+!+[]]+(!![]+[])[+[]]+(!![]+[])[!+[]+!+[]+!+[]]+(!![]+[])[+!+[]]])[+!+[]+[+!+[]]]+[!+[]+!+[]]+[+[]]+(+[![]]+[][(![]+[])[+[]]+([![]]+[][[]])[+!+[]+[+[]]]+(![]+[])[!+[]+!+[]]+(!![]+[])[+[]]+(!![]+[])[!+[]+!+[]+!+[]]+(!![]+[])[+!+[]]])[+!+[]+[+!+[]]]+[!+[]+!+[]+!+[]+!+[]]+[!+[]+!+[]]+(+[![]]+[][(![]+[])[+[]]+([![]]+[][[]])[+!+[]+[+[]]]+(![]+[])[!+[]+!+[]]+(!![]+[])[+[]]+(!![]+[])[!+[]+!+[]+!+[]]+(!![]+[])[+!+[]]])[+!+[]+[+!+[]]]+[!+[]+!+[]+!+[]+!+[]+!+[]+!+[]]+(![]+[])[+[]]+(+[![]]+[][(![]+[])[+[]]+([![]]+[][[]])[+!+[]+[+[]]]+(![]+[])[!+[]+!+[]]+(!![]+[])[+[]]+(!![]+[])[!+[]+!+[]+!+[]]+(!![]+[])[+!+[]]])[+!+[]+[+!+[]]]+[!+[]+!+[]+!+[]+!+[]+!+[]+!+[]]+(![]+[])[+[]]+(+[![]]+[][(![]+[])[+[]]+([![]]+[][[]])[+!+[]+[+[]]]+(![]+[])[!+[]+!+[]]+(!![]+[])[+[]]+(!![]+[])[!+[]+!+[]+!+[]]+(!![]+[])[+!+[]]])[+!+[]+[+!+[]]]+[!+[]+!+[]+!+[]+!+[]+!+[]+!+[]]+(!![]+[])[!+[]+!+[]+!+[]]+(+[![]]+[][(![]+[])[+[]]+([![]]+[][[]])[+!+[]+[+[]]]+(![]+[])[!+[]+!+[]]+(!![]+[])[+[]]+(!![]+[])[!+[]+!+[]+!+[]]+(!![]+[])[+!+[]]])[+!+[]+[+!+[]]]+[!+[]+!+[]+!+[]+!+[]+!+[]+!+[]]+[!+[]+!+[]+!+[]+!+[]+!+[]]+(+[![]]+[][(![]+[])[+[]]+([![]]+[][[]])[+!+[]+[+[]]]+(![]+[])[!+[]+!+[]]+(!![]+[])[+[]]+(!![]+[])[!+[]+!+[]+!+[]]+(!![]+[])[+!+[]]])[+!+[]+[+!+[]]]+[!+[]+!+[]]+[+[]]+(+[![]]+[][(![]+[])[+[]]+([![]]+[][[]])[+!+[]+[+[]]]+(![]+[])[!+[]+!+[]]+(!![]+[])[+[]]+(!![]+[])[!+[]+!+[]+!+[]]+(!![]+[])[+!+[]]])[+!+[]+[+!+[]]]+[!+[]+!+[]+!+[]+!+[]]+[+!+[]]+(+[![]]+[][(![]+[])[+[]]+([![]]+[][[]])[+!+[]+[+[]]]+(![]+[])[!+[]+!+[]]+(!![]+[])[+[]]+(!![]+[])[!+[]+!+[]+!+[]]+(!![]+[])[+!+[]]])[+!+[]+[+!+[]]]+[!+[]+!+[]+!+[]+!+[]+!+[]+!+[]+!+[]]+[!+[]+!+[]+!+[]+!+[]+!+[]+!+[]]+(+[![]]+[][(![]+[])[+[]]+([![]]+[][[]])[+!+[]+[+[]]]+(![]+[])[!+[]+!+[]]+(!![]+[])[+[]]+(!![]+[])[!+[]+!+[]+!+[]]+(!![]+[])[+!+[]]])[+!+[]+[+!+[]]]+[!+[]+!+[]+!+[]+!+[]+!+[]+!+[]]+[!+[]+!+[]+!+[]+!+[]+!+[]])()

-	Create a .txt file to hide in an image (chess.jpg). In the .txt file (secret.txt) copy and paste the script.

-	Using the terminal in Kali Linux, run steghide.
steghide --embed -ef secret.txt -cf chess.jpg -e none -Z
-ef is the path of the file to hide, -cf is the file that the data is embedded in, -e is the encryption, and -Z is
stating to not compress the file.

-	passphrase is history *all lowercase*b

-	The Secret.txt will now be hidden in the chess.jpg image.
