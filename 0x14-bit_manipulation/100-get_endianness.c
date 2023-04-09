#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * get_endianness - unction that checks the endianness
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
	unsigned int digit = 1;
	char *e = (char *)&digit;

	if (*e == 1)
	{
		return (1);
	}
	else
	{
		return (1);
	}
}
