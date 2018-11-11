
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include "storer.c"

#define BUFFER_SIZE 2048
char *options(void){
	// char *login = malloc(sizeof(char) * strlen("Options on NAS:\n1. Upload a file\n2.Retrieve a file\n3.Execute limited OS command\n4.Logout\nOption: "));
	// strcpy(login, "Options on NAS:\n1. Upload a file\n2.Retrieve a file\n3.Execute limited OS command\n4.Logout\nOption: ");
	return "Options on NAS:\n1. Upload a file\n2.Retrieve a file\n3.Execute limited OS command\n4.Logout\nOption: ";
}

char *file_options(void){
	return "Options on NAS on retrevial of file:\n1. Overwrite File\n2. Return file\n3. Execute file";
}

// user login creditionals.
int user_login(char* name){
    strtok(name, "\n"); // Fixes bad directory names comparison
    int option = is_user(name);

	//if user is known
    if(option == 1){
        switch_location(name);
        return 1;
    } // if it's an illegal name
    else if(option == -1){
        return 0;
    }// if a new user
    else{
        create_storage(name);
        switch_location(name);
        return 1;
    }
}

int main()
{
	int fd = 0;
	char buff[BUFFER_SIZE];
	char nbuff[BUFFER_SIZE];

	//Setup Buffer Array
	memset(buff, '0',sizeof(buff));

	//Create Socket
	fd = socket(AF_INET, SOCK_STREAM, 0);
    	if(fd<0)
	{
		perror("Client Error: Socket not created succesfully");
		return 0;
	}

	//Structure to store details
	struct sockaddr_in server;
	memset(&server, '0', sizeof(server));

	//Initialize
	server.sin_family = AF_INET;
	server.sin_port = htons(10011);
    server.sin_addr.s_addr = htonl(INADDR_ANY);


	bind(fd, (struct sockaddr*)&server, sizeof(server));

	int in;
	listen(fd, 10);
	while(in = accept(fd, (struct sockaddr*)NULL, NULL))
	{
		int childpid,n;
		if ((childpid = fork ()) == 0 )
		{

            // send the initial login screen
			close (fd);
			char login_string[] = "NAS Service Login:\nIf this is your first time, then simply just continue with a unique name:  ";
			send(in, login_string, strlen(login_string), 0);
            bzero(nbuff,BUFFER_SIZE);

            //authentication check
            n = recv(in, nbuff, BUFFER_SIZE, 0);

            int login_val = user_login(nbuff);

            if(login_val == 0){
                send(in, "Illegal name", strlen("Illegal name"), 0);
                close(in);
                exit(0);
            }
            else{
				char* option_string = options();
				send(in, option_string, strlen(option_string), 0);
            }

			while ( (n = recv(in, buff, BUFFER_SIZE, 0)) > 0)
			{

				if(!strcmp(buff,"1")){ //upload a file
					bzero(buff, BUFFER_SIZE);

                    //receive the filename
					n = recv(in, buff, BUFFER_SIZE,0);
                    char filename[50];

                    strncpy(filename, buff, 50);
                    bzero(buff, BUFFER_SIZE);
					printf("Filename%s\n",filename );
					send(in, "acknowledge", 10, 0); // acknowledge file has been received.

                    // receive the file_info
                    n = recv(in, buff, BUFFER_SIZE, 0);
                    char file_info[1000];
                    strncpy(file_info, buff, BUFFER_SIZE);
                    bzero(buff,BUFFER_SIZE);
                    store_file(filename, file_info);
				}
				else if(!strcmp(buff,"2\n")){ // File Options
					bzero(buff, BUFFER_SIZE);
					send(in,"File Options:\n1. Execute file \n2. Get file\nOption: ",80, 0);

					n = recv(in, buff, 30,0);
					printf("Option: %s\n", buff);
					// Two Options: Execute a file or retrieve a file
					if(!strncmp(buff,"1",1)){

						// get response for the filename
						bzero(buff, BUFFER_SIZE);
						send(in,"Name of file to execute: ", 25,0);

						n = recv(in, buff, 30,0);
						char filename[50];
						strncpy(filename, buff, 50);

						printf("Filename: %s\n", filename);

					}
					else if(!strncmp(buff,"2",1)){
						// Send back the file...
						bzero(buff, BUFFER_SIZE);
						send(in,"Name of file to grab: ", 23,0);

						n = recv(in, buff, 30,0);
						char filename[50];
						strncpy(filename, buff, 50);

						printf("Filename: %s\n", filename);
					}
					else{
						printf("Buff: %s\n", buff);
					}

				}
				else if(!strcmp(buff,"3\n")){ //execute a command
					bzero(buff, BUFFER_SIZE);
					send(in,"3",1,0);
                    send(in,"List of Commands:\n1. ls\n2. file \n3. stat \n4. cat\nRun with {comand} filename Option: ", strlen("List of Commands:\n1. ls\n2. file \n3. stat \n4. cat\nRun with {comand} filename Option: "), 0);

                    n = recv(in, buff, 30,0); //get the OS command
                    char command[30];
                    strncpy(command, buff, 30);

					// execute the command and send the result back.
                    char* results = execute_command(command);
                    send(in, results, strlen(results), 0);
                    bzero(buff, BUFFER_SIZE);

				}
				else if(!strcmp(buff,"4\n")){ // quit
					send(in,"q",1,0);
				}
				else {
					char* option_string = options();
					send(in, option_string, strlen(option_string), 0);
				}

				bzero(buff, BUFFER_SIZE);
			}
			close(in);
			exit(0);
		}

	}
}
