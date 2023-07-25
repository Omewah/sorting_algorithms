#include "sort.h"

/**
 * swap_elmt - Swaps two elements in an array.
 * @array: The array to swap.
 * @idx1: The first index.
 * @idx2: The second index.
 */
void swap_elmt(int *array, size_t idx1, size_t idx2)
{
	int z;

	if (array != NULL)
	{
		z = array[idx1];
		array[idx1] = array[idx2];
		array[idx2] = z;
	}
}

/**
 * qsort_lmt - Sorts using qucik sort + lomuto partition
 * @array: The array containing the sub-array.
 * @top: The head of the sub-array.
 * @end: The tail of the sub-array.
 * @size: The length of the array.
 */
void qsort_lmt(int *array, size_t top, size_t end, size_t size)
{
	size_t a;
	size_t b;
	int pwr;

	if ((top >= end) || (array == NULL))
		return;
	pwr = array[end];
	a = top;
	for (b = top; b < end; b++)
	{
		if (array[b] <= pwr)
		{
			if (a != b)
			{
				swap_elmt(array, a, b);
				print_array(array, size);
			}
			a++;
		}
	}
	if (a != end)
	{
		swap_elmt(array, a, end);
		print_array(array, size);
	}
	if (a - top > 1)
		qsort_lmt(array, top, a - 1, size);
	if (end - a > 1)
		qsort_lmt(array, a + 1, end, size);
}

/**
 * quick_sort - Sorts an array using the quick sort
 * @array: The array to sort.
 * @size: The length of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array != NULL)
	{
		qsort_lmt(array, 0, size - 1, size);
	}
}
