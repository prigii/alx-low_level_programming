#include <stdio.h>
#include <math.h>
/**
 * jump-search -
 * @array:
 * @size:
 * @value:
 * @sqrt: 
*/

int jump_search(int *array, size_t size, int value) {
    if (array == NULL || size == 0) {
        return -1; // Invalid input or empty array
    }

    int jump = (int)sqrt(size); // Calculate the jump step
    int prev = 0;

    while (array[prev] < value) {
        printf("Comparing element at index %d\n", prev);

        if (prev + jump >= size) {
            jump = size - prev - 1; // Adjust the jump step if we're near the end
        }

        prev += jump;

        if (prev >= size) {
            break; // Prevent going beyond the array boundaries
        }
    }

    // Perform a linear search in the current block
    for (int i = prev; i >= 0 && array[i] >= value; i--) {
        printf("Comparing element at index %d\n", i);

        if (array[i] == value) {
            return i; // Element found
        }
    }

    return -1; // Element not found
}

int main(void) {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21};
    size_t size = sizeof(arr) / sizeof(arr[0]);
    int value = 13;
    int result = jump_search(arr, size, value);

    if (result != -1) {
        printf("Value %d found at index %d\n", value, result);
    } else {
        printf("Value %d not found in the array\n", value);
    }

    return 0;
}
