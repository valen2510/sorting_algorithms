#include "sort.h"
/**
 * bubble_sort - function that sorts an array of integers using
 * bubble sort algorithm.
 * @array: array of integers.
 * @size: array size.
 **/
void bubble_sort(int *array, size_t size)
{
	/*Declare varaibles of iterations and temp variable for swap*/
	unsigned int i, j;
	int tmp = 0;

	/*Loop to transverse array size*/
	for (i = 0; i < size; i++)
	{
		/*Nested loop for comparisons between integers in the array*/
		for (j = 0; j + 1 + i < size; j++)
		{
			/*Compare actual position with next position in array*/
			if (array[j] > array[j + 1])
			{
				/*
				* Swap integer values of position
				* if the condition is true and print array
				*/
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
