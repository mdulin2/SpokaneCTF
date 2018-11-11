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

- Social Engineering:
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
- Math Number Theory Problems (Trevor)
	- If I have a license plate, with numbers and letter in English that must be 7 characters, how many possibilities are there?
 		- 36^7
	- Same question but can be 1 through 7 characters
		- 36 + 36^2+36^3+36^4+36^5+36^6+36^7
	- Could have a few more questions.
- Race condition (?):
	- Not sure what to do about this one…
- Packet Fun (Rodney)
	- Website has had some network traffic stolen… See if this pcap packet can help you at all.
- Steganography (Juan)
- Breaking hashes (Spokane Falls)
- Having a “I’m in” hacker moment video setup

Categories:
- Software
- Crypto
- Logging
- Social Engineering
- Miscellaneous




Totally open for new ideas. What does everyone think? Feel free to add a challenge idea!
