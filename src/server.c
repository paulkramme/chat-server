#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

#define PERMS 0666


int main(int argc, char **argv)
{
	int logfile;
	puts("Main chat server");
	puts("Server socket should start here...");
	logfile = open("chatserver.log", O_WRONLY | O_CREAT | O_APPEND, PERMS);

	close(logfile);
	return 0;
}
