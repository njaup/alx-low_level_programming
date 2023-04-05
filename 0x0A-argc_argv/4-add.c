#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * check_num - string are digit
 * @str: str array
 * Return: 0
 */
int check_num(char *str)
{
	unsigned int tally;

	tally = 0;
	while (tally < strlen(str))

	{
		if (!isdigit(str[tally]))
		{
			return (0);
		}
		tally++;
	}
	return (1);
}

/**
 * main - adds positive numbers
 * @argv: arguments
 * @argc: number of arguments
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int tally;
	int str_to_int;
	int total = 0;

	tally = 1;
	while (tally < argc)
	{
		if (check_num(argv[tally]))
		{
			str_to_int = atoi(argv[tally]);
			total += str_to_int;
		}
		else
		{
			printf("Error");
			printf("\n");
			return (1);
		}
		tally++;
	}
	printf("%d", total);
	printf("\n");
	return (0);
}
