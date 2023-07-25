#include "sort.h"

/**
 * insertion_sort_list - sorts doubly LL of integers in ascending order
 * @list: the doubly LL to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *a;
	listint_t *z;

	if (!list)
		return;

	a = *list;

	while (a)
	{
		while (a->next && (a->n > a->next->n))
		{
			z = a->next;
			a->next = z->next;
			z->prev = a->prev;

			if (a->prev)
				a->prev->next = z;

			if (z->next)
				z->next->prev = a;

			a->prev = z;
			z->next = a;

			if (z->prev)
				a = z->prev;
			else
				*list = z;

			print_list(*list);
		}
		a = a->next;
	}
}
