#include "sort.h"
/**
 * cocktail_sort_list - function that sorts a doubly linked list of integers in
 * ascending order using the Cocktail shaker sort algorithm
 * @list: double linked list of integers
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current = NULL;
	int swapped = 1;

	if (!list || !(*list) || !(*list)->next)
		return;

	while (swapped)
	{
		swapped = 0;
		for (current = (*list)->next; current->next; current = current->next)
		{
			if (current->prev->n > current->n)
				swapped = swap(list, current);
		}
		for (; current->prev; current = current->prev)
		{
			if (current->prev->n > current->n)
			{
				swapped = swap(list, current);

				if (current->next)
				current = current->next;
			}
		}
	}
}
/**
 * swap - function that swaps current and previous elements
 * @list: double linked list of integers.
 * @current: current element.
 * Return: 1 (Success).
 */
int swap(listint_t **list, listint_t *current)
{
	listint_t *previous;

	previous = current->prev;
	previous->next = current->next;
	current->prev = previous->prev;
	previous->prev = current;
	current->next = previous;
	if (current->prev)
		current->prev->next = current;
	else
		(*list) = current;
	if (previous->next)
		previous->next->prev = previous;

	print_list(*list);
	return (1);
}
