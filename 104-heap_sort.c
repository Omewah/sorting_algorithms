#include "sort.h"
/**
 * chk_array - check
 * @array: pointer to array address
 * @size: size of the array address pointer
 * @og: the initial size of the array
 * @idx: the array index
 */
void chk_array(int *array, size_t og, size_t size, size_t idx)
{
	int x, y, z;
	size_t a;
	size_t b;

	a = idx * 2 + 1;
	b = a + 1;
	y = array[a];
	z = array[b];
	if (((a < size) && (b < size) &&
		(y >= z && y > array[idx]))
		|| ((a == size - 1) && y > array[idx]))
	{
		x = array[idx];
		array[idx] = y;
		array[a] = x;
		print_array(array, og);
	}
	else if ((a < size) && (b < size) &&
		(z > y && z > array[idx]))
	{
		x = array[idx];
		array[idx] = z;
		array[b] = x;
		print_array(array, og);
	}
	if (a < size - 1)
		chk_array(array, og, size, a);
	if (b < size - 1)
		chk_array(array, og, size, b);
}
/**
 * heap_sort - sorts an array in ascending order
 * @array: pointer to array address
 * @size: size of the address pointer
 */
void heap_sort(int *array, size_t size)
{
	size_t a;
	size_t og = size;
	int z;

	if (!array)
		return;
	for (a = 0; a < size / 2 ; a++)
	{
		chk_array(array, og, size, size / 2 - 1 - a);
	}
	for (a = 0; a < og - 1; a++)
	{
		z = array[0];
		array[0] = array[size - 1 - a];
		array[size - 1 - a] = z;
		print_array(array, og);
		chk_array(array, og, size - a - 1, 0);
	}

}
