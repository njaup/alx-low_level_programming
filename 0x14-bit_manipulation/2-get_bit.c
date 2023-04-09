#include "main.h"
#include <stdio.h>

/**
 * get_bit - returns the value of a bit at a given index
 * @n: integer value
 * @index: bit value
 * Return: the value of the bit at index index
 * or -1 if an error occured
 */
int get_bit(unsigned long int n, unsigned int index)
{
unsigned long int binary = n >> index;

	if (binary & 1)
	{
		return (1);
	}
	return (0);
}
