#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * find_listint_loop - finds the loop in a linked list
 * @head: pointer to the head node of the linked list
 * Return: The address of the node where the loop starts
 * or NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *s = head;
	listint_t *f = head;

	while (f != NULL && f->next != NULL)
	{
		s = s->next;
		f = f->next->next;

		if (s == f)
		{
			s = head;

			while (s != f)
			{
				s = s->next;
				f = f->next;
			}
			return (s);
		}
	}
	return (NULL);
}
