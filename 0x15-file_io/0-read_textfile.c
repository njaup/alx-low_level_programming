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
	int fdescript;
	ssize_t nread, nwrite;
	char *buffer;

	if (!filename)
		return (0);

	fdescript = open(filename, O_RDONLY);

	if (fdescript == -1)
		return (0);

	buffer = malloc(sizeof(char) * (letters));
	if (!buffer)
		return (0);

	nread = read(fdescript, buffer, letters);
	nwrite = write(STDOUT_FILENO, buffer, nread);

	close(fdescript);

	free(buffer);

	return (nwrite);
}
