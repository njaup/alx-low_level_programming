#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

/**
 * main - prints the minimum number of coins
 * to make change for an amount of money
 * @argv: number of arguments
 * @argc: argv length
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int sum, aux, point, change;
	int coins[] = {25, 10, 5, 2, 1};

	sum = aux = point = change = 0;
	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	sum = atoi(argv[1]);

			if (sum <= 0)
			{
			printf("0");
			printf("\n");
			return (0);
			}
			while (coins[point] != '\0')

			{
			if (sum >= coins[point])
			{
			aux = (sum / coins[point]);
			change += aux;
			sum -= coins[point] * aux;
			}
			point++;
			}

			printf("%d", change);
			printf("\n");
			return (0);
}
