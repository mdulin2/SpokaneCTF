
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

char* upload_file(char* filename){
	strtok(filename, "\n"); //removes newlines
	if( access( filename, F_OK ) == -1 ) { // invalid filename
		printf("%s\n", "here?");
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

// int main(int argc, char *argv[]){
// 	char* file_contents = upload_file("doom");
// 	printf("%s",file_contents);
// }


int main(int argc, char *argv[])
{
	int fd = 0;
	char outbuff[1024];
	char inbuff[1024];

	if(argc<3)
	{
		printf("Less no of arguments !!");
		return 0;
	}

	//Setup Buffer Array
	memset(inbuff, '0',sizeof(inbuff));
	memset(outbuff, '0',sizeof(outbuff));

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
	server.sin_port =  htons(atoi(argv[2]));

	int in = inet_pton(AF_INET, argv[1], &server.sin_addr);
	if(in<0)
	{
		perror("Client Error: IP not initialized succesfully");
		return 0;
	}

	//Connect to given server
	in = connect(fd, (struct sockaddr *)&server, sizeof(server));
	if(in<0)
	{
		perror("Client Error: Connection Failed.");
		return 0;
	}

	// auth protocol
	in = recv(fd,inbuff,255,0);
	printf("%s", inbuff);

	fgets(outbuff,255,stdin);
	in = send(fd,outbuff,strlen(outbuff),0);

	bzero(inbuff,256);

	while(1)
	{

	    if (in < 0)
	    {
		 	perror("\nClient Error: Writing to Server");
	    	return 0;
	    }

		// Now read server response
	    in = recv(fd,inbuff,255,0);
	    if (in < 0)
	    {
		 	perror("\nClient Error: Reading from Server");
			return 0;
	    }

		// Get usual output from the server and get user response.
		printf("%s", inbuff);
		bzero(outbuff,256);
		fgets(outbuff,255,stdin);
		printf("outbuff%s\n", outbuff);

		if(outbuff[0] == '1'){ // Upload a file

			send(fd, "1", 1, 0); // send the server the option
			printf("%s","Name of file: ");
			char filename[256];
			fgets(filename,255,stdin);
			strtok(filename, "\n");
			printf("File....%s\n", filename );
			send(fd, filename, strlen(filename), 0);
			char* file_contents = upload_file(filename);


			in = recv(fd,inbuff,255,0); // acknowledge
			send(fd, file_contents, strlen(file_contents), 0);
		}
		else if(outbuff[0] == '2'){ // Retrieve a file

		}
		else if(outbuff[0] == '3'){ // run limited OS commands

		}
		// if(!strcmp(inbuff,"1")){
		//
		// 	// Get the file info
		// 	printf("%s","Name of file: ");
		// 	char filename[256];
		// 	fgets(filename,255,stdin);
		// 	strtok(filename, "\n");
		// 	char* file_contents = upload_file(filename);
		//
		// 	// send both the filename and the file_info
		// 	send(fd, filename, strlen(filename), 0);
		// 	send(fd, file_contents, strlen(file_contents), 0);
		//
		// }
		// else if(inbuff[0] == '2'){
		// 	bzero(inbuff,256);
		// 	in = recv(fd,inbuff,256,0);
		// 	printf("%s\n", inbuff); // Type of file usage from server
		//
		// 	fgets(outbuff, 256, stdin);
		// 	if(!strcmp(outbuff,"1\n")){
		// 		// send initial usage
		// 		bzero(inbuff,256);
		// 		in = recv(fd,inbuff, 256, 0);
		// 		// send the filename
		// 		bzero(outbuff, 256);
		// 		fgets(outbuff, 256, stdin);
		// 		send(fd, outbuff, strlen(outbuff), 0);
		// 	}
		// 	else if(!strcmp(outbuff,"2")){
		// 		// send initial usage
		// 		bzero(inbuff,256);
		// 		in = recv(fd,inbuff,256,0);
		// 		printf("%s", inbuff);
		// 	}
		// 	else{
		// 		printf("Wrong!%s\n", "");
		// 	}
		// }
		// else if(!strcmp(inbuff,"3")){
		// 	// Will send the command back to the server, to be executed.
		//
		// 	bzero(inbuff,256);
		// 	in = recv(fd,inbuff,255,0);
		// 	printf("%s\n", inbuff);
		// 	bzero(inbuff,256);
		//
		// 	// Getting the user OS command to the NAS
		// 	fgets(outbuff,255,stdin);
		// 	send(fd, outbuff, 10, 0);
		// 	bzero(outbuff,256);
		//
		// 	in = recv(fd,inbuff,255,0);
		//
		// 	bzero(inbuff,256);
		// }
		// else if(!strcmp(inbuff,"q")){
		// 	close(fd);
		// 	exit(0);
		// }
		// else if(!strcmp(inbuff,"0")){
		// 	//nothing
		// }
		// else{
		// 	printf("%s", inbuff);
		// }

	}
	close(fd);
	return 0;
}
