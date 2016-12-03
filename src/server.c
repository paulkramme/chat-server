#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

#define PERMS 0666


int main(int argc, char **argv)
{
	int logfile;
	char server_crash_not_received = "Server did not receive any packages, therefore return 1.";
	puts("Main chat server");
	puts("Server socket should start here...");
	logfile = open("chatserver.log", O_WRONLY | O_CREAT | O_APPEND, PERMS);
	write(logfile, "server startup\n", sizeof("server startup\n"));	
	char server_input[256];
	char server_read[256];
	int listen_fd;
	int comm_fd;
	struct sockaddr_in servaddr;
	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	memset(&servaddr, '\0', sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htons(INADDR_ANY);
	servaddr.sin_port = htons(8000);
	bind(listen_fd, (struct sockaddr *) &servaddr, sizeof(servaddr));
	listen(listen_fd, 10);
	comm_fd = accept(listen_fd, (struct sockaddr*) NULL, NULL);
	while(1)
	{
		server_input = "";
		memset(server_read, '\0', 256);
		if(read(comm_fd, server_read, 256) == -1)
		{
			write(logfile, server_crash_not_received, sizeof(server_crash_not_received));
			close(logfile);
			return 1;
		}
		if(strcmp(server_input, "/quit") == 0)
		{
			write(logfile, server_normal_shutdown, sizeof(server_normal_shutdown));
			close(logfile);
			return 0;
		}
		else
		{
			printf("MESSAGE: %s", server_input);
		}

	close(logfile);
	return 0;
}
