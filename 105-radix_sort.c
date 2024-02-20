#include "sort.h"

/**
 * get_max - Get the maximum number in an array.
 * @array: The array.
 * @size: The size of the array.
 *
 * Return: The maximum number in the array.
 */
int get_max(int *array, size_t size)
{
    int max = array[0];
    size_t i;

    for (i = 1; i < size; i++)
        if (array[i] > max)
            max = array[i];
    return max;
}

/**
 * counting_sort_radix - Counting sort for radix sort.
 * @array: The array to be sorted.
 * @size: Number of elements in the array.
 * @exp: The digit to sort by.
 */
void counting_sort_radix(int *array, size_t size, int exp)
{
    int *output = malloc(size * sizeof(int));
    int count[10] = {0};
    size_t i;

    /* Store count of occurrences in count[] */
    for (i = 0; i < size; i++)
        count[(array[i] / exp) % 10]++;

    /* Change count[i] so that count[i] now contains actual position of
     * this digit in output[] */
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    /* Build the output array */
    for (i = size - 1; i > 0; i--)
    {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }
    output[count[(array[i] / exp) % 10] - 1] = array[i];

    /* Copy the output array to array[], so that array[] now
     * contains sorted numbers according to current digit */
    for (i = 0; i < size; i++)
        array[i] = output[i];

    print_array(array, size);
    free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order using the
 * Radix sort algorithm.
 * @array: The array to be sorted.
 * @size: Number of elements in the array.
 */
void radix_sort(int *array, size_t size)
{
    int max;
    int exp;

    if (array == NULL || size < 2)
        return;

    /* Find the maximum number to know the number of digits */
    max = get_max(array, size);

    /* Do counting sort for every digit. Note that instead of passing digit
     * number, exp is passed. exp is 10^i where i is current digit number */
    for (exp = 1; max / exp > 0; exp *= 10)
        counting_sort_radix(array, size, exp);
}
