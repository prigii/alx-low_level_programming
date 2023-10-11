#include <stdio.h>

int interpolation_search(int *array, size_t size, int value) {
    if (array == NULL || size == 0) {
        return -1; // Invalid input or empty array
    }

    int low = 0;
    int high = size - 1;

    while (low <= high && value >= array[low] && value <= array[high]) {
        if (low == high) {
            printf("Comparing element at index %d\n", low);
            if (array[low] == value) {
                return low;
            }
            return -1; // Value not found
        }

        size_t pos = low + (((double)(high - low) / (array[high] - array[low])) * (value - array[low]));

        printf("Comparing element at index %zu\n", pos);

        if (array[pos] == value) {
            return pos; // Value found
        }

        if (array[pos] < value) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }

    return -1; // Value not found
}
