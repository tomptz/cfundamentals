#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <getopt.h>

int main(int argc, char *argv[])
{

	char c;
	//opterr = 0;
	char* cvalue;
	while ((c = getopt (argc, argv, "h:d:f:")) != -1)
	{
		cvalue = NULL;

		printf("%c\n", c);

		switch(c)
		{
		case 'h':
			break;

		case '?':
			exit(EXIT_FAILURE);
			break;
		}

	}

}
