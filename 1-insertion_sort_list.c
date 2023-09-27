#include "sort.h"

/**
 * insertion_sort_list - Sort integers of a doubly linked list
 *						 in ascending order
 * @list: Doubly linked list
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *new_node, *next_node;

	if (list == NULL || list == NULL)
		return;
	new_node = (*list)->next;
	while (new_node != NULL)
	{
		next_node = new_node->next;
		while (new_node->prev != NULL && new_node->prev->n > new_node->n)
		{
			new_node->prev->next = new_node->next;
			if (new_node->next != NULL)
				new_node->next->prev = new_node->prev;
			new_node->next = new_node->prev;
			new_node->prev = new_node->next->prev;
			new_node->next->prev = new_node;
			if (new_node->prev == NULL)
				*list = new_node;
			else
				new_node->prev->next = new_node;
			print_list(*list);
		}
		new_node = next_node;
	}
}
