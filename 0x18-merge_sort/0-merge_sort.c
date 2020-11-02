#include "sort.h"

void merge(int *array, int *left, int *right, size_t size);

/**
 * merge_sort - Sorts an array of integers in ascending order.
 * @array: Array to be sorted.
 * @size: Size of @array.
 *
 * Return: Void
 */

void merge_sort(int *array, size_t size)
{
	size_t half, i;
	int sub_left[500];
	int sub_right[500];

	if (!array || size < 2)
		return;

	half = size / 2;

	for (i = 0; i < half; i++)
		sub_left[i] = array[i];

	for (i = half; i < size; i++)
		sub_right[i - half] = array[i];

	merge_sort(sub_left, half);
	merge_sort(sub_right, size - half);
	merge(array, sub_left, sub_right, size);
}

/**
 * merge - Merges sublists into original array.
 * @array: Array in which @left and @right will be merged.
 * @left: Sub left array
 * @right: Sub right array
 * @size: Size of @array.
 * Return: Void
 */

void merge(int *array, int *left, int *right, size_t size)
{
	int i = 0, j = 0, k = 0;
	int size_left, size_right;

	size_left = size / 2;
	size_right = size - size_left;

	printf("Merging...\n[left]: ");
	print_array(left, size_left);
	printf("[right]: ");
	print_array(right, size_right);

	while (i < size_left && j < size_right)
	{
		if (left[i] < right[j])
			array[k++] = left[i++];
		else
			array[k++] = right[j++];
	}

	while (i < size_left)
	{
		array[k++] = left[i++];
	}
	while (j < size_right)
	{
		array[k++] = right[j++];
	}

	printf("[Done]: ");
	print_array(array, size);
}
