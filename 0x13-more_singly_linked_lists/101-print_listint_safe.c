#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_listint_safe - prints a listint_t linked list
 * @head: pointer to the head node of the linked list
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	 size_t count = 0;
        const listint_t *slow = head, *fast = head;

        while (slow && fast && fast->next)
        {
                printf("[%p] %d\n", (void *)slow, slow->n);
                count++;
                slow = slow->next;
                fast = fast->next->next;

                if (slow == fast)
                {
                        printf("[%p] %d\n", (void *)slow, slow->n);
                        printf("-> [%p] %d\n", (void *)slow->next, slow->next->n);
                        break;
                }
        }

        if (!slow || !fast || !fast->next)

        {
                while (head)
                {
                        printf("[%p] %d\n", (void *)head, head->n);
                        count++;
                        head = head->next;
                }
        }

        return (count);
}
