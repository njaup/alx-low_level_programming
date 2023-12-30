#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * append_text_to_file - Write a function that appends text
 * at the end of a file
 * @filename: files
 * @text_content: added content
 * Return: 1 on success and -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fdescript;
	int nl;
	int rwrite;

	if (!filename)
		return (-1);

	fdescript = open(filename, O_WRONLY | O_APPEND);

	if (fdescript == -1)
		return (-1);

	if (text_content)
	{
		for (nl = 0; text_content[nl]; nl++)
			;

		rwrite = write(fdescript, text_content, nl);

		if (rwrite == -1)
			return (-1);
	}

	close(fdescript);

	return (1);
}
