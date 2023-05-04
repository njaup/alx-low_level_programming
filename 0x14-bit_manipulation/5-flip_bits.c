#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * flip_bits - number of bits you would need to flip
 * to get from one number to another.
 * @n: integer 1
 * @m: integer 2
 * Return: bits
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int total = n ^ m;
	unsigned int byts = 0;

	while (total != 0)
	{
		byts += total & 1;
		total >>= 1;
	}
	return (byts);
}
