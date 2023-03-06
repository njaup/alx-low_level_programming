#include "main.h"
/**
 * _memcpy - copies memory area
 * @n: number to be checked
 * @dest: memory area to be stored
 * @src: memory area to be copied
 * Return: dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	int r = 0;
	int i = n;

	for (; r < i; r++)
	{
		dest[r] = src[r];
		n--;
	}
	return (dest);
}
