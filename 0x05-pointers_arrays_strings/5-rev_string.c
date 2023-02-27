#include "main.h"
/**
 * rev_string - reverses a string
 * @s: string
 * Return: string in reverse
 */
void rev_string(char *s)
{
	char temp;
	int length = 0, index = 0;

	while (s[index++])
	length++;

	for (index = length - 1; index >= length / 2; index--)
	{
		temp = s[index];
		s[index] = s[length - index - 1];
		s[length - index - 1] = temp;
	}
}

