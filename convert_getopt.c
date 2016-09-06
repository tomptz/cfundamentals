/*
 * Small program to test getopt
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

int main(int argc, char *argv[])
{

	char c;
	//opterr = 0; //Comment this to get error messages

	while ((c = getopt (argc, argv, "h:d:f:")) != -1)
	{
		switch(c)
		{
		case 'h':
			printf("%u\n", strtol(optarg, NULL, 16));
			break;

		case 'd':
			printf("0X%X\n", atoi(optarg));
			break;

		case '?':
			exit(EXIT_FAILURE);
			break;
		}

	}

}
