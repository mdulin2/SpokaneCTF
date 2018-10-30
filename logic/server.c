
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include "storer.c"

char *options(void){
	char *login = malloc(sizeof(char) * strlen("Options on NAS:\n1. Upload a file\n2.Retrieve a file\n3.Execute limited OS command\n4.Logout\nOption: "));
	strcpy(login, "Options on NAS:\n1. Upload a file\n2.Retrieve a file\n3.Execute limited OS command\n4.Logout\nOption: ");
	return login;
}

char *file_options(void){
	char *login = malloc(sizeof(char) * strlen("Options on NAS on retrevial of file:\n1. Overwrite File\n2. Return file\n3. Execute file"));
	strcpy(login, "Options on NAS on retrevial of file:\n1. Overwrite File\n2. Return file\n3. Execute file");
	return login;
}

int user_login(char* name){
    strtok(name, "\n"); // Need to fix bad directory names
    int option = is_user(name);

    if(option == 1){
        switch_location(name);
        return 1;
    }
    else if(option == -1){
        return 0;
    }
    else{
        create_storage(name);
        switch_location(name);
        return 1;
    }
}

int main()
{
	int fd = 0;
	char buff[1024];
	char nbuff[1024];

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
			send(in, "NAS Service Login:\nIf this is your first time, then simply just continue with a unique name:  \0", strlen(login_string), 0);
            bzero(nbuff,256);

            //authentication check
            n = recv(in, nbuff, 256,0);
            printf("%s\n", nbuff);
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

			while ( (n = recv(in, buff, 256,0)) > 0)
			{
				if(!strcmp(buff,"1\n")){ //upload a file
					bzero(buff,256);
					send(in,"1",2,0);

                    //receive the filename
					n = recv(in, buff, 256,0);
                    char filename[50];
                    strcpy(filename, buff);
                    bzero(buff,256);

                    // receive the file_info
                    n = recv(in, buff, 1000,0);
                    char file_info[1000];
                    strcpy(file_info, buff);
                    bzero(buff,256);

                    store_file(filename, file_info);
				}
				else if(!strcmp(buff,"2\n")){ // File Options
					send(in,"2",2,0);
				}
				else if(!strcmp(buff,"3\n")){ //execute a command
					send(in,"3",2,0);
				}
				else if(!strcmp(buff,"4\n")){ // quit
					send(in,"q",2,0);
				}
				else {
					char* option_string = options();
					send(in, option_string, strlen(option_string), 0);
				}

				bzero(buff,256);
			}
			close(in);
			exit(0);
		}

	}
}
