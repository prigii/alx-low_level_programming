#include "search_algos.h"
/**
* linear_search - a function that  searches for a value in an array of
* integers using the Linear search algorithm
* @array: the array to be searched
* @size: size of the array
* @value: value of array parameters
* Return: -1 if successful
*/
int linear_search(int *array, size_t size, int value)
{
if (array == NULL)
return (-1);
for (int i = 0; i < size; i++)
{
printf("Value checked array[%d] = [%d]\n", i, array[i]);
if (array[i] == value)
return (i);
}

return (-1);
}
