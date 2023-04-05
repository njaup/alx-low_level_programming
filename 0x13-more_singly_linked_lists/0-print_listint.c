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
	size_t tally;
	const listint_t *current = h;

	tally = 0;
	while (current != NULL)
	{
		printf("%d", current->n);
		printf("\n");
		current = current->next;
		tally++;
	}

	return (tally);
}
