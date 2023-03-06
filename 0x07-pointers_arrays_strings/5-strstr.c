#include "main.h"
#include <stdio.h>
/**
 * _strstr - locates a substring
 * @needle: value
 * @haystack: value
 * Return: NULL if the substring is not found
 */
char *_strstr(char *haystack, char *needle)
{
	for (; *haystack != '\0'; haystack++)
	{
		char *one = needle;
		char *two = haystack;

		while (*two == *one && *one != '\0')
		{
			one++;
			two++;
		}
		if (*one == '\0')
			return (haystack);
	}
	return (0);
}
