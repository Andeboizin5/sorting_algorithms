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

	listint_t *curr = (*list)->next;

	while (curr != NULL)
	{
		listint_t *temp = curr->prev;

		while (temp != NULL && temp->n > curr->n)
		{
			if (curr->next != NULL)
				curr->next->prev = temp;
			temp->next = curr->next;
			curr->next = temp;
			curr->prev = temp->prev;
			temp->prev = curr;
			if (curr->prev != NULL)
				curr->prev->next = curr;
			else
				*list = curr;
			temp = curr->prev;
			print_list(*list);
		}
		curr = curr->next;
	}
}
