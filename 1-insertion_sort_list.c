#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * @list: lists input
 * Return: Always 0
 */
void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	listint_t *current = (*list)->next;

	while (current != NULL)
	{
		listint_t *next = current->next;
		listint_t *temp = current;

		while (temp->prev != NULL && temp->prev->n > current->n)
		{
			temp = temp->prev;
		}

		if (temp != current)
		{
			current->prev->next = current->next;
			if (current->next != NULL)
				current->next->prev = current->prev;

			if (temp->prev == NULL)
			{
				current->prev = NULL;
				current->next = *list;
				current->next->prev = current;
				*list = current;
			}
			else
			{
				current->next = temp;
				current->prev = temp->prev;
				temp->prev->next = current;
				temp->prev = current;
			}

			print_list(*list);
		}

		current = next;
	}
}
