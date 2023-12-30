#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * read_textfile - reads a text file and prints the letters
 * @filename: files
 * @letters: numbers of letters printed.
 * Return: if write fails or does not write, return 0
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int filed;
	ssize_t nread, nwrite;
	char *buffer;

	if (!filename)
		return (0);

	filed = open(filename, O_RDONLY);

	if (filed == -1)
		return (0);

	buffer = malloc(sizeof(char) * (letters));
	if (!buffer)
		return (0);

	nread = read(filed, buffer, letters);
	nwrite = write(STDOUT_FILENO, buffer, nread);

	close(filed);

	free(buffer);

	return (nwrite);
}
