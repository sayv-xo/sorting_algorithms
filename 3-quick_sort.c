#include "sort.h"

/**
 * partition - partition for the quicksort using the Lomuto scheme
 * @array: array to sort
 * @low: lowest index of the partition to sort
 * @hi: highest index of the partition to sort
 * @size: size of the array
 *
 * Return: index of the partition
 */
size_t partition(int *array, ssize_t low, ssize_t hi, size_t size)
{
	ssize_t i, j;
	int swap, pivot;

	pivot = array[hi];
	i = low - 1;
	for (j = low; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap = array[i];
				array[i] = array[j];
				array[j] = swap;
				print_array(array, size);
			}
		}
	}
	if (array[hi] < array[i + 1])
	{
		swap = array[i + 1];
		array[i + 1] = array[hi];
		array[hi] = swap;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quicksort - sorts a partition of an array of integers
 * @array: array to sort
 * @low: lowest index of the partition to sort
 * @hi: highest index of the partition to sort
 * @size: size of the array
 *
 * Return: void
 */
void quicksort(int *array, ssize_t low, ssize_t hi, size_t size)
{
	ssize_t pivot;

	if (low < hi)
	{
		pivot = partition(array, low, hi, size);
		quicksort(array, low, pivot - 1, size);
		quicksort(array, pivot + 1, hi, size);

	}
}

/**
 * quick_sort - sorts an array of integers using Quick sort algorithm
 * @array: The array to sort
 * @size: The size of the array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
