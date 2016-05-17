#include "ntee.h"

int main(int argc, char **argv) {
	int out_fd;
	char[8] buf;
	int readcount;
 	if (access(argv[1], W_OK) == -1)
	{
		perror("Can't write to specified socket");
	} 
	
	while (1)
	{
		putc(c, outfile);
	}
	fclose(outfile);
	return 0;
}
