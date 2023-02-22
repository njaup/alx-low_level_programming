#include <stdio.h>

/**
 * print_to_98 - prints all natural numbers from n to 98
 * @n: The numbers to be printed in order
 * Return: nothing on success
 */
void print_to_98(int n)
{

	if (n > 98)
	{
		while (n >= 98)
		{
			printf("%d", n);
			if (n != 98)
				printf(", ");
			n--;
		}
	}
	else
	{
		while (n <= 98)
		{
			printf("%d", n);
			if (n != 98)
				printf(", ");
			n++;
		}
	}
	putchar('\n');
}

