This will be an attack/defense problem, likely.
So, we will need a simple deploy and connect script for this.

The premise behind this is an open source Intelligence (OSINT) agent. Anybody can add or read information about a company in the system.

There are several files here:
- MessageStorer.py: The source code for the program
- connect.sh: Allows a user to connect to the service, given an IP address
- reset.sh: Reverts the MessageStorer.py file to its original form.
- shutdown.sh: Turns off the running version of the service.
- deploy.sh: Turns on the service
