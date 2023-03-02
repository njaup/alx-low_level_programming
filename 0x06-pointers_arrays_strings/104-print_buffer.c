#include "main.h"
#include <stdio.h>

/**
 * print_buffer - prints a buffer 10 bytes at a time
 * @size: the number of bytes to be printed from the buffer
 * @b: buffer
 * Return: void
 */

void print_buffer(char *b, int size)
{
	int i, byte, j;

	byte = 0;

	if (size <= 0)
	{
		printf("\n");
		return;
	}
	while (byte < size)
	{
		j = size - byte < 10 ? size - byte : 10;
			printf("%08x: ", byte);
		for (i = 0; i < 10; i++)
		{
			if (i < j)
				printf("%02x", *(b + byte + i));
			else
				printf(" ");
			if (i % 2)
			{
				printf(" ");
			}
		}
		for (i = 0; i < j; i++)
		{
			int c = *(b + byte + i);

			if (c < 32 || c > 132)
			{
				c = '.';
			}
			printf("%c", c);
		}
		printf("\n");
		byte += 10;
	}
}
