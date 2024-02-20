#include "sort.h"

/**
 * swap - Swaps two integers in an array.
 * @array: The array containing the integers.
 * @i: The first integer to be swapped.
 * @j: The second integer to be swapped.
 * @size: The size of the array.
 */
void swap_hoare(int *array, size_t i, size_t j, size_t size)
{
    int temp;

    temp = array[i];
    array[i] = array[j];
    array[j] = temp;
    print_array(array, size);
}

/**
 * hoare_partition - Order a subset of an array of integers according to
 *                   the Hoare partition scheme.
 * @array: The array of integers.
 * @size: The size of the array.
 * @low: The lowest index of the subset to order.
 * @high: The highest index of the subset to order.
 *
 * Return: The final partition index.
 */
int hoare_partition(int *array, size_t size, int low, int high)
{
    int pivot = array[high];
    int i = low - 1;
    int j = high + 1;

    while (1)
    {
        do {
            i++;
        } while (array[i] < pivot);
        do {
            j--;
        } while (array[j] > pivot);
        if (i >= j)
            return (j);
        swap_hoare(array, i, j, size);
    }
}

/**
 * quick_sort_hoare_recursion - Implement the quicksort algorithm through
 *                              recursion.
 * @array: An array of integers.
 * @size: The size of the array.
 * @low: The lowest index of the array subset to order.
 * @high: The highest index of the array subset to order.
 */
void quick_sort_hoare_recursion(int *array, size_t size, int low, int high)
{
    int pi;

    if (low < high)
    {
        pi = hoare_partition(array, size, low, high);
        quick_sort_hoare_recursion(array, size, low, pi);
        quick_sort_hoare_recursion(array, size, pi + 1, high);
    }
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending
 *                    order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Hoare partition scheme. Prints the
 * array after each swap of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_hoare_recursion(array, size, 0, size - 1);
}
