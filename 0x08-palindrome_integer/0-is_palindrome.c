#include <stdio.h>
#include "palindrome.h"


/**
 * is_palindrome - checks if an unsigned int is a palindrome
 * @n: Number to be checked
 * Return: 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long num = n;
	unsigned long sum = n % 10;

	while (num /= 10)
		sum = (sum * 10) + (num % 10);

	return (n == sum);
}
