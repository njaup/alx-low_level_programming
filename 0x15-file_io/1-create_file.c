#include "main.h"
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

/**
 * create_file - creates a file
 * @filename: The name of the file
 * @text_content: string to write to the file
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	size_t length = strlen(text_content);
	int file_d;
	ssize_t num_w;

	if (filename == NULL)
	{
		return (-1);
	}
	file_d = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (file_d == -1)
	{
		return (-1);
	}
	if (text_content != NULL)
	{
		num_w = write(file_d, text_content, length);
		if (num_w == -1)
		{
			close(file_d);
			return (-1);
		}
		if ((size_t) num_w != length)
		{
			close(file_d);
			return (-1);
		}
	}
	close(file_d);
	return (1);
}
