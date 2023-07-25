#include "sort.h"

/**
 * print_list - a function that prints the integers in a list
 * @list: The list to print
 */
void print_list(const listint_t *list)
{
    int b;

    b = 0;
    while (list)
    {
        if (b > 0)
            printf(", ");
        printf("%d", list->n);
        ++b;
        list = list->next;
    }
    printf("\n");
}
