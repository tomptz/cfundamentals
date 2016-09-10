/*
 * Program using qsort to sort numbers
 *
 * Uses dynamic memory allocation + checks for malloc failure
 *
 */

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


int main(int argc, char *argv[])
{
	int* numbers;
	int numbers_to_read;

	fscanf(stdin, "%d", &numbers_to_read);

	numbers = malloc(numbers_to_read*sizeof(int));

	if (numbers == NULL)
	{
		printf("Error: malloc failed.\n");
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < numbers_to_read; ++i) {
		fscanf(stdin, "%d", numbers+i);
	}

	qsort(numbers, numbers_to_read, sizeof(int), compare);

	for (int i = 0; i < numbers_to_read; ++i) {
		printf("%d\n", numbers[i]);
	}




	//
	//
	//	fgets(buffer, 1000, stdin);
	//	numbers_read = getNumbers(buffer, numbers, 100);
	//
	//	qsort(numbers, numbers_read, sizeof(int), compare);
	//
	//	for (int i=0; i<numbers_read; i++)
	//	{
	//		printf("%d\n", numbers[i]);
	//	}
	//


}
