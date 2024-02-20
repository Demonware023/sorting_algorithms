#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using the
 * Counting sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void counting_sort(int *array, size_t size)
{
    int *count, *sorted, max = 0;
    size_t i;

    if (!array || size < 2)
        return;

    for (i = 0; i < size; i++)
        if (array[i] > max)
            max = array[i];

    count = calloc(max + 1, sizeof(*count));
    if (!count)
        return;

    for (i = 0; i < size; i++)
        count[array[i]] += 1;

    for (i = 1; i <= (size_t)max; i++)
        count[i] += count[i - 1];

    print_array(count, max + 1);

    sorted = malloc(size * sizeof(*sorted));
    if (!sorted)
    {
        free(count);
        return;
    }

    for (i = 0; i < size; i++)
    {
        sorted[count[array[i]] - 1] = array[i];
        count[array[i]] -= 1;
    }

    for (i = 0; i < size; i++)
        array[i] = sorted[i];

    free(sorted);
    free(count);
}
