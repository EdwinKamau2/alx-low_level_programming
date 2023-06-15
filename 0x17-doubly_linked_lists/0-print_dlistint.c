#include "lists.h"

/**
 * print_dlistint - this will print all the elements of a
 * dlistint_t list
 *
 * @h: is the head of the list
 * Return: this is the number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	int c;

	c = 0;

	if (h == NULL)
		return (c);

	while (h->prev != NULL)
		h = h->prev;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		c++;
		h = h->next;
	}

	return (c);
}
