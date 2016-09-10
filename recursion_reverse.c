/*
 * recursion_reverse.c
 *
 *  Created on: Sep 10, 2016
 *      Author: tomp
 */

#include<stdlib.h>
#include <stdio.h>

void reverse(const char* stringToReverse);

int main(int argc, char*argv[])
{
	for (int arg = 1; arg < argc; ++arg) {
		reverse(argv[arg]);
		printf(" ");
	}

}

void reverse(const char* stringToReverse)
{
	if (*stringToReverse != '\0')
	{
		reverse(stringToReverse+1);
		printf("%c", *(stringToReverse));
	}
}
