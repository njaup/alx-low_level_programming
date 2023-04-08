#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_binary - prints the binary representation of a number
 * @n: number to be converted to binary and printed
 */
void print_binary(unsigned long int n)
{
	int bitpos = sizeof(n) * 8;
	unsigned long int binary = 1UL << (bitpos - 1);

	for (int count = 0; count < bitpos; count++)
	{
		if ((n & binary) == 0)
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
		binary >>= 1;
	}

}

/**
 * main - prints the binary representation of a number
 * @digit: binary number
 * Return: 0
 */
int main(void)
{
	unsigned long int digit = 25;

	printf("Binary rep of %lu is: \n", digit);
	print_binary(digit);
	return (0);
}
