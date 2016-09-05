/*
 * palindrome.c
 *
 * This program tests whether a sentence provided as a command-line argument is a palindrome
 * The program is case insensitive and removes spaces and unwanted tokens
 * For example, test with
 * 		./palindrome sos"!"sos"-"sos soS
 * 		./palindrome If I had a Hi-Fi
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void read_input_string(int argc, char * argv[], char ** dest);
void remove_tokens(const char * src, char * dest, const char excluded_tokens[]);



int main(int argc, char *argv[])
{
	//Illegal tokens to exclude
	const char excluded_tokens [] = "!,- ";

	//Do some input checking
	if (argc == 1)
	{
		printf("Error: no arguments provided.\n");
		exit(EXIT_FAILURE);
	}


	//Read the input string that has to be checked
	char* input_string;
	read_input_string(argc, argv, &input_string);

	//Remove illegal tokens
	char final_string[strlen(input_string)];
	remove_tokens(input_string, final_string, excluded_tokens);

	//Do the palindrome detection
	char is_palindrome = 1;
	for(int delta=0; delta<strlen(final_string)/2; delta++)
	{
		if(toupper(final_string[delta]) != toupper(final_string[strlen(final_string)-1-delta]))
		{
			is_palindrome = 0;
			break;
		}
	}


	//Print the result
	printf("The string \"%s\" ", final_string);
	if (is_palindrome == 1)
		printf("is a palindrome.\n");
	else
		printf("is NOT a palindrome.\n");

	//Free the allocated memory
	free(input_string);

}


/*
 * read_input_string
 *
 * Creates one string by concatenating all strings provided as command-line arguments.
 * This also removes the spaces between the words.
 * This function allocates the required memory to store the concatenated string
 *
 */
void read_input_string(int argc, char * argv[], char ** dest)
{
	int req_length = 0;
	for(int i=1; i<argc; i++)
		req_length += strlen(argv[i]);

	*dest = (char*) malloc(req_length+1); //Don't forget one byte for null terminating char

	strncpy(*dest, argv[1], req_length);

	for(int i=2; i<argc; i++)
		strcat(*dest, argv[i]);
}

/*
 *  remove_tokens
 *
 *  Removes all illegal tokens from the input
 *
 */


void remove_tokens(const char * src, char * dest, const char excluded_tokens[])
{
	while(*src != 0)
	{
		if ( strchr(excluded_tokens, *src) == NULL )
		{
			*dest = *src;
			dest++;
		}
		src++;
	}
	*dest=0;
}



