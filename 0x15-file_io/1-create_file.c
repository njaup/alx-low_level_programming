#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * create_file - function that creates a file
 * @filename: the file name
 * @text_content: terminated string to write to the file
 * Return: 1 on success, -1 on failure
 * if the file already exists, truncate it
 * if filename is NULL return -1
 * if text_content is NULL create an empty file
 */
int create_file(const char *filename, char *text_content)
{
	FILE *f = fopen(filename, "write");

	if (f == 0)
	{
		perror("Error opening");
		return (-1);
	}
	if (fprintf(f, "%s", text_content) < 0)
	{
		perror("Error writing");
		return (1);
	}
	if (fclose(f) != 0)
	{
		perror("Error closing");
		return (-1);
	}
	return (1);
}
