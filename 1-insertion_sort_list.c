#include "sort.h"

/*
 * insertion_sort_list - sorts a doubly linked list of integers
 * @list: list input
 * Return: Always 0
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current)
	{
		prev = current->prev;
		while (prev && prev->n > current->n)
		{
			prev->next = current->next;
			if (current->next)
				current->next->prev = prev;

			current->next = prev;
			current->prev = prev->prev;
			prev->prev = current;

			if (current->prev)
				current->prev->next = current;
			else
				*list = current;
			print_list(*list);
			prev = current->prev;
		}
		current = current->next;
	}
}
