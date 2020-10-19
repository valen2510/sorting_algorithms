#include "sort.h"
/**
 * insertion_sort_list - function that sorts a doubly linked list of
 * integers in ascending order using the Insertion sort algorithm.
 * @list: double linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *previous;

	if (!list || !(*list))
		return;
	/**
	 * First loop to transverse the double linked list
	 **/
	for (current = (*list)->next; current; current = current->next)
	{
		/**
		* Second loop to compare the integers on the current position
		* with the previuos one if exist
		**/
		while (current->prev && current->prev->n > current->n)
		{
			/**
			* If the condition is True, then the nodes switch places
			**/
			previous = current->prev;
			current->prev = previous->prev;
			previous->prev = current;
			previous->next = current->next;
			current->next = previous;
			/**
			* Condition to check in case of current node reach the first position
			**/
			if (current->prev)
				current->prev->next = current;
			else
				*list = current;
			/**
			* Condition in case the previous node reach the last position
			**/
			if (previous->next)
				previous->next->prev = previous;
			print_list(*list);
		}
	}
}
