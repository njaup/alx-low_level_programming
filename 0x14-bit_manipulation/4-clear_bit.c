#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * clear_bit - function that sets the value of a bit
 * to 0 at a given index
 * @n: integer value
 * @index: this is the argument
 * Return: 1 if it worked, or -1 if an error occurred
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int binary = ~(1UL << index);

	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}

	*n &= binary;

	return (0);
}