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
	int data = 0;
	listint_t *temp = NULL;

	if (*head == NULL)
	{

	return (data); /*if the list is empty*/

	}

	data = (*head)->n; /*retrieve the data from the head node*/
	temp = *head; /*save the head node pointer*/

	*head = (*head)->next; /*move the head to the next node*/
	free(temp); /*free the memory of the original head node*/

	return (data); /*return the data value of the original head node*/

}
