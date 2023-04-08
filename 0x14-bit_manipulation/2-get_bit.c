#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * get_bit - returns the value of a bit at a given index
 * @n: integer value
 * @index: bit value
 * Return: the value of the bit at index index
 * or -1 if an error occured
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int bit = n >> index;

	if (bit & 1)
	{
		return (1);
	}
	return (0);
}

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	unsigned long int n = 218;
	unsigned int index = 3;
	int binary = get_bit(n, index);

	printf("Binary %u of %lu is %d", index, n, binary);
	printf("\n");

	return (0);
}
