#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * flip_bits - returns the number of bits you would need to flip
 * to get from one number to another
 * @n: number
 * @m: number
 * Return: index
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int total = n ^ m;
	unsigned int index = 0;

	while (total)
	{
		index += total & 1;
		total >>= 1;
	}
	return (index);
}
