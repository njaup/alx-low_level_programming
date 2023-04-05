#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * sum_listint - returns the sum of all the data
 * (n) of a listint_t linked list
 * @head: pointer to the head node of the linked list
 * Return: if the list is empty, return 0
 */
int sum_listint(listint_t *head)
{
	int tally;

	listint_t *c = head;
	
	tally = 0;
	while (c != NULL)
	{
		tally += ->n;
		c = c->next;
	}
	return (tally);
}
