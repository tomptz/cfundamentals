/*
 * Copy memory from source to destination. Use memory dump utility to verify.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libmemdmp.h"


int main(int argc, char *argv[])
{

	char src[50] = "Source memory : let's try to copy this...";
	char dest[50] = "Destination memory before copy...";

	//Perform the copy
	for (int i=0; i<50; i++)
	{
		*(dest+i) = *(src+i);
	}

	printf("Source memory:\n");
	memdmp(src, 50);


	printf("Destination memory:\n");
	memdmp(dest, 50);



}
