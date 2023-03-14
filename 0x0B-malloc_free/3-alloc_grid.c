#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * alloc_grid - returns a pointer to a 2 dimensional array of integers
 * @width: dimension
 * @height: dimension
 * Return: If width or height is 0 or negative, return NULL
 */
int **alloc_grid(int width, int height)
{
	int i, j;
	int **a;

	if (height <= 0 || width <= 0)
		return (NULL);
	a = (int **) malloc(sizeof(int *) * height);

	if (a == NULL)
		return (NULL);
	for (i = 0; i < height; i++)
	{
		a[i] = (int *) malloc(sizeof(int) * width);

		if (a[i] == NULL)
		{
			free(a);
			for (j = 0; j <= i; j++)
				free(a[j]);
			return (NULL);
		}
	}

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			a[i][j] = 0;
		}
	}
	return (a);
}
