#include "main.h"
#include <stdio.h>
#include <math.h>
#include <string.h>

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: binary number
 * Return: the converted number, or 0
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int digit = 0;
	int count = 0;

	while (b[count])
	{
		if (b[count] == '1')

			digit = (digit << 1) | 1;

		else if (b[count] == '0')

		digit <<= 1;

		else

		return (0);
		count++;
	}
	return (digit);
}
