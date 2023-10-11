#include "search_algos.h"
/**
* binary_search - a function that  searches for a value a sorted array of
* integers using the Binary search algorithm
* @array: the array to be searched
* @size: size of the array
* @value: value of array parameters
* Return: -1 if successful
*/
int binary_search(int *array, size_t size, int value)
{
if (array == NULL)
return (-1);
int left = 0;
int right = size - 1;
while (left <= right)
{
int mid = left + (right - left) / 2;
printf("Searching in array: ");
for (int i = left; i <= right; i++)
printf("%d ", array[i]);
printf("\n");
if (array[mid] == value)
return (mid);
else if (array[mid] < value)
left = mid + 1;
else
right = mid - 1;
}
return (-1);
}
