#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stddef.h>

/**
 * read_textfile -  reads a text file and prints
 * it to the POSIX standard output
 * @filename: The name of the file
 * @letters: the number of letters it should read and print
 * Return: actual number of letters it could read and print
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	FILE *file;
	char buffer[MAX_BUFFER_SIZE];
	ssize_t sum_byt_w = 0;
	size_t byt_r;

	file = fopen(filename, "r");

	if (filename == NULL)
	{
		return (0);
	}
	if (file == NULL)
	{
		return (0);
	}
	while ((byt_r = fread(buffer, 1, sizeof(buffer), file)) > 0)
	{
		ssize_t byt_w = write(STDOUT_FILENO, buffer, byt_r);
		if (byt_w == -1 || (size_t) byt_w != byt_r)
		{
			fclose(file);
			return (0);
		}
		sum_byt_w += byt_w;
		if (sum_byt_w >= (ssize_t) letters)
			break;
	}
	fclose(file);
	return (sum_byt_w);
}
