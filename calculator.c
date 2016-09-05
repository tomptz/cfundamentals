/*
 * Exercise 2.1 and 2.2
 *
 * The calculator supports integers, floats, octal (start with 0) and hex (start with 0x) numbers, as well as bitwise operators
 *
 * Test with
 * 		./calculator "*" 1 2 3 010 -0.5 0.25 -0.25
 * 			This should output 1.5
 *
 * 		./calculator ">" 0x10 1
 * 			This should output 8
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


float get_number(char*argv[], int index);

int main(int argc, char *argv[])
{
	//Check for arguments
	if (argc < 2)
	{
		printf("Error : no arguments provided!\n");
		exit(EXIT_FAILURE);
	}

	//Check for operator string size
	if (strlen(argv[1]) > 1)
	{
		printf("Error : invalid operator!\n");
	}

	//Check whether operands are provided
	if (argc < 4)
	{
		printf("Error : insufficient amount of operands provided!\n");
		exit(EXIT_FAILURE);
	}


	float next_number; //var to hold next number
	float result; //var to hold result
	char operator; //char to hold operator

	//Read first operand
	result = get_number(argv, 0);

	//Cycle through the other operands and apply operation
	for (int i = 1; i<argc-2; i++)
	{
		next_number = get_number(argv, i);
		operator = argv[1][0];

		switch (operator)
		{
		case '+':
			result += next_number;
			break;

		case '-':
			result -= next_number;
			break;

		case '/':
			result /= next_number;
			break;

		case '*':
			result *= next_number;
			break;

		case '%':
			result = (int) result % (int) next_number;
			break;

		case '<':
			result = (int) result << (int) next_number;
			break;

		case '>':
			result = (int) result >> (int) next_number;
			break;

		default:
			printf("Error : unknown operator!\n");
			exit(EXIT_FAILURE);


		}

	}
	printf("%f\n", result);


}

/*
 * get_number
 *
 * Interprets a number string from the arg array as an octal number (if it starts with 0 and doesn't have a decimal point or x char) or as a float.
 * The atof function automatically recognizes and converts hex numbers.
 *
 */


float get_number(char* argv[], int index)
{

	float next_number;
	char* next_number_string = argv[index+2];

	if( next_number_string[0] == '0' && next_number_string[1] != '.' && toupper(next_number_string[1]) != 'X' ) //Octal if not decimal or hex
	{
		next_number = strtol(next_number_string, NULL, 8); //Use base 8
	}
	else
	{
		next_number = atof(next_number_string); //Alpha to float
	}

	return next_number;
}
