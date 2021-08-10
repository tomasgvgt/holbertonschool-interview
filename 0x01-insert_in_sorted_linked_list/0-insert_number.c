#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - inserts a number into a sorted singly linked list.
 * @head: double pointer to head
 * @number: number to insert
 * Return: the address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *node;
	listint_t *tmp;

	tmp = *head;
	node = malloc(sizeof(listint_t));
	if (node == NULL)
		return (NULL);
	
	node->n = number;
	node->next = NULL;
	if (tmp->next == NULL)
		tmp->next = node;

	while (node->n > tmp->n)
	{
		if (tmp->next == NULL)
		{
			tmp->next = node;
			return (node);
		}
		if (tmp->next->n >= node->n)
		{
			node->next = tmp->next;
			tmp->next = node;
			return (node);
		}
		tmp = tmp->next;
	}
	return(node);
}
