#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: The array to be sorted
 * @size: The array size to sort
 */
void selection_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	size_t x;
	int z;

	for (j = 0; j < size - 1; j++)
	{
		x = j;
		for (i = j + 1; i < size; i++)
		{
			if (array[i] < array[x])
				x = i;
		}

		if (x != j)
		{
			z = array[j];
			array[j] = array[x];
			array[x] = z;
			print_array(array, size);
		}
	}
}
