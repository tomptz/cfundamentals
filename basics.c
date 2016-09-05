#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	printf("Hello Tass!\n");
	printf(argv[0]);
	printf("\n");

	for (int i = 0; i<argc; i++)
	{
		printf("%s\n",argv[i]);
	}

	for (int i = 1; i<argc; i++)
	{
		printf("%s\n",argv[i]);
	}

	for (int i = argc-1; i>0; i--)
	{
		printf("%s\n",argv[i]);
	}

	return 0;
}
