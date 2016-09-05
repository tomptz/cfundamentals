#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

	//Basic hello world
	printf("Hello Tass!\n");

	//Program name
	printf("%s\n", argv[0]);

	//Print all args
	for (int i = 0; i<argc; i++)
	{
		printf("%s\n",argv[i]);
	}

	//Print all args except program name
	for (int i = 1; i<argc; i++)
	{
		printf("%s\n",argv[i]);
	}

	//Print all args in reverse order, except program name
	for (int i = argc-1; i>0; i--)
	{
		printf("%s\n",argv[i]);
	}

	return 0;
}
