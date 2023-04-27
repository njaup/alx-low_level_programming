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
	int len = strlen(text_content);
	FILE *fp = fopen(filename, "a");

	if (filename == NULL)
	{
		return (-1);
	}

	if (text_content == NULL)
	{
		return (1);
	}

	if (fp == NULL)
	{
		return (-1);
	}

	if ((int)fwrite(text_content, sizeof(char), len, fp) != len)
	{
		fclose(fp);
		return (-1);
	}

	fclose(fp);
	return (-1);
}
