#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * get_nodeint_at_index - returns the nth node * of a listint_t linked list
 * @head: pointer to the head node of the linked list
 * @index: index of the node
 * Return: if the node does not exist, return NULL
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *c = head;
	unsigned int count = 0;

	while (c != NULL && count < index)
	{
		c = c->next;
		count++;
	}

	if (c == NULL)
	{
		return (NULL);
	}

	return (c);
}
