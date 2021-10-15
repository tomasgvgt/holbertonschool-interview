#include "menger.h"

/**
 * menger - Draws a 2D Menger Sponge
 * @level: Level of the Menger Sponge to draw
 */
void menger(int level)
{
	int x, y, i, j, lvl, len;
	char **arr = NULL;

	len = (int)pow(3, level);

	arr = malloc(sizeof(char *) * len);
	if (arr == NULL)
		return;

	for (i = 0; i < len; i++)
	{
		arr[i] = malloc(sizeof(char) * len);
		if (arr[i] == NULL)
		{
			for (j = 0; j < i; j++)
				free(arr[j]);
			free(arr);
		}
	}

	for (y = 0; y < len; y++)
		for (x = 0; x < len; x++)
			arr[x][y] = '#';

	for (lvl = 1; lvl <= level; lvl++)
		spaces(arr, lvl, len);

	for (y = 0; y < len; y++)
	{
		for (x = 0; x < len; x++)
			printf("%c", arr[x][y]);
		printf("\n");
	}

	for (i = 0; i < len; i++)
		free(arr[i]);
	free(arr);
}

/**
 * spaces - creates spaces
 * @arr: array
 * @len: Lenght of array
 * @lev: Level of the spaces
 */
void spaces(char **arr, int lev, int len)
{
	int x, y, xx, yy, spacelev, prevlev, currlev;

	prevlev = (int)pow(3, lev - 1);
	currlev = (int)pow(3, lev);
	spacelev = prevlev;

	for (y = prevlev; y < len; y += currlev)
	{
		for (x = prevlev; x < len; x += currlev)
		{
			for (yy = 0; yy < spacelev; yy++)
			{
				for (xx = 0; xx < spacelev; xx++)
				{
					arr[x + xx][y + yy] = ' ';
				}
			}
		}
	}
}
