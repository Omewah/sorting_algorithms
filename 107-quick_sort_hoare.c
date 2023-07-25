#include "sort.h"
/**
 * po_swap - change the positions of values in an array
 * @array: the array containing values to swap positions
 * @val1: the first value
 * @val2: the second value
 */
void po_swap(int *array, ssize_t val1, ssize_t val2)
{
	int z;

	z = array[val1];
	array[val1] = array[val2];
	array[val2] = z;
}
/**
 * h_parIN - implementing hoare partitioning algorithm
 * @array: the array to partition
 * @val1: the first value
 * @val2: the second value
 * @size: the length of the array to partition
 * Return: the partitioned array element
 */
int h_parIN(int *array, int val1, int val2, int size)
{
	int x = val1 - 1;
	int y = val2 + 1;
	int pvt = array[val2];

	while (1)
	{

		do {
			x++;
		} while (array[x] < pvt);
		do {
			y--;
		} while (array[y] > pvt);
		if (x >= y)
			return (x);
		po_swap(array, x, y);
		print_array(array, size);
	}
}
/**
 * q_sort - implementing quick sort algorithm
 * @array: the array to sort
 * @val1: the first value
 * @val2: the second value
 * @size: the length of the array to sort
 */
void q_sort(int *array, ssize_t val1, ssize_t val2, int size)
{
	ssize_t ps = 0;

	if (val1 < val2)
	{
		ps = h_parIN(array, val1, val2, size);
		q_sort(array, val1, ps - 1, size);
		q_sort(array, ps, val2, size);
	}
}
/**
 * quick_sort_hoare - sort an array in ascending order
 * @array: the array to sort
 * @size: the length of the array to sort
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	q_sort(array, 0, size - 1, size);
}
