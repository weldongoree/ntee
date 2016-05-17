#include "ntee.h"

int main(int argc, char **argv) {
	FILE *outfile;
	int c;
	outfile=fopen("/tmp/ntee.pipe", "w");

	while ((c = getchar()) != EOF)
	{
		putc(c, outfile);
	}
	fclose(outfile);
	return 0;
}
