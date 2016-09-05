/*
 * Hexadecimal to int converter
 *
 * Test using :
 * 	./hex2int B9644B 0xFF
 * 		should result in
 * 			12149835
 *			255
 *
 * ./hex2int B96X44B
 * 		should result in illegal input error message
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int convert_char(const char hex_char);

int main(int argc, char *argv[])
{

	//Do some input checking
	if (argc == 1)
	{
		printf("Error: no arguments provided.\n");
		exit(EXIT_FAILURE);
	}


	for(int i=1; i<argc; i++) //Cycle through all the strings provided as arguments
	{

		char* hexstring = argv[i]; //Current hexstringb
		int start_index; //Index of first relevant digit after prefix

		//Detect hex prefix, eliminate case sensitivity
		if (strlen(hexstring)>2 && hexstring[0] == '0' && toupper(hexstring[1]) == 'X')
			start_index = 2;
		else
			start_index = 0;

		//Do the conversion of the current hexstring
		int result = 0;
		for(int j = start_index; j<strlen(hexstring) ; j++)
		{
			result = result << 4; //At each new iteration, shift temporary result 4 bit
			result = result + convert_char(hexstring[j]); //Add next least significant number
		}

		//Print the results
		printf("%d\n", result);

	}

}

/*
 * convert_char
 *
 * Converts a single hex char to int using the ASCII table.
 * Also detects illegal chars
 *
 */
int convert_char(const char hex_char)
{
	char upper_hex_char = toupper(hex_char);

	if (upper_hex_char > 64 && upper_hex_char < 71)
	{
		return (int) upper_hex_char - 55;
	}
	else if (upper_hex_char > 47 &&  upper_hex_char < 58)
	{
		return (int) upper_hex_char - 48;
	}
	else
	{
		printf("Error : illegal input.\n");
		exit(EXIT_FAILURE);
	}
}

