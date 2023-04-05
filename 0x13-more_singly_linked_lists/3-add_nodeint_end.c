#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * add_nodeint_end - adds a new node at the end of a listint_t list
 * @head: pointer to the head of the list
 * @n: the value
 * Return: the address of the new element, or NULL if it failed
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *N_node, *L_node;

	N_node = malloc(sizeof(listint_t));
	if (N_node == NULL)
		return (NULL);

	N_node->n = n;
	N_node->next = NULL;

	if (*head == NULL)
	{
		*head = N_node;
		return (N_node);
	}

	L_node = *head;
	while (L_node->next)
		L_node = L_node->next;
	L_node->next = N_node;

	return (N_node);
}
