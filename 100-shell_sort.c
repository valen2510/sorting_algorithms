#include "sort.h"
/**
 * shell_sort - function that sorts an array of integers in ascending order
 * using the Shell sort algorithm, and the Knuth sequence.
 * @array: array of integers
 * @size: array size.
 */
void shell_sort(int *array, size_t size)
{
	unsigned int i, j, interval;
	int insert_value;

	/* Use Knuth sequence for intervals. Reach the biggest interval possible.*/
	for (interval = 1; interval < size / 3; interval = interval * 3 + 1)
		;
	/* First loop to decrement interval after comparisons and swapping.*/
	while (interval > 0)
	{
		/* Second loop to tranverse array with intervals*/
		for (i = interval; i < size; i++)
		{
			/* Set interval value in array as insert value to be inserted.*/
			insert_value = array[i];

			/*
			* Third loop to check elements to shift towards right
			* and compare with insert_value. In case insert value is smaller
			* than integer at smaller position, then swap integer at j.
			*/
			j = i;
			while (j >= interval && insert_value <= array[j - interval])
			{
				array[j] = array[j - interval];
				j -= interval;
			}
			/*
			* Insert value at the last position of j.
			* (The smaller position of the interval).
			*/
			array[j] = insert_value;
		}
		/* Decrease interval and print array. */
		interval /= 3;
		print_array(array, size);
	}
}
