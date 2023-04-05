#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * delete_nodeint_at_index - deletes the node at index index
 * of a listint_t linked list
 * @head: pointer to the head node of the linked list
 * @index: index of the node to delete
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *c, *node;
	unsigned int i;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		node = *head;
		*head = (*head)->next;
		free(node);
		return (1);
	}

	c = *head;

	for (i = 0; i < index - 1 && c != NULL; i++)
		c = c->next;

	if (c == NULL || c->next == NULL)
		return (-1);

	node = c->next;
	c->next = node->next;
	free(node);

	return (1);
}
