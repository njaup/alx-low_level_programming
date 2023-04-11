#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * append_text_to_file - function that appends text
 * at the end of a file
 * @filename: the file name
 * @text_content: terminated string
 * Return: 1 on success and -1 on failure
 * If filename is NULL return -1
 * if the file exists and -1
 */
int append_text_to_file(const char *filename, char *text_content)
{
	FILE *f = fopen(filename, "app");
	int l = strlen(text_content);
	int bits = fwrite(text_content, 1, l, f);

	if (!f)
	{
		return (-1);
	}

	fclose(f);
	if (bits < l)
	{
		return (-1);
	}
 
	return (1);
}
