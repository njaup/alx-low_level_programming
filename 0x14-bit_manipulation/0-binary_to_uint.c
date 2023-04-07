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
	int length = strlen(b);
	int count;

	for (count = 0; count < length; count++)
	{
		if (b[count] == '1')
		{
			digit += (1 << (length - count - 1));
		}
	}
	return (digit);
}
