# Race Conditions

Currently, there are two race conditions in here: POC.c and challenge.c.

# POC.c:
A proof of concept to see if we can pull off this race condition in a challenge. This was written by Rodney and Max. The challenge uses a text file to perform a TOCTOU(time of check vs time of use) bug. Will not be in the CTF.

# challenge.c:
The program uses multithreading to check if a number is prime or not. However, because the VALUE is not locked, then the amount of time that the prime checker takes is enough to change the value of VALUE in the input section. So, this creates a race condition that can be exploited within the pthread_slave function.

# Exploit:
- First, insert a very, very large prime number. Because this is multithreaded, it will just run in the background. Now, put in an easy to compute number(such as 1,2,3,4...). Because the first thread is still running, yet the execution has continued, a race condition has occurred now. Because the race condition has occurred, a flag will be displayed.
