#include "ntee.h"

int main(int argc, char **argv) {
	FILE *outfile;
	int readin;
 	if (access(argv[1], W_OK) == -1)
	{
		perror("Can't write to file");
		return -1;
	} 
	outfile = fopen(argv[1], "w");
	while ((readin=getchar()) != EOF)
	{
		putc(readin, outfile);
		fflush(outfile);
	}
	fclose(outfile);
	return 0;
}
