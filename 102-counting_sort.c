#include "sort.h"
/**
 * counting_sort - sorts an array in ascending order
 * @array: pointer to the array to sort
 * @size: size of the array to sort
 */
void counting_sort(int *array, size_t size)
{
	int a, b;
	int *idx, *z;
	size_t k;

	if (!array || size < 2)
		return;
	a = array[0];
	for (k = 0; k < size; k++)
	{
		if (array[k] > a)
			a = array[k];
	}
	idx = calloc((a + 1), sizeof(int));
	for (k = 0; k < size; k++)
	{
		idx[array[k]]++;
	}
	for (b = 1; b < a; b++)
	{
		idx[b + 1] += idx[b];
	}
	print_array(idx, a + 1);
	z = malloc(sizeof(int) * size);
	for (k = 0; k < size; k++)
	{
		idx[array[k]]--;
		z[idx[array[k]]] = array[k];
	}
	for (k = 0; k < size; k++)
	{
		array[k] = z[k];
	}
	free(z);
	free(idx);
}

