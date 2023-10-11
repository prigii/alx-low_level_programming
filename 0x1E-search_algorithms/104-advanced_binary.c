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

int main(void) {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21};
    size_t size = sizeof(arr) / sizeof(arr[0]);
    int value = 13;
    int result = advanced_binary(arr, size, value);

    if (result != -1) {
        printf("Value %d found at index %d\n", value, result);
    } else {
        printf("Value %d not found in the array\n", value);
    }

    return 0;
}
