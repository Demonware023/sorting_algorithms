#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order
 *              using the Shell sort algorithm with the Knuth sequence
 * @array: Array to be sorted
 * @size: Size of the array
 */
void shell_sort(int *array, size_t size)
{
    size_t gap = 1, i, j;
    int temp;

    /* Calculate the initial gap */
    while (gap < size / 3)
        gap = gap * 3 + 1;

    /* Start sorting with decreasing gaps */
    for (; gap > 0; gap /= 3)
    {
        /* Perform insertion sort for elements at a gap */
        for (i = gap; i < size; i++)
        {
            /* Insert array[i] into the sorted sequence array[0..i-gap-1] */
            temp = array[i];

            for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
            {
                array[j] = array[j - gap];
            }

            array[j] = temp;
        }

        /* Print array after decreasing the gap */
        print_array(array, size);
    }
}
