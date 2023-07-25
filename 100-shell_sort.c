#include "sort.h"

/**
 * vswap - swaped values in an array.
 * @array: the array containing values to swap.
 * @idx1: First index
 * @idx2: Second index
 */
void vswap(int *array, int idx1, int idx2)
{
	int z;

	if (array[idx1] != array[idx2])
	{
		z = array[idx1];
		array[idx1] = array[idx2];
		array[idx2] = z;
	}
}

/**
 * shell_sort - sort integers in ascending order
 * @array: The array to sort.
 * @size: array size to be sorted.
 */
void shell_sort(int *array, size_t size)
{
	size_t x = 0;
	size_t y;
	size_t z;

	if (size < 2)
		return;

	while (x <= size / 3)
		x = x * 3 + 1;

	while (x >= 1)
	{
		for (y = x; y < size; y++)
			for (z = y; z >= x && array[z] < array[z - x]; z -= x)
				vswap(array, z, z - x);
		x /= 3;
		print_array(array, size);
	}
}
