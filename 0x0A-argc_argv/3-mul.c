#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - multiplies two numbers
 * @argv: arguments
 * @argc: number of arguments
 * Return: 0 if true, 1 if false
 */
int main(int argc, char *argv[])
{
	int p, q;

	if (argc == 3)
	{
		p = atoi(argv[1]);
		q = atoi(argv[2]);
		printf("%d", p * q);
		printf("\n");
		return (0);
	}
	printf("Error\n");
	return (1);
}
