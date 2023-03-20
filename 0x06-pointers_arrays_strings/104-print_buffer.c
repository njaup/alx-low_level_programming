#include "main.h"
#include <stdio.h>

/**
 * print_buffer - prints a buffer 10 bytes at a time
 * @size: the number of bytes to be printed from the buffer
 * @b: buffer
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
			int C = *(b + byte + i);

			if (C < 32 || C > 132)
			{
				C = '.';
			}
			printf("%c", C);
		}
		printf("\n");
		byte += 10;
	}
}
