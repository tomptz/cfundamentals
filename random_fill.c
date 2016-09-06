#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void print_array(const int* array, const int size)
{
	int col = 0;
	for(int i=0; i<size; i++)
	{
		col++;
		printf("%4d ", array[i]);

		if (col == 20)
		{
			printf("\n");
			col = 0;
		}
	}
	printf("\n");
}

int main(int argc, char *argv[])
{
	const int size = 20;
	int random_array[size];
	time_t t;
	srand((unsigned) time(&t));

	for(int i=0; i<size; i++)
	{
		random_array[i] = rand() % 20;
	}


	printf("Original array:\n");
	print_array(random_array, size);


	int unique_number_counter = 0;
	int max_uniques = 10;
	int * unique_numbers = malloc(sizeof(int)*max_uniques);
	int current_number;

	for(int i=0; i<size; i++)
	{
		current_number = random_array[i];

		char found = 0;
		for(int j=0; j<unique_number_counter; j++)
		{
			if (unique_numbers[j]==current_number)
			{
				found = 1;
				break;
			}
		}

		if (found == 0)
		{
			if (unique_number_counter == max_uniques)
			{
				max_uniques *= 2;
				unique_numbers = realloc(unique_numbers, sizeof(int)*max_uniques);
			}

			printf("Number %2d first found at position %d.\n",current_number, i);
			unique_numbers[unique_number_counter] = current_number;

			unique_number_counter++;

		}
		else
		{
			printf("Number %2d again found at position %d.\n",current_number, i);


		}

	}

	printf("\n");
    printf("Array with duplicates removed:\n");
	print_array(unique_numbers, unique_number_counter);


	free(unique_numbers);







}
