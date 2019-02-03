The premise behind this is an open source Intelligence (OSINT) agent. Anybody can add or read information about a company in the system.

There are several files here:
- MessageStorer.py: The source code for the program
- connect.sh: Allows a user to connect to the service, given an IP address
- reset.sh: Reverts the MessageStorer.py file to its original form.
- shutdown.sh: Turns off the running version of the service.
- deploy.sh: Turns on the service


# Exploit 
When reading from a file, the path is actually not verified. So, running ../../../../../../../../../../../../etc/Services/ServiceA will give you the flag for the challenge. The classic directory traversal. 

# Mitigation: 
Disallow characters such as '.' and '/' to read and write output. 
