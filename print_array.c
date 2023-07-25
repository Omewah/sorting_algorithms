#include "sort.h"

/**
 * print_array - a function that prints an array
 * @array: The array to be printed
 * @length: the length of the array
 */
void print_array(const int *array, size_t length)
{
    size_t b;

    b = 0;
    while (array && b < length)
    {
        if (b > 0)
            printf(", ");
        printf("%d", array[b]);
        ++b;
    }
    printf("\n");
}
