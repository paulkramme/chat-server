#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

#define PERMS 0666


int main(int argc, char **argv)
{
	int logfile;
	puts("Main chat server");
	puts("Server socket should start here...");
	logfile = open("chatserver.log", O_WRONLY | O_CREAT | O_APPEND, PERMS);
	write(logfile, "server startup\n", sizeof("server startup\n"));	


	close(logfile);
	return 0;
}
