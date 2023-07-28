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
	unsigned long int mask = 1UL << (sizeof(unsigned long int) * 8 - 1);
	unsigned long int bit;

	while (mask != 0)
	{
		bit = (n & mask);
		if (bit)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		mask >>= 1;
	}
	write(1, "\n", 1);
}
