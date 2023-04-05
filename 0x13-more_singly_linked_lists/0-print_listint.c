#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * print_listint - prints all the elements of a listint_t list
 * @h: pointer to head of list
 * Return: the numbber of nodes
 */
size_t print_listint(const listint_t *h)
{
	const listint_t *current = h;
	size_t count = 0;

	for (current = h; current != NULL; current = current->next)
	{
		count++;
		printf("%d\n", current->n);
	}

	return (count);
}
