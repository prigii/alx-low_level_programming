#include <stdio.h>

int binary_search(int *array, int low, int high, int value) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        printf("Comparing element at index %d\n", mid);

        if (array[mid] == value) {
            return mid;
        } else if (array[mid] < value) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1; // Value not found
}

int exponential_search(int *array, size_t size, int value) {
    if (array == NULL || size == 0) {
        return -1; // Invalid input or empty array
    }

    if (array[0] == value) {
        return 0; // Value found at the beginning
    }

    int range = 1;

    while (range < size && array[range] < value) {
        printf("Comparing element at index %d\n", range);
        range *= 2;
    }

    int high = range < size ? range : size - 1;
    int low = range / 2;

    printf("Searching in the range [%d, %d]\n", low, high);

    return binary_search(array, low, high, value);
}
