#include "sort.h"

/**
 * node_swap - Swap the nodes of doubly LL
 * @node: the node to be swapped
 * @list: the doubly LL
 */
void node_swap(listint_t **node, listint_t **list)
{
	listint_t *z1 = *node;
	listint_t *z2;
	listint_t *z3;

	if (!(*node)->prev)
		*list = (*node)->next;

	z1 = z3 = *node;
	z2 = z1->next;

	z1->next = z2->next;
	z3 = z1->prev;
	z1->prev = z2;
	z2->next = z1;
	z2->prev = z3;

	if (z2->prev)
		z2->prev->next = z2;


	if (z1->next)
		z1->next->prev = z1;

	*node = z2;

}
/**
 * cocktail_sort_list - sorts a doubly LL in ascending order
 * @list: the doubly LL to sort
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *i;
	listint_t *z;
	int a = 0;
	int b = -1;
	int c = -1;

	if (!list || !(*list) || (!((*list)->prev) && !((*list)->next)))
		return;

	i = *list;
	while (c >= b)
	{
		b++;
		while (i->next && a != c)
		{
			if (i->n > i->next->n)
			{
				z = i;
			       node_swap(&z, list);
			       print_list(*list);
			       i = z;
			}

			a++;
			i = i->next;
		}

		if (b == 0)
			c = a;
		c--;
		while (i->prev && a >= b)
		{
			if (i->n < i->prev->n)
			{
				z = i->prev;
				node_swap(&z, list);
				print_list(*list);
				i = z->next;
			}
			a--;
			i = i->prev;
		}
	}
}
