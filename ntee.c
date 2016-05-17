#include "ntee.h"

int main(int argc, char **argv) {
	char *command = argv[1];
	char *pipepath = "/tmp/ntee.pipe";
	int pipehandle;
	pipehandle=mkfifo(pipepath, 0600);
	int fd[2];
	pid_t command_pid;
	pipe(fd);
	if ((command_pid = fork()) == -1)
	{
		perror("fork"); 		
		return -1;
	}	
	if (command_pid == 0)
	{
		close(0);	
		if (dup(fd[0]) == -1) 
		{
			perror("dup");
			return -1;
		}
	 	if (execlp(command, command, NULL));	
	 	{
			perror("execlp");
			return -1;
		}		
	} else {
		close(1);
		if (dup(fd[1]) == -1) 
		{
			perror("dup parent");
			return -1;
		}
		printf("(+ 1 2 3)\n");
		fflush(NULL);
  		sleep(5);
		return 0;	
	}	
}

