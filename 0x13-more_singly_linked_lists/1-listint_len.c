#include "lists.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/**
 * listint_len - returns the number of elements in a linked listint_t list
 * @h: a pointer to the head node
 * Return: number of elements in the list
 */
size_t listint_len(const listint_t *h)
{
	size_t tally = 0;
	const listint_t *current = h;

	while (current != NULL)
	{
		current = current->next;
		tally++;
	}
	return (tally);
}
