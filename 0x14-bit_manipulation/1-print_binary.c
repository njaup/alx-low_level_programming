#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/**
 * print_binary - prints the binary representation of a number
 * @n: integer
 * Return: NULL
 */
void print_binary(unsigned long int n)
{
	unsigned long int byt = 1UL << (sizeof(unsigned long int) * 8 - 1);
	char c = (n & byt) ? '1' : '0';
	int fd = STDOUT_FILENO;

	while (byt > 0)
	{
		write(fd, &c, 1);
		byt >>= 1;
	}
}
