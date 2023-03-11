#include "main.h"
#include <stdio.h>

/**
 * main - prints its name
 * @argv: arguments
 * @argc: number of arguments
 * Return: 0
 */
int main(int argc, char *argv[])
{
	(void) argc; /*ignore argc*/

	printf("%s\n", argv[0]);
	return (0);
}
