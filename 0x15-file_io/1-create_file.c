#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

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
	int fdesc = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);

	if (filename == NULL)
	{
		return (-1);
	}
	if (fdesc == -1)
	{
		return (-1);
	}
	if (text_content != NULL)
	{
		ssize_t length = strlen(text_content);
		ssize_t written = write(fdesc, text_content, length);

		if (written != length)
		{
			close(fdesc);
			return (-1);
		}
	}

	close(fdesc);
	return (1);
}
