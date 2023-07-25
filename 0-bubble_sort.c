#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: The array of integer to sort
 * @size: The array size to sort
 */

void bubble_sort(int *array, size_t size)
{
	size_t a;
	int z;
	int x;

	if (!array || size == 0)
		return;

	do {
		x = 1;
		for (a = 0; a < size - 1; a++)
		{
			if (array[a] > array[a + 1])
			{
				x = 0;
				z = array[a];
				array[a] = array[a + 1];
				array[a + 1] = z;
				print_array(array, size);
			}
		}

	} while (x == 0);
}
