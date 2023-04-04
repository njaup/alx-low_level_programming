#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

/**
 * print_listint - prints all the elements of a listint_t list
 * @h: pointer to head of list
 * Return: the numbber of nodes
 */

size_t print_listint(const listint_t *h)
{
	size_t nodes;

	nodes = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		nodes++;
	}
	return (nodes);
}
