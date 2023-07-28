#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: binary
 * Return: result
 */
unsigned int binary_to_uint(const char *b)
{
	size_t length = strlen(b);
	unsigned int total = 0;
	unsigned int rate = 1;
	int index;

	if (b == NULL)
		return (0);

	for (index = length - 1; index >= 0; index--)
	{
		if (b[index] == '1')
		{
			total += rate;
		}
		else if (b[index] != '0')
		{
			return (0);
		}
		rate <<= 1;
	}
	return (total);
}
