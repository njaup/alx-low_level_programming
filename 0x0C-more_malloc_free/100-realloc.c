#include "main.h"
#include <stdlib.h>

/**
 * *_realloc - reallocates a memory block using malloc and free
 * @ptr: pointer
 * @old_size: memory previously allocated
 * @new_size: memory currently allocated
 * Return: If new_size == old_size do not do anything and return ptr
 * If new_size is equal to zero, and ptr is not NULL
 * then the call is equivalent to free(ptr). Return NULL
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *realloc, *clone;
	unsigned int i;

	if (ptr != NULL)
		clone = ptr;

	else
		{
			return (malloc(new_size));
		}
	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (0);
	}
	realloc = malloc(new_size);

	if (realloc == NULL)
		return (0);

	for (i = 0; i < (old_size || i < new_size); i++)
	{
		*(realloc + 1) = clone[i];
	}
	free(ptr);
	return (realloc);
}

