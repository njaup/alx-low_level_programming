#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * print_binary - prints the binary representation of a number
 * @n: integer
 * Return: NULL
 */
void print_binary(unsigned long int n)
{
	int count;

	for (count = (sizeof(unsigned long int) * 8) - 1; count >= 0; count--)
	{
		if ((n >> count) & 1)
		{
			putchar('1');
		}
		else
		{
			putchar('0');
		}
	}
}
