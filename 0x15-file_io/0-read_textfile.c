#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * read_textfile - function that reads a text file and prints
 * it to the POSIX standard output
 * @filename: The file name
 * @letters: the number of letters
 * Return: the actual number of letters it could read and print
 * if the file can not be opened or read, return 0
 * if filename is NULL return 0
 * if write fails or does not write the expected amount
 * of bytes, return 0
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	FILE *fo;
	char *bul;
	ssize_t data;

	fo = fopen(filename, "r");
	if (fo == 0)
	{
		perror("Error opening file");
		return (-1);
	}
	bul = malloc(letters + 1);
	if (bul == 0)
	{
		perror("Error reading file");
		fclose(fo);
		return (-1);
	}
	data = fread(bul, 1, letters, fo);
	bul[data] = '\0';
	printf("%s", bul);

	free(bul);
	fclose(fo);
	return (data);
}
