#include "sort.h"

/**
 * getMax - Retrieves the maximum integer in an array
 * @array: Array where the max number will be found
 * @size: Siz of @array
 * Return: Max Number
 */

int getMax(int *array, int size)
{
	int i, max;

	max = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}

/**
 * countSort - Sorting the array digit by digit depending on exp
 * @array: Array that will be sorted
 * @size: Size of @array
 * @exp: Integer by which array[i] will be divided in order
 * to find specific digit.
 * Return: Void
 */

void countSort(int *array, int size, int exp)
{
	int i;
	int *output;
	int count[10] = {0};


	output = malloc(sizeof(int) * size);
	if (!output)
		return;
	/**
	 * Storing number of occurrences of each digit in
	 * the position of count
	 */
	for (i = 0; i < size; i++)
	{
		count[(array[i] / exp) % 10]++;
	}

	/**
	 * Change count[i] so that it now stores the actual
	 * position of the digit in output[]
	 */
	for (i = 1; i < 10; i++)
	{
		count[i] += count[i - 1];
	}

	/** Storing each value in its respective index in output[] */
	for (i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	/** Pass output[] to array[] with the number correctly sorted */
	for (i = 0; i < size; i++)
	{
		array[i] = output[i];
	}
	free(output);
}


/**
 * radix_sort - Sorts an array of integers in ascending order using the LSD
 * radix sort algorithm
 * @array: Array to be sorted
 * @size: Size of @array
 * Return: Void
 */

void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (size < 2)
		return;

	max = getMax(array, size);
	for (exp = 1; max / exp > 0; exp *= 10)
	{
		countSort(array, size, exp);
		print_array(array, size);
	}
}
