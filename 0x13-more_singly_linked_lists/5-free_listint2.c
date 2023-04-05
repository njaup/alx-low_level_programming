#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * free_listint2 - frees a listint_t list
 * @head: ponter to the head of the list
 */
void free_listint2(listint_t **head)
{
	listint_t *c;

	if (head == NULL)
		return;

	while (*head)
	{
		c = *head;

		*head = (*head)->next;

		free(c);
	}
}
