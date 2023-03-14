#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _strdup - pointer to a newly allocated space in memory
 * which contains a copy of the string given as a parameter
 * @str: string
 * Return: NULL if str = NULL
 */
char *_strdup(char *str)
{
	char *d;
	unsigned int i, len;

	i = 0;
	len = 0;

	if (str == NULL)
		return (NULL);

	while (str[len])
		len++;
	d = malloc(sizeof(char) * (len + 1));

	if (d == NULL)
		return (NULL);

	while ((d[i] = str[i]) != '\0')
		i++;
	return (d);
}
