#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * free_listint2 - frees a listint_t list
 * @head: ponter to the head of the list
 */
void free_listint2(listint_t **head)
{
	listint_t *tmp, **current = head;

	if (current == NULL)
		return;

	while (*current != NULL)
	{
		tmp = (*current)->next;

		*current = tmp;

		free(*current);
	}
	current = NULL;
}
