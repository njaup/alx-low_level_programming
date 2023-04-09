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
	unsigned long int mask = n >> index;

	if (mask & 1)
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
	int bit = get_bit(n, index);

	printf("Bit %u of %lu is %d\n", index, n, bit);

	return (0);
}
