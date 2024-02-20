#include "sort.h"

/**
 * swap - Swaps two integers in an array.
 * @array: The array containing the integers.
 * @i: The first integer to be swapped.
 * @j: The second integer to be swapped.
 * @size: The size of the array.
 */
void swap_bitonic(int *array, size_t i, size_t j, size_t size)
{
    int temp;

    temp = array[i];
    array[i] = array[j];
    array[j] = temp;
    print_array(array, size);
}

/**
 * bitonic_compare - Compares and swaps two integers in a bitonic sequence.
 * @array: The array containing the integers.
 * @i: The first integer to be compared.
 * @j: The second integer to be compared.
 * @dir: The direction to sort in.
 * @size: The size of the array.
 */
void bitonic_compare(int *array, size_t i, size_t j, size_t size)
{
    if (array[i] > array[j])
        swap_bitonic(array, i, j, size);
}

/**
 * bitonic_merge - Merges two bitonic sequences.
 * @array: The array containing the sequences.
 * @low: The starting index of the first sequence.
 * @cnt: The size of each sequence.
 * @dir: The direction to sort in.
 * @size: The size of the array.
 */
void bitonic_merge(int *array, size_t low, size_t cnt, int dir, size_t size)
{
    size_t k, i;

    if (cnt > 1)
    {
        k = cnt / 2;
        for (i = low; i < low + k; i++)
            bitonic_compare(array, i, i + k, size);
        bitonic_merge(array, low, k, dir, size);
        bitonic_merge(array, low + k, k, dir, size);
        if (dir == 0)
            reverse(array + low, cnt);
    }
}

/**
 * bitonic_sort_recursive - Sorts a bitonic sequence in ascending order.
 * @array: The array containing the sequence.
 * @low: The starting index of the sequence.
 * @cnt: The size of the sequence.
 * @dir: The direction to sort in.
 * @size: The size of the array.
 */
void bitonic_sort_recursive(int *array, size_t low, size_t cnt, int dir, size_t size)
{
    size_t k;

    if (cnt > 1)
    {
        k = cnt / 2;
        bitonic_sort_recursive(array, low, k, 1, size);  /* sort first half in ascending order */
        bitonic_sort_recursive(array, low + k, k, 0, size);  /* sort second half in descending order */
        bitonic_merge(array, low, cnt, dir, size);
    }
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order using the
 * Bitonic sort algorithm.
 * @array: The array to be sorted.
 * @size: Number of elements in the array.
 */
void bitonic_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    bitonic_sort_recursive(array, 0, size, 1, size);
}

void reverse(int *array, size_t cnt)
{
    size_t start = 0;
    size_t end = cnt - 1;
    int temp;

    while (start < end)
    {
        temp = array[start];
        array[start] = array[end];
        array[end] = temp;
        start++;
        end--;
    }
}
