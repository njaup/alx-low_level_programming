#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * insert_nodeint_at_index - inserts a new node
 * at a given position
 * @head: pointer to the head node of the linked list
 * @idx: index where the new node should be inserted
 * @n: value to be stored
 * Return: the address of the new node, or NULL if it failed
 * if it is not possible to add the new node at index idx
 * do not add the new node and return NULL
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node = malloc(sizeof(listint_t));
	listint_t *previous_node = *head;

	if (new_node == NULL)
        {
                return (NULL);
        }

	new_node->n = n;
	new_node->next = NULL;

	if (idx == 0)
	{
		new_node->next = *head;
		*head = new_node;
		return (*head);
	}


	for (unsigned int i = 0; i < idx - 1 && previous_node != NULL; i++)
	{
		previous_node = previous_node->next;
	}

	if (previous_node == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->next = previous_node->next;
	previous_node->next = new_node;

	return (*head);
}

int main()
{
	listint_t *head = NULL;

	head = insert_nodeint_at_index(&head, 0, 10);
	insert_nodeint_at_index(&head, 1, 20);
	insert_nodeint_at_index(&head, 2, 30);
	insert_nodeint_at_index(&head, 3, 40);

	listint_t *current_node = head;

	while (current_node != NULL)
	{
		printf("%d ", current_node->n);
		current_node = current_node->next;
	}
	printf("\n");

	insert_nodeint_at_index(&head, 2, 50);

	current_node = head;
	while (current_node != NULL)
	{
		printf("%d ", current_node->n);
		current_node = current_node->next;
	}
	printf("\n");

	return (0);
}
