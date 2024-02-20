#include "deck.h"
#include <stdlib.h>
#include <string.h>

/**
 * card_value - get the integer value of a card
 * @card: pointer to the card to get the value of
 *
 * Return: integer value of the card
 */
int card_value(const card_t *card)
{
    int i;
    char *values[] = {"Ace", "2", "3", "4", "5", "6", "7",
                      "8", "9", "10", "Jack", "Queen", "King"};

    for (i = 0; i < 13; i++)
    {
        if (!strcmp(values[i], card->value))
            return (i);
    }
    return (0);
}

/**
 * swap_nodes - swap two nodes in a doubly linked list
 * @list: double pointer to the beginning of the list
 * @node1: first node to swap
 * @node2: second node to swap
 */
void swap_nodes(deck_node_t **list, deck_node_t *node1, deck_node_t *node2)
{
    node1->next = node2->next;
    if (node2->next)
        node2->next->prev = node1;
    node2->prev = node1->prev;
    node2->next = node1;
    node1->prev = node2;
    if (node2->prev)
        node2->prev->next = node2;
    else
        *list = node2;
}

/**
 * partition - order a subset of a doubly linked list of integers in such
 * a way that all elements less than the pivot come before all elements
 * greater than the pivot
 * @list: double pointer to the beginning of the list
 * @lo: leftmost node of the subset to order
 * @hi: rightmost node of the subset to order
 *
 * Return: pointer to the 'pivot' node
 */
deck_node_t *partition(deck_node_t **list, deck_node_t *lo, deck_node_t *hi)
{
    deck_node_t *pivot = lo;
    deck_node_t *node = hi->next;

    while (node != lo)
    {
        node = node->prev;
        if (node->card->kind > pivot->card->kind ||
            (node->card->kind == pivot->card->kind &&
             card_value(node->card) > card_value(pivot->card)))
        {
            if (node == hi)
                hi = hi->prev;
            swap_nodes(list, node, hi->next);
        }
    }
    if (node == hi)
        hi = hi->prev;
    swap_nodes(list, node, hi->next);
    return (hi->next);
}

/**
 * quick_sort - sort a doubly linked list of integers in ascending
 * order using the Quick sort algorithm
 * @list: double pointer to the beginning of the list
 * @lo: leftmost node of the subset to order
 * @hi: rightmost node of the subset to order
 */
void quick_sort(deck_node_t **list, deck_node_t *lo, deck_node_t *hi)
{
    deck_node_t *pivot;

    if (lo && lo != hi && lo != hi->next)
    {
        pivot = partition(list, lo, hi);
        quick_sort(list, lo, pivot->prev);
        quick_sort(list, pivot->next, hi);
    }
}

/**
 * sort_deck - sort a deck of cards
 * @deck: the deck to sort
 */
void sort_deck(deck_node_t **deck)
{
    deck_node_t *node = *deck;

    if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
        return;
    while (node->next)
        node = node->next;
    quick_sort(deck, *deck, node);
}
