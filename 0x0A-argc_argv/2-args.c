#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints all arguments it receives
 * @argv: arguments
 * @argc: number of arguments
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int tally = 0;

	if (argc > 0)
	{
		while (tally < argc)
		{
			printf("%s", argv[tally]);
			printf("\n");
			tally++;
		}
	}
	return (0);
}
