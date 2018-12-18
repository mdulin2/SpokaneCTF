Challenges:
Attack/Defense:

- Access Control: (Trevor)
	- Admin page is available
	- Adding a user does not need authentication from admin.
	- Predictable cookies (session fixation)
	- Could either be a simple time-based mechanism that base-64 encoded or the md5 of the username?
- SQL Injection (Andrew)
	- Get the flag from the search bar?
	- Login as admin.
- Directory Traversal (Max)
	- Have an application where it is possible to store and see data that is ‘yours’. But, without proper input validation.
	- **Finished**
- Command Injection (Vanessa)
	- Basic PHP site that takes in an arbitrary users command to execute something bad on the system.
- Logic Question (Rodney)
	- In the 'logic' directory. 

Write Ups:
- For all of the vulnerabilities for the Wargames, an answer needs to be given, to one of the judges, on how to patch the vulnerabilities.

Wargame:
- Android Phone: (Max) **finished**
	- Connect to the phone through the ADB on port 5555.
	- Told about ADB, but that is it.
	- This is supposed to mimic the Android phone manufactures who left the debugger port open upon release.
	- Currently on a single phone, but this could be emulated.
- C-like issues: (Max) **finished**
	- Printf() vulnerability
- Buffer Overflows: (Max) **finished**
	- Redirecting the auth to a different memory address, to get the flag.
- XSS scripting: (Trevor)
	- Could this all be one website?
	- Basic functionality on error message
	- A stored XSS on some data on the site for an email list or something?
	- Bypassing with integrated HTML for an href for the color of a page?
	- Bypass built in security mechanisms for particular blog posting?

- Social Engineering: (Utsal)
	- Given a list of emails, point out the phishing emails.
        - Embedded URL
        - Phish from a phish from Grandma
        - ILoveYou phishing email 
        - Microsoft Word attachment
	- Guarding a box in the CS lounge. Points for getting the box!
		- Could just put a flag value in the box for them to use.
- Crypto (Max)
	- Keyboard cipher!
		- Alternating from right to left.
			-Maxwell Dulin would be ,CQRK; FY;UM
		- Break the Cesar Cipher for text
	- Given a very small public RSA key; break this…
		- **finished**
	- Huffman encoding problem.
		- **finished**
- Math Number Theory Problems (Max) **finished**:
	- RSA cracking key: amount of division operations needed. 
	- Combinations are tiles on a floor
	- Amount of possible passwords
- Race condition (Max and Rodney): **finished**
- Packet Fun (Rodney/RJ):
	- Website has had some network traffic stolen… See if this pcap packet can help you at all.
- Steganography (Juan)
	- Blank Canvas: Given an image with a white background. Find the flag hidden in the image.
	- Rubik's Cube: Given an image of a rubiks cube. A text file is hidden in the rubiks cube image using the HideSeek algorithm. Find the text file that has the flag.
	- Missing Piece: Given an image of a puzzle with a missing piece. An audio file is hidden in the image using the BlindHide algorithm. Analyze the audio file and discover the hidden message inside the audio.
- Having a “I’m in” hacker moment video setup

Categories:
- Software
- Crypto
- Logging
- Social Engineering
- Miscellaneous




Totally open for new ideas. What does everyone think? Feel free to add a challenge idea!
