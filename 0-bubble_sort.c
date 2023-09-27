#include "sort.h"

/**
 * bubble_sort - Sort an array of integers using bubble sort
 * @array: Array
 * @size: size of array
 * Return: Nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, swap;
	int tmp;

	if (array == NULL || size < 2)
		return;

	swap = 1;
	while (swap)
	{
		swap = 0;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				swap++;
				print_array(array, size);
			}
		}
	}
}
