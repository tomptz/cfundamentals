#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void memdmp(char* start, int count);


int main(int argc, char *argv[])
{
	char test[50] = "Hallo";
	memdmp(test, 50);
}


/*
 * void memdmp(char* start, int count)
 *
 * Dumps the content of memory in both hex and ASCII
 *
 * start : start pointer to first byte
 * count : number of bytes to dump
 *
 */

void memdmp(char* start, int count)
{
	printf("         ");

	for(int col = 0; col<16; col++)
	{
		printf("%02X ", col);
	}

	printf("\n");
	printf("         ");

	for(int col = 0; col<16; col++)
	{
		printf("---", col);
	}


	printf("\n");

	int current = 0;
	while(current<count)
	{
		printf("0x%04X | ", current);

		for(int col = 0; col<16; col++)
		{
			if(current<count)
				printf("%02X ", *(start+current));
			else
				printf("   ");

			current++;

		}

		current -= 16; //Reset current mem pointer

		printf(" | ");

		for(int col = 0; col<16; col++)
		{
			char current_char = *(start+current);

			if (current_char > 47  && current_char < 122)
				printf("%c", current_char);
			else
				printf(".");

			current++;

			if(current>=count)
				break;

		}

		printf("\n");

	}

}
