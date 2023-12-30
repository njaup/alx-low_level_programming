#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * create_file - Create a function that creates a file
 * @filename: files
 * @text_content: Writed in the file
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fdescript;
	int nl;
	int rwrite;

	if (!filename)
		return (-1);

	fdescript = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (fdescript == -1)
		return (-1);

	if (!text_content)
		text_content = "";

	for (nl = 0; text_content[nl]; nl++)
		;

	rwrite = write(fdescript, text_content, nl);

	if (rwrite == -1)
		return (-1);

	close(fdescript);

	return (1);
}
