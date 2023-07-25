#include "sort.h"

/**
 * cp_buffer - a copy function between buffers
 * @src: the source buffer to copy from
 * @dst: the destination buffer after copying
 * @size: size of buffer to be copied
 */
void cp_buffer(int *src, int *dst, int size)
{
	int z;

	for (z = 0; z < size; z++)
		dst[z] = src[z];
}
/**
 * mg_buffer - merges buffer after copying
 * @src: the source buffer to merge
 * @dest: the destination buffer after merging
 * @idx1: first buffer index 1
 * @idx2: second buffer index 2
 * @idx3: third buffer index 3
 * @idx4: fourth buffer index 4
 */
void mg_buffer(int *src, int *dest, int idx1, int idx2, int idx3, int idx4)
{
	int x = idx1, y = idx3, z = idx1;

	while (x <= idx2 || y <= idx4)

		if (x <= idx2 && y <= idx4)
			if (dest[x] <= dest[y])
				src[z] = dest[x], z++, x++;
			else
				src[z] = dest[y], z++, y++;

		else if (x > idx2 && y <= idx4)
			src[z] = dest[y], z++, y++;
		else
			src[z] = dest[x], z++, x++;
}
/**
 * pr_array - prints an array in a given range
 * @array: the array to print
 * @src: the head of the array
 * @dest: the destination to print
 */
void pr_array(int *array, int src, int dest)
{
	int z;

	for (z = src; z <= dest; z++)
	{
		if (z > src)
			printf(", ");
		printf("%d", array[z]);
	}
	printf("\n");
}
/**
 * sp_array - a function that splits elements in an array
 * @sp: the array to be split
 * @b: the buffer of arrays containing elements
 * @min: minimum byte length
 * @max: maximum byte length
 * @sz: total size of data to split
 */
void sp_array(int *sp, int *b, int min, int max, int sz)
{
	int z, y;
	int idx1, idx2, idx3, idx4;

	if ((max - min) <= 0)
		return;

	z = (max + min + 1) / 2;
	y = max;
	max = z - 1;

	idx1 = min;
	idx2 = max;

	sp_array(sp, b, min, max, sz);

	min = z;
	max = y;

	idx3 = min;
	idx4 = max;

	sp_array(sp, b, min, max, sz);

	printf("Merging...\n");
	printf("[left]: ");

	pr_array(sp, idx1, idx2);

	printf("[right]: ");

	pr_array(sp, idx3, idx4);
	mg_buffer(sp, b, idx1, idx2, idx3, idx4);
	cp_buffer(sp, b, sz);

	printf("[Done]: ");
	pr_array(sp, idx1, idx4);
}
/**
 * merge_sort - sorts an array in ascending order
 * @array: array of data to be sorted
 * @size: size of data
 */
void merge_sort(int *array, size_t size)
{
	int *z;

	if (size < 2)
		return;

	z = malloc(sizeof(int) * size);
	if (z == NULL)
		return;

	cp_buffer(array, z, size);

	sp_array(array, z, 0, size - 1, size);

	free(z);
}
