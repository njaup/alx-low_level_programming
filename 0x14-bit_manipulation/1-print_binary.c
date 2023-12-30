#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * print_binary - prints the binary representation of a number
 * @n: number
 */
void print_binary(unsigned long int n)
{
	int size = sizeof(unsigned long int) * 8;
	int index;

	for (index = size - 1; index >= 0; index--)
	{
		if ((n >> index) & 1)
		{
			putchar('1');
		}
		else if (index == 0)
		{
			putchar('0');
		}
	}
}
