#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * error_f - checks if files can be opened.
 * @file_from: Read in chunks of BUFFER_SIZE and write to file_to
 * @file_to: for writing or create it if it doesn't exist
 * @argv: arguments vector.
 * Return: no return.
 */
void error_f(int file_from, int file_to, char *argv[])
{
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
}
/**
 * main - check the code for Holberton School students.
 * @argc: number of arguments
 * @argv: arguments vector
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	int file_from, file_to, error_c;
	ssize_t nchars, nwrite;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
		exit(97);
	}

	file_from = open(argv[1], O_RDONLY);
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	error_f(file_from, file_to, argv);

	nchars = 1024;
	while (nchars == 1024)
	{
		nchars = read(file_from, buffer, 1024);
		if (nchars == -1)
			error_f(-1, 0, argv);
		nwrite = write(file_to, buffer, nchars);
		if (nwrite == -1)
			error_f(0, -1, argv);
	}

	error_c = close(file_from);
	if (error_c == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}

	error_c = close(file_to);
	if (error_c == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}
	return (0);
}
