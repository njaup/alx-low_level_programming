#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * pop_listint - deletes the head node of a listint_t linked list
 * and returns the head node’s data (n)
 * @head: pointer to the head node of the linked list
 * Return: if the linked list is empty return 0
 */
int pop_listint(listint_t **head)
{
	int value;
	listint_t *node = NULL;

	value = 0;
	if (*head == NULL)
	{

	return (value);

	}

	value= (*head)->n;
	node = *head;

	*head = (*head)->next;
	free(node);

	return (value);

}
