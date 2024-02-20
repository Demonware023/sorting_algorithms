#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Double pointer to the head of the list
 * @node: Node to swap with its next node
 */
void swap_nodes(listint_t **list, listint_t *node)
{
    listint_t *tmp = node->next;

    if (node->prev)
        node->prev->next = tmp;
    else
        *list = tmp;
    tmp->prev = node->prev;
    if (tmp->next)
        tmp->next->prev = node;
    node->next = tmp->next;
    node->prev = tmp;
    tmp->next = node;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm
 * @list: Double pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
    char swapped = 1;
    listint_t *node;

    if (!list || !*list || !(*list)->next)
        return;

    while (swapped)
    {
        swapped = 0;
        for (node = *list; node && node->next; node = node->next)
        {
            if (node->n > node->next->n)
            {
                swap_nodes(list, node);
                print_list((const listint_t *)*list);
                swapped = 1;
            }
        }
        if (!swapped)
            break;
        swapped = 0;
        for (node = node->prev; node && node->prev; node = node->prev)
        {
            if (node->prev->n > node->n)
            {
                swap_nodes(list, node->prev);
                print_list((const listint_t *)*list);
                swapped = 1;
            }
        }
    }
}
