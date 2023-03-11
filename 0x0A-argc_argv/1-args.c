#include "main.h"
#include <stdio.h>

/**
 * main - prints the number of arguments passed into it
 * @argv: arguments
 * @argc: number of arguments
 * Return: 0
 */
int main(int argc, char *argv[])
{
	(void) argv;

	printf("%i\n", argc - 1);
	return (0);
}
