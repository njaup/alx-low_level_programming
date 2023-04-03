#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

/**
 * print_listint - prints all the elements of a listint_t list
 * @n: integer value
 * @next: points to the next node
 * @current: pointer to head of list
 *
 * Description: singly linked list node structure
 * Return: the numbber of nodes
 */
size_t print_listint(const listint_t *h)
{
	size_t nodes = 0;
	const listint_t *current = h;
	
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
		nodes++;
	}
	return (nodes);
}
