#include "main.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * _is_zero - determines if any number is zero
 * @argv: arguments
 * Return: no return
 */

void _is_zero(char *argv[])
{
	int i, isn1 = 1, isn2 = 1;

	for (i = 0; argv[1][i]; i++)
		if (argv[1][i] != '0')
		{
			isn1 = 0;
			break;
		}
	for (i = 0; argv[2][i]; i++)
		if (argv[2][i] != '0')
		{
			isn2 = 0;
			break;
		}
	if (isn1 == 1 || isn2 == 1)
	{
		printf("0\n");
		exit(0);
	}
}

/**
 * _initialize_array - set memery to zero in a new array
 * @ar: array
 * @lar: length of the array
 * Return: pointer
 */

char *_initialize_array(char *ar, int lar)
{
	int i = 0;

	for (i = 0; i < lar; i++)
		ar[i] = '0';
	ar[lar] = '\0';
	return (ar);
}

/**
 * check_num - determines length of the number
 * and checks if the number is in base 10
 * @argv: arguments
 * @n: row of the array
 * Return: length of the number
 */

int check_num(char *argv[], int n)
{
	int ln;

	for (ln = 0; argv[n][ln]; ln++)
		if (!isdigit(argv[n][ln]))
		{
			printf("Error\n");
			exit(98);
		}

	return (ln);
}

/**
 * main - multiplies two positive numbers
 * @argc: number of arguments
 * @argv: arguments
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int ln1, ln2, lnout, add, addl, i, j, k, ca;
	char *nout;

	if (argc != 3)
		printf("Error\n"), exit(98);
	ln1 = check_num(argv, 1), ln2 = check_num(argv, 2);
	_is_zero(argv), lnout = ln1 + ln2, nout = malloc(lnout + 1);
	if (nout == NULL)
		printf("Error\n"), exit(98);
	nout = _initialize_array(nout, lnout);
	k = lnout - 1, i = ln1 - 1, j = ln2 - 1, ca = addl = 0;
	for (; k >= 0; k--, i--)
	{
		if (i < 0)
		{
			if (addl > 0)
			{
				add = (nout[k] - '0') + addl;
				if (add > 9)
					nout[k - 1] = (add / 10) + '0';
				nout[k] = (add % 10) + '0';
			}
			i = ln1 - 1, j--, addl = 0, ca++, k = lnout - (1 + ca);
		}
		if (j < 0)
		{
			if (nout[0] != '0')
				break;
			lnout--;
			free(nout), nout = malloc(lnout + 1), nout = _initialize_array(nout, lnout);
			k = lnout - 1, i = ln1 - 1, j = ln2 - 1, ca = addl = 0;
		}
		if (j >= 0)
		{
			add = ((argv[1][i] - '0') * (argv[2][j] - '0')) + (nout[k] - '0') + addl;
			addl = add / 10, nout[k] = (add % 10) + '0';
		}
	}
	printf("%s\n", nout);
	return (0);
}
