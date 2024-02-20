#ifndef DECK_H
#define DECK_H

typedef enum kind_e
{
    SPADE = 0,
    HEART,
    CLUB,
    DIAMOND
} kind_t;

/**
 * struct card_s - Playing card
 *
 * @value: Value of the card
 * From "Ace" to "King"
 * @kind: Kind of the card
 */
typedef struct card_s
{
    const char *value;
    const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Deck of card
 *
 * @card: Pointer to the card of the node
 * @prev: Pointer to the previous node of the list
 * @next: Pointer to the next node of the list
 */
typedef struct deck_node_s
{
    const card_t *card;
    struct deck_node_s *prev;
    struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);
int card_value(const card_t *card);
void swap_nodes(deck_node_t **list, deck_node_t *node1, deck_node_t *node2);
void swap_nodes(deck_node_t **list, deck_node_t *node1, deck_node_t *node2);
deck_node_t *partition(deck_node_t **list, deck_node_t *lo, deck_node_t *hi);
void quick_sort(deck_node_t **list, deck_node_t *lo, deck_node_t *hi);
void sort_deck(deck_node_t **deck);


#endif
