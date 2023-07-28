#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * clear_bit - sets the value of a bit to 0 at a given index
 * @n: number
 * @index: input
 * Return: 1
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask = ~(1UL << index);

	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}
	*n = *n & mask;
	return (1);
}
