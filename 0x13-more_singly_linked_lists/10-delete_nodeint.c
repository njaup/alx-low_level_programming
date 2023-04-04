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
	listint_t *current, *temp;
	unsigned int i;

	if (*head == NULL) /*check if the list is empty*/
		return (-1);

	if (index == 0)
	{
		temp = *head; /*check if the node to be deleted is the head*/
		*head = (*head)->next;
		free(temp);
		return (1);
	}

	current = *head;

	for (i = 0; i < index - 1 && current != NULL; i++)
		current = current->next;

	if (current == NULL || current->next == NULL)
		/*check if the index is out of range*/
		return (-1);

	/*delete the node at index*/
	temp = current->next;
	current->next = temp->next;
	free(temp);

	return (1);
}
