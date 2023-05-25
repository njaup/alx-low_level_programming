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
	FILE *file = fopen(filename, "r");
	char *buffer = (char *)malloc(letters + 1);
	ssize_t bytesRead = fread(buffer, sizeof(char), letters, file);
	ssize_t bytesWritten = fwrite(buffer, sizeof(char), bytesRead, stdout);

	if (filename == NULL)
	{
		return (0);
	}

	if (file == NULL)
	{
		return (0);
	}

	if (buffer == NULL)
	{
		fclose(file);
		return (0);
	}

	if (bytesRead <= 0)
	{
		fclose(file);
		free(buffer);
		return (0);
	}

	buffer[bytesRead] = '\0';

	if (bytesWritten != bytesRead)
	{
		fclose(file);
		free(buffer);
		return (0);
	}
	fclose(file);
	free(buffer);
	return (bytesWritten);
}
