#include <stdio.h>

int binary_search_recursive(int *array, int low, int high, int value) {
    if (low > high) {
        return -1; // Value not found
    }

    int mid = low + (high - low) / 2;

    printf("Searching in the range [%d, %d]\n", low, high);

    if (array[mid] == value) {
        return mid; // Value found at index mid
    } else if (array[mid] < value) {
        return binary_search_recursive(array, mid + 1, high, value);
    } else {
        return binary_search_recursive(array, low, mid - 1, value);
    }
}

int advanced_binary(int *array, size_t size, int value) {
    if (array == NULL || size == 0) {
        return -1; // Invalid input or empty array
    }

    return binary_search_recursive(array, 0, size - 1, value);
}
