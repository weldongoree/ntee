#include "ntee.h"
FILE *get_stream(char *path)
{
	
}

int main(int argc, char **argv) 
{
	FILE *pipehandle;
	struct timeval timeout;
	timeout.tv_sec=0;
	timeout.tv_usec=100;
	int read_in, i;
	
	pid_t pipereader;
	for (i = 1; i < argc; i++)
	{
		if ((pipereader = fork()) == -1)
		{
			perror("fork");
			return -1;
		}

		if (pipereader == 0) 
		{
	 		pipehandle=fopen(argv[i], "r");			
			int pipe_in;
			while (pipe_in=fgetc(pipehandle))  
			{
				if (pipe_in != EOF)
				{
					putchar(pipe_in); 		
				}
			}				
		}
	}
	while ((read_in = getchar()) != EOF)
	{
		putchar(read_in);		
	}
	return 0;	
}

