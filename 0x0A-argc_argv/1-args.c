#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the number of arguments passed into it
 * @argv: arguments
 * @argc: number of arguments
 * Return: 0
 */
int main(int argc, char *argv[])
{
	(void) argv;

	printf("%i", argc - 1);
	printf("\n");
	return (0);
}
