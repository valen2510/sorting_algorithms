#include "sort.h"
/**
 * selection_sort - function that sorts an array of integers in
 * ascending order using the Selection sort algorithm.
 * @array: array of integers.
 * @size: size of array.
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i, j, tmp, min;

	if (size < 2)
		return;

	/*
	 * Transverse the array and set the first element as the minimum.
	 */
	for (i = 0; i < size; i++)
	{
		min = i;
		/*
		 * Nested loop that starts from a position after i and
		 * transverse the array
		 */
		for (j = i + 1; j < size; j++)
		{
			/*
			* Compare the minimum with every element in the array
			* in case is true, change minimun element.
			*/
			if (array[min] > array[j])
				min = j;
		}

		/*
		* Condition in case a new minimum element have been found, then swap.
		*/
		if (min != i)
		{
			tmp = array[i];
			array[i] = array[min];
			array[min] = tmp;
			print_array(array, size);
		}
	}
}
