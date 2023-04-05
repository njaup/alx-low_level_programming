#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints its name
 * @argv: arguments
 * @argc: number of arguments
 * Return: 0
 */
int main(int argc, char *argv[])
{
	(void) argc;

	printf("%s", argv[0]);
	printf("\n");
	return (0);
}
