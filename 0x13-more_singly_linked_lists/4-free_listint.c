#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * free_listint - frees a listint_t list
 * @head: pointer to the first node of the list
 */
void free_listint(listint_t *head)
{
	listint_t *c = head;

	while (c != NULL)
	{
		listint_t *next = c->next;

		free(c);

		c = next;
	}
}
