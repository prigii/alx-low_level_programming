#include "search_algos.h"

skiplist_t *linear_skip(skiplist_t *list, int value) {
    if (list == NULL) {
        return NULL; // Invalid input
    }

    skiplist_t *current = list;
    skiplist_t *express = NULL;

    while (current->n < value) {
        if (current->express == NULL) {
            printf("Value not found in the list.\n");
            return NULL; // Value not found
        }

        printf("Value checked at index [%lu] = [%d]\n", current->express - list, current->express->n);

        express = current->express;

        if (express->n >= value) {
            break;
        }

        current = express;
    }

    printf("Value found between indexes [%lu] and [%lu]\n", current - list, express - list);

    while (current != NULL && current->n <= value) {
        printf("Value checked at index [%lu] = [%d]\n", current - list, current->n);

        if (current->n == value) {
            return current;
        }

        current = current->next;
    }

    printf("Value not found in the list.\n");

    return NULL; // Value not found
}
