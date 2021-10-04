#include "lists.h"
#include <stdio.h>
#include <stdlib.h>


/**
 * reverse_listint - function that reverses a listint_t linked list.
 * @head: is a pointer to the head of the list
 * Return: void
 */
void reverse(listint_t **head)
{
	listint_t *next = NULL;
	listint_t *prev = NULL;
	listint_t *current = *head;

	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head = prev;
}

listint_t *findMiddle(listint_t **head) {
  listint_t *fast = *head;
  listint_t *slow = *head;

  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }

  return (slow);
}

/**
 * compareLists - compares two lists.
 * @head: pointer to head
 * @middle: pointer to the middle of the list
 * Return: void
 */
int compareLists(listint_t **head, listint_t *middle) {
  while (middle != NULL) {
    if (middle->n != (*head)->n)
      return (0);
    *head = (*head)->next;
    middle = middle->next;
  }
  return (1);  
}

/**
 * is_palindrome - Checks if a singly linked list is palindrome
 * @head: double pointer of first node of listint_t list.
 * Return: 0 if not a palindrome, 1 if palindrome
 */
int is_palindrome(listint_t **head) {
  listint_t *middle = NULL;

  if (head == NULL)
    return (0);

  if (*head == NULL)
    return (1);

  middle = findMiddle(head);
  reverse(&middle);
  if (compareLists(head, middle) == 1)
    return (1);
  return (0);
}
