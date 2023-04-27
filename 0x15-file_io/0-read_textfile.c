#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

/**
 * read_textfile - function that reads a text file and prints
 * it to the POSIX standard output
 * @filename: The file name
 * @letters: the number of letters
 * Return: the actual number of letters it could read and print
 * if the file can not be opened or read, return 0
 * if filename is NULL return 0
 * if write fails or does not write the expected amount
 * of bytes, return 0
 */
ssize_t read_textfile(const char *filename, size_t letters)
{

	char buffer[1024];
	ssize_t bytes_read, bytes_written;
	int fd = open(filename, O_RDONLY);

	if (!filename)
	{
		return (0);
	}

	if (fd == -1)
	{
		return (0);
	}

	bytes_read = read(fd, buffer, sizeof(char) * letters);

	if (bytes_read == -1)
	{
		close(fd);
		return (0);
	}

	bytes_written = write(STDOUT_FILENO, buffer, bytes_read);

	if (bytes_written == -1 || bytes_written != bytes_read)
	{
		close(fd);
		return (0);
	}

	close(fd);
	return (bytes_read);
}
