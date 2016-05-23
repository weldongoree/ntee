#include "ntee.h"
	
int main(int argc, char **argv) 
{
	
	struct pollfd input_fds[argc];
	int i;
 	char read_buff[64];	
	input_fds[0].fd = 0; /* stdin */
	input_fds[0].events = POLLIN | POLLRDNORM | POLLRDBAND | POLLPRI;
	input_fds[0].revents = 0;
	ssize_t readcount;
	for (i = 1; i < argc; i++)
	{
		if (access(argv[i], F_OK) == -1)
		{
			mkfifo(argv[i], 0600);
		}
		input_fds[i].fd = open(argv[i], O_RDONLY);
		input_fds[i].events = POLLIN | POLLRDNORM | POLLRDBAND | POLLPRI;
		input_fds[i].revents = 0;
	}
        while (1)
	{
		poll(input_fds, argc, 0);
		for (i = 0; i < argc; i++)
		{
			if (input_fds[i].revents & POLLRDNORM)
			{
				readcount=read(input_fds[i].fd, &read_buff, 64);
				if (readcount > 0)
				{
					write(1, read_buff, readcount);
				}
			}
		}
	}				
	return 0;	
}

