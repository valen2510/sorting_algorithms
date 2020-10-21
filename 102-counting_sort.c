#include "sort.h"
/**
 * counting_sort - function that sorts an array of integers in
 * ascending order using the Counting sort algorithm
 * @array: array of integers
 * @size: size of array.
 */
void counting_sort(int *array, size_t size)
{
	int *count_array, *output_array;
	unsigned int i, k;

	if (!array || size < 2)
		return;

	k = array[0];
	for (i = 1; i < size; i++)
	{
		if ((int)k < array[i])
			k = array[i];
	}
	count_array = malloc(sizeof(int) * (k + 1));
	if (!count_array)
		return;
	for (i = 0; i <= k; i++)
		count_array[i] = 0;

	for (i = 0; i < size; i++)
		count_array[array[i]]++;

	for (i = 0; i < k; i++)
		count_array[i + 1] += count_array[i];
	print_array(count_array, k + 1);

	output_array = malloc(sizeof(int) * size);
	if (!output_array)
		return;

	for (i = 0; i < size; i++)
	{
		output_array[count_array[array[i]] - 1] = array[i];
		count_array[array[i]]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output_array[i];

	free(count_array);
	free(output_array);
}
