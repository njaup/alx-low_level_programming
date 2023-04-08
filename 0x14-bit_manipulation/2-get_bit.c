#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * get_bit - returns the value of a bit at a given index
 * @n: integer value
 * @i: index
 * Return: the value of the bit at index index
 * or -1 if an error occured
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int bit = n >> i;

	if (bit & 1)
	{
		return (1);
	}
	return (0);
}

int main()
{
	unsigned long int n = 218;
	unsigned int i = 3;

	int binary = get_bit(n, i);
	printf("Binary %u of %lu is %d", i, n, binary);
	printf("\n");

	return (0);
}
