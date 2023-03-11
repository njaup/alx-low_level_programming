#include <stdlib.h>
#include <stdio.h>

/**
 * main - prints the minimum number of coins
 * to make change for an amount of money
 * @argv: number of arguments
 * @argc: argv length
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int total, aux, position, change;
	int coins[] = {25, 10, 5, 2, 1};

	total = aux = position = change = 0;
	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	total = atoi(argv[1]);

			if (total <= 0)
			{
			printf("0\n");
			return (0);
			}
			while (coins[position] != '\0')

			{
			if (total >= coins[position])
			{
			aux = (total / coins[position]);
			change += aux;
			total -= coins[position] * aux;
			}
			position++;
			}

			printf("%d\n", change);
			return (0);
}
