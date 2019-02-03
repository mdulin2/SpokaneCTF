# Challenges

## Installation: 

Use https://github.com/volatilityfoundation/volatility/wiki/Installation for instructions on how to install. Once the repo is cloned then simply just call python vol.py -f file_name.
## Malicious File
The image that will be used is at https://www.dropbox.com/s/6uln8t53r4oj3fp/capdflag.vmem?dl=0. Download this for the challenge.

## Questions: 
There are 6 questions associated with these forensics problems. 

1. What Windows OS is running on the system where the memory capture was taken from? 
2. What is the IP address of the external **connection** from the memory image?
3. What is the Process Name associated with the remote IP address?
	- Hint: Looking for process ids will help here. 
4. What is the child process of the Process associated with the external connection?
	- Hint: PPID stands for process id
5. What type of file is Explorer.exe and reader_sl.exe? 
	- Hint: Use the procdump command in order to get the files. 
6. What Result does Windows defender give for the Explorer.exe? The answer is the amount of unsafe votes given from the community. 
	- Hint: Use https://www.virustotal.com for this.  

### Tips: 
Use https://github.com/volatilityfoundation/volatility/wiki/Command-Reference for reference on commands. Simply just searching the page for keywords like 'connections' and other things is really helpful.
