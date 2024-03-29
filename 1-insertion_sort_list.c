#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using Insertion sort algorithm
 *
 * @list: Pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *tmp;

    if (!list || !*list || !(*list)->next)
        return;

    current = (*list)->next;
    while (current)
    {
        tmp = current->next;
        while (current->prev && current->n < current->prev->n)
        {
            current->prev->next = current->next;
            if (current->next)
                current->next->prev = current->prev;
            current->next = current->prev;
            current->prev = current->prev->prev;
            current->next->prev = current;
            if (!current->prev)
                *list = current;
            else
                current->prev->next = current;
            print_list(*list);
        }
        current = tmp;
    }
}
