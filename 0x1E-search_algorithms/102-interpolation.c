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

int main(void) {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21};
    size_t size = sizeof(arr) / sizeof(arr[0]);
    int value = 13;
    int result = interpolation_search(arr, size, value);

    if (result != -1) {
        printf("Value %d found at index %d\n", value, result);
    } else {
        printf("Value %d not found in the array\n", value);
    }

    return 0;
}
