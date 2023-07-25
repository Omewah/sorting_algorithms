#include "sort.h"
/**
 * v_swap - swap + sort values in ascending/descending order
 * @array: the array which contains the values
 * @val1: first value
 * @val2: second value
 * @od: ascending/descending order
 */
void v_swap(int array[], int val1, int val2, int od)
{
	int z;

	if (od == (array[val1] > array[val2]))
	{
		z = array[val1];
		array[val1] = array[val2];
		array[val2] = z;
	}
}
/**
 * bsq_sort - sort bitonic sequences
 * @array: the array which contains the sequences
 * @val: the first sequence
 * @nth: the nth value of the sequence
 * @od: ascending/descending order
 */
void bsq_sort(int array[], int val, int nth, int od)
{
	int x, y;

	if (nth > 1)
	{
		x = nth / 2;
		for (y = val; y < val + x; y++)
			v_swap(array, y, y + x, od);
		bsq_sort(array, val, x, od);
		bsq_sort(array, val + x, x, od);
	}
}
/**
 * bsq_sortIN - bitonic sort algorithm implementation
 * @array: the array which contains the sequences
 * @val: the first sequence
 * @nth: the nth value of the sequence
 * @od: ascending/descending order
 * @size: the length of the array
 */
void bsq_sortIN(int array[], int val, int nth, int od, int size)
{
	int x;

	if (nth > 1)
	{
		if (od >= 1)
		{
			printf("Merging [%i/%i] (UP):\n", nth, size);
			print_array(&array[val], nth);
		}
		else
		{
			printf("Merging [%i/%i] (DOWN):\n", nth, size);
			print_array(&array[val], nth);
		}
		x = nth / 2;
		bsq_sortIN(array, val, x, 1, size);
		bsq_sortIN(array, val + x, x, 0, size);
		bsq_sort(array, val, nth, od);
		if (od <= 0)
		{
			printf("Result [%i/%i] (DOWN):\n", nth, size);
			print_array(&array[val], nth);
		}
		if (od >= 1)
		{
			printf("Result [%i/%i] (UP):\n", nth, size);
			print_array(&array[val], nth);
		}
	}
}
/**
 * bitonic_sort - sorts the array in ascending order
 * @array: the array to sort
 * @size: the length of the array to sort
 */
void bitonic_sort(int *array, size_t size)
{
	int od = 1;

	if (!array || size < 2)
		return;
	bsq_sortIN(array, 0, size, od, size);
}
