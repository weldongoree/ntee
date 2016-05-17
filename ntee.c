#include "ntee.h"

int main(int argc, char **argv) 
{
	FILE *pipehandle;
	struct timeval timeout;
	timeout.tv_sec=0;
	timeout.tv_usec=100;
	int read_in;
	
	pid_t pipereader;

	if ((pipereader = fork()) == -1)
	{
		perror("fork");
		return -1;
	}

	if (pipereader == 0) 
	{
	 	pipehandle=fopen("/tmp/ntee.pipe", "r");			
		int pipe_in;
		while ((pipe_in=fgetc(pipehandle)) != EOF)  
		{
			putchar(pipe_in); 		
		}				
		return 0;	
	}
	while ((read_in = getchar()) != EOF)
	{
		putchar(read_in);		
	}
	return 0;	
}

