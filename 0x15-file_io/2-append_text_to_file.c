#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * append_text_to_file - appends text at the end of a file
 * @filename: The name of the file
 * @text_content: string to add at the end of the file
 * Return: 1 on success and -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	FILE *file_d;
	size_t w;
	size_t text_length = strlen(text_content);

	file_d = fopen(filename, "a");

	if (text_content == NULL)
	{
		return (-1);
	}
	if (filename == NULL)
	{
		return (-1);
	}
	if (file_d == NULL)
	{
		return (-1);
	}
	w = fwrite(text_content, 1, text_length, file_d);
	fclose(file_d);

	if (w != text_length)
	{
		return (-1);
	}
	return (1);
}
