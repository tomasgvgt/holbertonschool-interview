#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has a cycle in it
 * @list: start of the list
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *aux_s = list, *aux_f = list;

	while (aux_s && aux_f && aux_f->next)
	{
		aux_s = aux_s->next;
		aux_f = aux_f->next->next;
		if (aux_s == aux_f)
		{
			return (1);
		}
	}
	return (0);
}
