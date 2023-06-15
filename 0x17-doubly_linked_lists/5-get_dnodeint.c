#include "lists.h"

/**
 * get_dnodeint_at_index - this returns the
 * nth node of a dlistint_t linked list
 *
 * @head: is the head of the list
 * @index: this is the index of the nth node
 * Return: is the nth node
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int ui;

	if (head == NULL)
		return (NULL);

	while (head->prev != NULL)
		head = head->prev;

	ui = 0;

	while (head != NULL)
	{
		if (ui == index)
			break;
		head = head->next;
		ui++;
	}

	return (head);
}
