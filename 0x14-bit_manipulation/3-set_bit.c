#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * set_bit - function that sets the value of a bit
 * to 1 at a given index
 * @n: integer value
 * @index: the input
 * Return: 1 if it worked, or -1 if an error occurred
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
	{
		return (0);
	}

	*n |= (1UL << index);

	return (1);
}
