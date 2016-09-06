#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libmemdmp.h"


int main(int argc, char *argv[])
{
	char test[50] = "Hallo";
	memdmp(test, 50);
}

