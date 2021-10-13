#include "slide_line.h"

/**
 * slide_line - Slides and merges an array of integers
 * @line: points to an array of integers.
 * @size: number of elements.
 * @direction: left or right.
 * Return: 1 if success, 0 if failure.
 */
int slide_line(int *line, size_t size, int direction)
{
	if (((direction != SLIDE_RIGHT) && (direction != SLIDE_LEFT)) || size <= 0)
		return (0);
	if (direction == SLIDE_RIGHT)
		slide_right(line, size);
	else if (direction == SLIDE_LEFT)
		slide_left(line, size);
	else
		return (0);
	return (1);
}

/**
 * slide_right - Slides and merges an array of integers to the right
 * @line: points to an array of integers.
 * @size: number of elements.
 * Return: 1 if success, 0 if failure.
 */
void slide_right(int *line, size_t size)
{
	size_t j;
	size_t q = 0;
	int aux[32], p, i, k;

	for (j = 0; j < size; j++)
		aux[j] = 0;
	q = size - 1;
	for (p = size - 1; p >= 0; p--)
	{
		if (line[p] != 0)
			aux[q--] = line[p];
	}
	for (i = size - 1; i >= 0; i--)
	{
		if (aux[i] == aux[i - 1])
		{
			aux[i] += aux[i - 1];
			aux[i - 1] = 0;
		}
	}
	for (k = size - 1; k >= 0; k--)
		line[k] = 0;
	q = size - 1;
	for (p = size - 1; p >= 0; p--)
	{
		if (aux[p] != 0)
			line[q--] = aux[p];
	}
}

/**
 * slide_left - Slides and merges an array of integers to the left
 * @line: points to an array of integers.
 * @size: number of elements.
 * Return: 1 if success, 0 if failure.
 */
void slide_left(int *line, size_t size)
{
	size_t i, k, p;
	size_t q = 0;
	int aux[32];

	for (k = 0; k < size; k++)
		aux[k] = 0;
	for (p = 0; p < size; p++)
	{
		if (line[p] != 0)
			aux[q++] = line[p];
	}
	for (i = 0; i < size; i++)
	{
		if (aux[i] == aux[i + 1])
		{
			aux[i] += aux[i + 1];
			aux[i + 1] = 0;
		}
	}
	q = 0;
	for (k = 0; k < size; k++)
		line[k] = 0;
	for (p = 0; p < size; p++)
	{
		if (aux[p] != 0)
		{
			line[q++] = aux[p];
		}
	}
}
