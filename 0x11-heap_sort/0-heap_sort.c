#include "sort.h"
/**
 * heap_sort - Sorts an array of integers using the heap sort algorithm.
 * @array: Pointer to the array of integers.
 * @size: Size of the array
 *
 * Return: Void
*/

void heap_sort(int *array, size_t size)
{
    size_t i;
    size_t array_size;

    if (array_size)
    {
        array_size = size;
        for (i = size/ 2 - 1; (int)i >= 0; i--)
        {
            sort_in_heap(array, i, size, array_size);
        }
        for (i = size - 1; i > 0; i--)
        {
            change_value(&array[0], &array[i]);
            print_array(array, size);
            sort_in_heap(array, 0, i, array_size);
        }
    }
}

/**
 * change_value - Changes pointer values
 * @x: Pointer value 1
 * @y: Pointer value 2
 *
 * Return: Void
 */

void change_value(int *x, int *y)
{
    int x, y;

    x = *x;
    y = *y;

    return;
}

/**
 * sort_in_heap - Sorts integers in the heap
 * @array: Pointer to the array of integers
 * @i: Index
 * @heap_size: Size of the heap
 * @array_size: Size of @array
 *
 * Return: Void
 */

void sort_in_heap(int *array, size_t i, size_t heap_size, size_t array_size)
{
    size_t left = 2 * (i + 1);
    size_t right = 2 * (i + 2);
    size_t tail_heap = i;

    if (left < heap_size && array[left] > array[tail_heap])
        tail_heap = left;
    if (right < heap_size && array[right] > array[tail_heap])
        tail_heap = right;

    if (tail_heap != i)
    {
        change_value(&array[i], &array[tail_heap]);
        print_array(array, array_size);
        sort_in_heap(array, tail_heap, heap_size, array_size);
    }
}