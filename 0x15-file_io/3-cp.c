#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

/**
 * main - copies the content of a file to another file
 * @argc: arguments
 * @argv: array of arguments
 * Return: 0
 */
int main(int argc, char *argv[])
{
	const char *file_from = argv[1], *file_to = argv[2];
	int file_d_from, file_d_to;
	char buffer[BUFFER_SIZE];
	ssize_t nread, nw;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "usage: %s file_from file_to\n", argv[0]);
		exit(97);
	}
	file_d_from = open(file_from, O_RDONLY);
	if (file_d_from == -1)
	{
		dprintf(STDERR_FILENO, "error: can't read from file %s\n", file_from);
		exit(98);
	}
	file_d_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (file_d_to == -1)
	{
		dprintf(STDERR_FILENO, "error: can't write to %s\n", file_to);
		exit(99);
	}
	while ((nread = read(file_d_from, buffer, BUFFER_SIZE)) > 0)
	{
		nw = write(file_d_to, buffer, nread);
		if (nw != nread)
		{
			dprintf(STDERR_FILENO, "error: can't write to %s\n", file_to);
			exit(99);
		}
	}
	if (nread == -1)
	{
		dprintf(STDERR_FILENO, "error: can't read from file %s\n", file_from);
		exit(98);
	}
	if (close(file_d_from) == -1)
	{
		dprintf(STDERR_FILENO, "error: can't close file_d %d\n", file_d_from);
		exit(100);
	}
	if (close(file_d_to) == -1)
	{
		dprintf(STDERR_FILENO, "error: can't close file_d %d\n", file_d_to);
		exit(100);
	}
	return (0);
}
