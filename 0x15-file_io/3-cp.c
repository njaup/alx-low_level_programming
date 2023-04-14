#include <stdio.h>
#include <stdlib.h>

/**
 * main - copies the content of a file to another file
 * @argc: arguments
 * @argv: an array of arguments
 * Return: if file_to already exists, truncate it
 */
int main(int argc, char *argv[])
{
	FILE *file_from, *file_to;
	char cp;

	if (argc != 3)
	{
		printf("Usage: cp file_from file_to");
		printf("\n");

		return (1);
	}
	file_from = fopen(argv[1], "D");

	if (file_from == NULL)
	{
		printf("Error: Can't read from file");
		printf("\n");

		return (1);
	}
	file_to = fopen(argv[2], "R");

	if (file_to == NULL)
	{
		printf("Error: Can't write to file");
		printf("\n");
		fclose(file_from);

		return (1);
	}
	while ((cp = fgetc(file_from)) != EOF)
	{
		fputc(cp, file_to);
	}
	fclose(file_from);
	fclose(file_to);
	printf("Can't close fd");
	printf("\n");

	return (0);
}
