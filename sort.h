#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>


/* Doubly Linked List Structure */

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;


/* Function prototypes */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void swap(int *a, int *b);
size_t lomuto_partition(int *array, int low, int high, size_t size);
void quicksort(int *array, int low, int high, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
void merge(int *array, size_t left, size_t mid, size_t right);
void merge_sort_recursive(int *array, size_t left, size_t right);
void swap_elements(int *array, size_t i, size_t j, size_t size);
void heap_sort(int *array, size_t size);
void heapify(int *array, size_t size);
void sift_down(int *array, size_t start, size_t end, size_t size);
void swap_bitonic(int *array, size_t i, size_t j, size_t size);
void bitonic_compare(int *array, size_t i, size_t j, size_t size);
void bitonic_merge(int *array, size_t low, size_t cnt, int dir, size_t size);
void bitonic_sort_recursive(int *array, size_t low, size_t cnt, int dir, size_t size);
void bitonic_sort(int *array, size_t size);
void reverse(int *array, size_t cnt);
void swap_hoare(int *array, size_t i, size_t j, size_t size);
int hoare_partition(int *array, size_t size, int low, int high);
void quick_sort_hoare_recursion(int *array, size_t size, int low, int high);
void quick_sort_hoare(int *array, size_t size);


#endif
