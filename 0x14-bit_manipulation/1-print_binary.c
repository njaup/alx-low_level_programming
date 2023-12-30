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
	int index = 0;

	for (int count = size - 1; count >= 0; count--)
	{
		if ((n >> count) & 1)
		{
			putchar('1');
			index++;
		}
		else if (index > 0 || count == 0)
		{
			putchar('0');
		}
	}
}
