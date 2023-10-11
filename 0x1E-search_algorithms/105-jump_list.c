#include "search_algos.h"


/* Define a struct for the linked list node */


listint_t *jump_list(listint_t *list, size_t size, int value) {
    if (list == NULL || size == 0) {
        return NULL; // Invalid input or empty list
    }

    int jump = (int)sqrt(size); // Calculate the jump step
    listint_t *current = list;
    listint_t *prev = NULL;

    while (current->n < value) {
        printf("Comparing element: %d\n", current->n);

        prev = current;

        for (int i = 0; i < jump; i++) {
            if (current->next != NULL) {
                current = current->next;
            } else {
                break;
            }
        }

        if (current == NULL) {
            break;
        }
    }

    // Perform linear search in the current block
    while (prev != NULL && prev->n < value) {
        printf("Comparing element: %d\n", prev->n);
        prev = prev->next;
    }

    if (prev != NULL && prev->n == value) {
        return prev; // Element found
    } else {
        return NULL; // Element not found
    }
}
