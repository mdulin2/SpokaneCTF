Challenges:
Attack/Defense:

- Access Control:
	- Admin page is available
	- Adding a user does not need authentication from admin.
	- Predictable cookies (session fixation)
	- Could either be a simple time-based mechanism that base-64 encoded or the md5 of the username?
- SQL Injection:
	- Get the flag from the search bar?
	- Login as admin.
	- Set up a firewall, banning some keywords.
- Directory Traversal:
	- Have an application where it is possible to store and see data that is ‘yours’. But, without proper input validation.
	- **Finished**
- Command Injection:
	- Basic PHP site that takes in an arbitrary users command to execute something bad on the system.
- Logic Question:
	- Not sure what to do about this one…

Write Ups:
- For all of the vulnerabilities for the Wargames, an answer needs to be given, to one of the judges, on how to patch the vulnerabilities.

Wargame:
- Android Phone:
	- Connect to the phone through the ADB on port 5555.
	- Told about ADB, but that is it.
	- This is supposed to mimic the Android phone manufactures who left the debugger port open upon release.
- C-like issues: **finished**
	- Printf() vulnerability
- XSS scripting:
	- Could this all be one website?
	- Basic functionality on error message
	- How to grade this automatically…Could have judges for this too?
	- A stored XSS on some data on the site for an email list or something?
	- Bypassing with integrated HTML for an href for the color of a page?
	- Bypass built in security mechanisms for particular blog posting? Find a way to bypass the filter.
- Buffer Overflows:
	- Redirecting the auth to a different memory address
	- Getting a shell on machine
- Social Engineering:
	- Go around campus to learn information about people.
	- Want to learn?
		- Home town, dorm, pet names, computer type, Operating System, zagid…
	- Need to have a professional write up for this.
	- Bot for receiving emails
- Crypto:
	- Keyboard cipher!
		- Alternating from right to left.
			-Maxwell Dulin would be ,CQRK; FY;UM
		- Break the Cesar Cipher for text
	- Given a very small public RSA key; break this…
		- **finished**
	- Huffman encoding problem.
		- **finished**
	- Breaking hashes
- Math Number Theory Problems:
	- If I have a license plate, with numbers and letter in English that must be 7 characters, how many possibilities are there?
 		- 36^7
	- Same question but can be 1 through 7 characters
		- 36 + 36^2+36^3+36^4+36^5+36^6+36^7
	- Could have a few more questions.
- Hacker history trivia?
- Race condition
	- Not sure what to do about this one…
- Packet Fun:
	- Website has had some network traffic stolen… See if this pcap packet can help you at all.
	- Rodney!
- Finding passwords from a thumb drive image:
	- No idea how to do this…
- Poor input validation?
- Having a “I’m in” hacker moment video





Totally open for new ideas. What does everyone think? Feel free to add a challenge idea!