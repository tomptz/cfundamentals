all : basics calculator palindrome

basics : basics.c
	gcc -o basics basics.c

calculator: calculator.c
	gcc -o calculator calculator.c
	
palindrome: palindrome.c
	gcc -o palindrome palindrome.c	