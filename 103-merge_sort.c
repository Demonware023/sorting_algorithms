#include "sort.h"

/**
 * merge - Merge two subarrays of array[].
 * @array: The array to be sorted.
 * @left: Index of the left subarray.
 * @mid: Index of the middle point.
 * @right: Index of the right subarray.
 */
void merge(int *array, size_t left, size_t mid, size_t right)
{
    size_t i, j, k;
    size_t n1 = mid - left + 1;
    size_t n2 = right - mid;

    /* Create temporary arrays */
    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = array[left + i];
    for (j = 0; j < n2; j++)
        R[j] = array[mid + 1 + j];

    printf("[left]: ");
    print_array(L, n1);
    printf("[right]: ");
    print_array(R, n2);

    /* Merge the temp arrays back into array[left..right] */
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if any */
    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if any */
    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }

    printf("[Done]: ");
    print_array(array + left, n1 + n2);

    /* Free temporary arrays */
    free(L);
    free(R);
}

/**
 * merge_sort_recursive - Merge sort algorithm (recursive part).
 * @array: The array to be sorted.
 * @left: Index of the leftmost element of the subarray.
 * @right: Index of the rightmost element of the subarray.
 */
void merge_sort_recursive(int *array, size_t left, size_t right)
{
    if (left < right) {
        /* Same as (left+right)/2, but avoids overflow for large left and right */
        size_t mid = left + (right - left) / 2;

        /* Sort first and second halves */
        merge_sort_recursive(array, left, mid);
        merge_sort_recursive(array, mid + 1, right);

        /* Merge the sorted halves */
        printf("Merging...\n");
        merge(array, left, mid, right);
        printf("[Done]: ");
        print_array(array + left, right - left + 1);
    }
}

/**
 * merge_sort - Sorts an array of integers in ascending order using the Merge sort algorithm.
 * @array: The array to be sorted.
 * @size: Number of elements in the array.
 */
void merge_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    printf("Merging...\n");
    merge_sort_recursive(array, 0, size - 1);
    printf("[Done]: ");
    print_array(array, size);
}
