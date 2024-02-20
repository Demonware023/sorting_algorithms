#include "sort.h"

/**
 * swap - Swaps two integers in an array.
 * @array: The array containing the integers.
 * @i: The first integer to be swapped.
 * @j: The second integer to be swapped.
 * @size: The size of the array.
 */
void swap_elements(int *array, size_t i, size_t j, size_t size)
{
    int temp;

    temp = array[i];
    array[i] = array[j];
    array[j] = temp;
    print_array(array, size);
}

/**
 * sift_down - Repairs the heap whose root element is at index 'start', assuming
 * the heaps rooted at its children are valid.
 * @array: The array to be sorted.
 * @start: The index of the root of the heap.
 * @end: The last index of the array.
 * @size: The size of the array.
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
    size_t root = start;
    size_t child;
    size_t swap;

    while (root * 2 + 1 <= end)
    {
        child = root * 2 + 1;
        swap = root;
        if (array[swap] < array[child])
            swap = child;
        if (child + 1 <= end && array[swap] < array[child + 1])
            swap = child + 1;
        if (swap == root)
            return;
        swap_elements(array, root, swap, size);
        root = swap;
    }
}

/**
 * heapify - Creates a heap from an array.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void heapify(int *array, size_t size)
{
    int start;

    start = (size - 2) / 2;
    while (start >= 0)
    {
        sift_down(array, start, size - 1, size);
        start--;
    }
}

/**
 * heap_sort - Sorts an array of integers in ascending order using the
 * Heap sort algorithm.
 * @array: The array to be sorted.
 * @size: Number of elements in the array.
 */
void heap_sort(int *array, size_t size)
{
    size_t end;

    if (array == NULL || size < 2)
        return;

    heapify(array, size);
    end = size - 1;
    while (end > 0)
    {
        swap_elements(array, end, 0, size);
        end--;
        sift_down(array, 0, end, size);
    }
}
