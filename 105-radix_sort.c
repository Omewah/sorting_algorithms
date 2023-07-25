#include "sort.h"
/**
 * rx_sort2 - radix sort function
 * @array: the array to sort
 * @b: memory allocation to the buffer array
 * @size: length of the array to sort
 * @dgt: the array significant digit
 */
void rx_sort2(int *array, int **b, int size, int dgt)
{
	int i, y, sz = 10;
	int pwr;
	int dix[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int dix2[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	for (i = 0; i < size; i++)
	{
		pwr = array[i];
		for (y = 0; y < dgt; y++)
			if (y > 0)
				pwr = pwr / 10;
		pwr = pwr % 10;
		b[pwr][dix[pwr]] = array[i];
		dix[pwr] += 1;
	}

	for (i = 0, y = 0; i < sz; i++)
	{
		while (dix[i] > 0)
		{
			array[y] = b[i][dix2[i]];
			dix2[i] += 1, dix[i] -= 1;
			y++;
		}
	}

	print_array(array, size);
}
/**
 * rx_sort - radix sort function
 * @array: the array to sort
 * @size: the length of array to sort
 * @dgt: the array significant digit
 */
void rx_sort(int *array, int size, int dgt)
{
	int dix[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int i, y, pwr, sz = 10, **b;

	for (i = 0; i < size; i++)
	{
		pwr = array[i];
		for (y = 0; y < dgt; y++)
			if (y > 0)
				pwr = pwr / 10;
		pwr = pwr % 10;
		dix[pwr] += 1;
	}

	if (dix[0] == size)
		return;

	b = malloc(sizeof(int *) * 10);
	if (!b)
		return;

	for (i = 0; i < sz; i++)
		if (dix[i] != 0)
			b[i] = malloc(sizeof(int) * dix[i]);


	rx_sort2(array, b, size, dgt);

	rx_sort(array, size, dgt + 1);

	for (i = 0; i < sz; i++)
		if (dix[i] > 0)
			free(b[i]);
	free(b);
}
/**
 * radix_sort - sorts an array in ascending order
 * @array: the array to be sorted
 * @size: the length of the array
 */
void radix_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	rx_sort(array, size, 1);
}
