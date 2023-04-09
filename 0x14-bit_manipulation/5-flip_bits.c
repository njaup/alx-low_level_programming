#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * flip_bits - function that returns the number of bits
 * you would need to flip to get from one number to another
 * @n: value of integer 1
 * @m: value of integer 2
 * Return: count of bit flips
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int sum = n ^ m;
	unsigned int i = 0;

	while (sum != 0)
	{
		if (sum & 1)
		{
			i++;
		}
		sum >>= 1;
	}
	return (i);
}
