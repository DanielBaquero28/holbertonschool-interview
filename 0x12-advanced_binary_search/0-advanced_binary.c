#include "search_algos.h"

void print_array(int *array, int left, int right);
int binary_search(int *array, int left, int right, int value);

/**
 * advanced_binary - Searches for @value in @array of size @size
 * @array: Pointer to the array of integers
 * @size: Size of @array
 * @value: Value of integer that we'll be looking for.
 * Return: Index of first @value if present, otherwise -1
 */

int advanced_binary(int *array, size_t size, int value)
{
	int advanced_index;

	if (!array)
		return (-1);
	advanced_index = binary_search(array, 0, size - 1, value);

	return (advanced_index);
}

/**
 * binary_search - Searches for @value in @array
 * @array: Pointer to the array of integers
 * @left: Index of first element looking in a sub_array
 * @right: Index of last element looking in a sub_array
 * @value: Value that we'll looking for
 * Return: Index of first element that we're looking for, otherwise -1
 */

int binary_search(int *array, int left, int right, int value)
{
	if (right >= left)
	{
		int mid = left + (right - left) / 2;

		print_array(array, left, right);
		/**
		 * Checking if value is in the middle of the array
		 * or sub_array.
		 */

		if (array[mid] == value)
		{
			/**
			 * Checking if value has duplicates in positions
			 * before it.
			 */
			if (array[mid - 1] == value)
				return (binary_search(array, left, mid, value));
			return (mid);
		}

		/**
		 * Checking if value is in the lower half of the array
		 * or sub_array.
		 */
		if (array[mid] > value)
			return (binary_search(array, left, mid, value));

		/**
		 * Checking if value is in the upper half of the array
		 * or sub_array
		 */
		else
			return (binary_search(array, mid + 1, right, value));
	}
	/**
	 * If value is not present in array or if array is NULL
	 */
	else
		return (-1);
}

/**
 * print_array - Prints @array
 * @array: Array that will be printed
 * @left: First position of the array
 * @right: Last position of the array
 *
 * Return: Void
 */

void print_array(int *array, int left, int right)
{
	int i;

	printf("Searching in array:");
	for (i = left; i < right; i++)
		printf(" %d,", array[i]);
	printf(" %d\n", array[i]);
}
