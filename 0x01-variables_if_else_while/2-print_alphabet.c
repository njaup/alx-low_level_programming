#include <stdio.h>

/**
 * main - Prints the alphabet in lowercase, followed by a new line.
 *
 * Return: Always 0.
 */
int main(void)
{
	char alp[26] = "abcdefghijklmnopqrstuvwxyz";
	int i;


	for (i = 0; i < 26; i++)
	{
		ptchar(alp[i]);
	}
	putchar('\n');
	return (0);
}
