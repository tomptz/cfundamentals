#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char buffer[1000];

/*
 * int compare (const void* p1, const void* p2)
 *
 * Function to compare two ints using qsort
 *
 */
 
int compare (const void* p1, const void* p2)
{
	if (*(int *)p1<*(int *)p2)
		return -1;
	else if (*(int*)p1>*(int *)p2)
		return 1;
	else
		return 0;
}
	

/*
 * int getNumbers(const char* buffer, int* dest, int max)
 *
 * Function to parse a buffer read in by fgets
 *
 */

int getNumbers(const char* buffer, int* dest, int max)
{
	int amount_read=0;
	int total=0;
	int offset;
	
	while(amount_read<max)
	{
		if(sscanf(buffer+total, "%d%n", dest+amount_read, &offset)==EOF)
			break;

		amount_read++;
		buffer+=offset;
	}
			
	return amount_read;
      
}

int main(int argc, char *argv[])
{
	char buffer[1000];
	int numbers[100];
	int numbers_read;

	fgets(buffer, 1000, stdin);
    	
	numbers_read = getNumbers(buffer, numbers, 100);

	qsort(numbers, numbers_read, sizeof(int), compare);
 	
	for (int i=0; i<numbers_read; i++)
	{
		printf("%d\n", numbers[i]);
	}

}
