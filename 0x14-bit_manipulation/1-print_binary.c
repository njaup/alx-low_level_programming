#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_binary - prints the binary representation of a number
 * @n: number to be converted to binary and printed
 */
void print_binary(unsigned long int n)
{
	int bitpos;

	for (bitpos = 32; bitpos >= 0; bitpos--)
	{
		printf("%ld\n", (n >> bitpos) & 1);
	}
}
